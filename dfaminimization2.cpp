#include <stdio.h>

#define STATES 8
#define ALPHABET 2

char states[STATES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char alphabet[ALPHABET] = {'0', '1'};

int transition[STATES][ALPHABET] = {
    {1, 2},  // A
    {0, 2},  // B
    {3, 1},  // C
    {3, 0},  // D
    {3, 5},  // E
    {6, 4},  // F
    {5, 7},  // G
    {3, 6}   // H
};

int distinguishabilities[STATES][STATES];

void initializeDistinguishabilities() {
    for(int i = 0; i < STATES; i++) {
        for(int j = 0; j < STATES; j++) {
            distinguishabilities[i][j] = 0;
        }
    }
}

void fillDistinguishabilities() {
    for(int i = 0; i < STATES; i++) {
        for(int j = 0; j < i; j++) {
            if((i < 4 && j >= 4) || (i >= 4 && j < 4)) {
                distinguishabilities[i][j] = 1;
            }
        }
    }

    int changes = 1;
    while(changes) {
        changes = 0;
        for(int i = 0; i < STATES; i++) {
            for(int j = 0; j < STATES; j++) {
                if(i != j && !distinguishabilities[i][j]) {
                    for(int k = 0; k < ALPHABET; k++) {
                        int nextStateI = transition[i][k];
                        int nextStateJ = transition[j][k];
                        if(distinguishabilities[nextStateI][nextStateJ]) {
                            distinguishabilities[i][j] = 1;
                            changes = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void printDistinguishabilitiesTable() {
    printf("Table of Distinguishabilities:\n");
    printf("   ");
    for(int i = 0; i < STATES; i++) {
        printf("%c ", states[i]);
    }
    printf("\n");
    for(int i = 0; i < STATES; i++) {
        printf("%c: ", states[i]);
        for(int j = 0; j < STATES; j++) {
            printf("%d ", distinguishabilities[i][j]);
        }
        printf("\n");
    }
}

void constructMinStateDFA() {
    char minStates[STATES];
    int minStatesCount = 0;
    for(int i = 0; i < STATES; i++) {
        if(states[i] < 'E') {
            minStates[minStatesCount++] = states[i];
        }
    }

    printf("\nMinimum-state Equivalent DFA:\n");
    printf("States: ");
    for(int i = 0; i < minStatesCount; i++) {
        printf("%c ", minStates[i]);
    }
    printf("\n");

    for(int i = 0; i < minStatesCount; i++) {
        printf("Transitions from %c: ", minStates[i]);
        for(int j = 0; j < ALPHABET; j++) {
            int nextState = transition[i][j];
            if(nextState < minStatesCount) {
                printf("(%c -> %c) ", minStates[i], minStates[nextState]);
            }
        }
        printf("\n");
    }
}

int main() {
    initializeDistinguishabilities();
    fillDistinguishabilities();
    printDistinguishabilitiesTable();
    constructMinStateDFA();
    return 0;
}

