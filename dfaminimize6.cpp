#include <stdio.h>
#include <stdbool.h>

#define STATES 8
#define SYMBOLS 2

char states[STATES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char symbols[SYMBOLS] = {'0', '1'};
char transition_table[STATES][SYMBOLS];
int distinguishability_table[STATES][STATES];

void initializeTransitionTable() {
    char transitions[STATES][SYMBOLS] = {
        {'B', 'A'},
        {'A', 'C'},
        {'D', 'B'},
        {'D', 'D'},
        {'D', 'F'},
        {'G', 'E'},
        {'F', 'G'},
        {'G', 'G'}
    };

    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < SYMBOLS; j++) {
            transition_table[i][j] = transitions[i][j];
        }
    }
}

void initializeDistinguishabilityTable() {
    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < STATES; j++) {
            distinguishability_table[i][j] = 0;
        }
    }
}

void markIndistinguishable(int state1, int state2) {
    distinguishability_table[state1][state2] = 1;
    distinguishability_table[state2][state1] = 1;
}

bool isDistinguishable(int state1, int state2) {
    for (int k = 0; k < SYMBOLS; k++) {
        int nextState1 = -1;
        int nextState2 = -1;

        for (int i = 0; i < STATES; i++) {
            if (states[i] == transition_table[state1][k]) {
                nextState1 = i;
            }
            if (states[i] == transition_table[state2][k]) {
                nextState2 = i;
            }
        }

        if (nextState1 != nextState2 &&
            (distinguishability_table[nextState1][nextState2] == 1 || distinguishability_table[nextState2][nextState1] == 1)) {
            return true;
        }
    }

    return false;
}

void tableFillingAlgorithm() {
    for (int i = 0; i < STATES; i++) {
        for (int j = i + 1; j < STATES; j++) {
            if ((distinguishability_table[i][j] == 0) && (isDistinguishable(i, j))) {
                markIndistinguishable(i, j);
            }
        }
    }
}

int main() {
    initializeTransitionTable();
    initializeDistinguishabilityTable();
    tableFillingAlgorithm();

    printf("Distinguishability Table:\n");
    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < STATES; j++) {
            printf("%d ", distinguishability_table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
