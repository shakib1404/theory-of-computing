
#include <stdio.h>

// DFA transition table
int dfa[4][2] = {
    {1, 2}, // q0: input 0 goes to q1, input 1 goes to q2
    {0, 3}, // q1: input 0 goes to q0, input 1 goes to q3
    {3, 0}, // q2: input 0 goes to q3, input 1 goes to q0
    {2, 1}  // q3: input 0 goes to q2, input 1 goes to q1
};

// DFA initial state and set of final states
int initialState = 0;
int finalStates[] = {0};

// Function to check if the input string is accepted by the DFA
int isAccepted(char *str) {
    int currentState = initialState;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            printf("Invalid input character: %c\n", str[i]);
            return 0;
        }

        int input = str[i] - '0'; // Convert character '0' or '1' to 0 or 1

        currentState = dfa[currentState][input];
    }

    for (int i = 0; i < sizeof(finalStates) / sizeof(finalStates[0]); i++) {
        if (currentState == finalStates[i]) {
            return 1; // String is accepted
        }
    }

    return 0; // String is rejected
}

int main() {
    char str[100];

    printf("Enter a string (containing 0's and 1's only): ");
    scanf("%s", str);

    if (isAccepted(str)) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("String is rejected by the DFA.\n");
    }

    return 0;
}
