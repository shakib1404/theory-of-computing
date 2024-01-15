#include <stdio.h>
#include <stdbool.h>

#define NUM_STATES 8
#define NUM_SYMBOLS 2

char states[NUM_STATES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char alphabet[NUM_SYMBOLS] = {'0', '1'};
char transition[NUM_STATES][NUM_SYMBOLS] = {{'B', 'A'}, {'A', 'C'}, {'D', 'B'}, {'D', 'A'}, {'D', 'F'}, {'G', 'E'}, {'F', 'G'}, {'G', 'D'}};
int finalState = 3; // Index of the final state 'D'

char table[NUM_STATES][NUM_STATES];

void initializeTable() {
    for(int i = 0; i < NUM_STATES; i++) {
        for(int j = 0; j <= i; j++) {
            if (i == finalState || j == finalState) {
                table[i][j] = 'X';
            } else {
                table[i][j] = '-';
            }
        }
    }
}

void markEquivalentStates() {
    bool changed = true;

    while (changed) {
        changed = false;
        for (int i = 0; i < NUM_STATES; i++) {
            for (int j = 0; j <= i; j++) {
                if (table[i][j] == '-') {
                    bool equivalent = true;

                    for (int k = 0; k < NUM_SYMBOLS; k++) {
                        int nextState1 = transition[i][k] - 'A';
                        int nextState2 = transition[j][k] - 'A';

                        if (table[nextState1][nextState2] == 'X' || table[nextState2][nextState1] == 'X') {
                            equivalent = false;
                            break;
                        }
                    }

                    if (equivalent) {
                        table[i][j] = 'E';
                        table[j][i] = 'E'; // Fill corresponding entry for symmetry
                        changed = true;
                    } else {
                        table[i][j] = 'X';
                        table[j][i] = 'X'; // Fill corresponding entry for symmetry
                    }
                }
            }
        }
    }
}

void printMinimizedDFA() {
    printf("\nMinimized DFA Transition Table:\n");
    for (int i = 0; i < NUM_STATES; i++) {
        if (table[i][i] != 'X') {
            printf("%c ", states[i]);

            for (int j = 0; j < NUM_SYMBOLS; j++) {
                int nextState = transition[i][j] - 'A';
                if (table[nextState][nextState] != 'X') {
                    printf("%c ", states[nextState]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    initializeTable();
    markEquivalentStates();
    printMinimizedDFA();
    return 0;
}
