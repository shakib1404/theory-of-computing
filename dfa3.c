#include <stdio.h>

int main() {
    int numStates, numFinalStates, numTransitions;

    printf("Enter the number of states: ");
    scanf("%d", &numStates);



    printf("Enter the number of final states: ");
    scanf("%d", &numFinalStates);

    int finalStates[numFinalStates];

    printf("Enter final states: ");
    for (int i = 0; i < numFinalStates; i++) {
        scanf("%d", &finalStates[i]);
    }

    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);

    int dfa[numStates][2]; // 2 for 0 and 1 inputs

    printf("Define transitions as \"initial state input final state\":\n");
    for (int i = 0; i < numTransitions; i++) {
        int initialState, input, finalState;
        scanf("%d%d%d", &initialState, &input, &finalState);
        dfa[initialState][input] = finalState;
    }

    int initialState;
    printf("Enter the initial state: ");
    scanf("%d", &initialState);

    char str[100];

    printf("Enter a string (containing 0's and 1's only): ");
    scanf("%s", str);

    int currentState = initialState;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            printf("Invalid input character: %c\n", str[i]);
            return 1;
        }

        int input = str[i] - '0';
        currentState = dfa[currentState][input];
    }

    int isFinalState = 0;
    for (int i = 0; i < numFinalStates; i++) {
        if (currentState == finalStates[i]) {
            isFinalState = 1;
            break;
        }
    }

    if (isFinalState) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("String is rejected by the DFA.\n");
    }

    return 0;
}

