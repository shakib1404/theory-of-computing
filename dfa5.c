#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABET 2

int main() {
    int numofstates, numofalphabet;
    char alphabet[MAX_ALPHABET];
    int transition[MAX_STATES][MAX_ALPHABET];
    bool final_states[MAX_STATES] = {false};

    printf("Enter the number of states (max %d): ", MAX_STATES);
    scanf("%d", &numofstates);

    printf("Enter the number of alphabets (max %d): ", MAX_ALPHABET);
    scanf("%d", &numofalphabet);

    printf("Enter the alphabet symbols (e.g., 'a', 'b'): ");
    for (int i = 0; i < numofalphabet; ++i) {
        scanf(" %c", &alphabet[i]);
    }

    printf("Enter the transitions (state next_state) for each alphabet:\n");
    for (int i = 0; i < numofstates; ++i) {
        for (int j = 0; j < numofalphabet; ++j) {
            int next_state;
            printf("Transition from state %d with '%c': ", i, alphabet[j]);
            scanf("%d", &next_state);
            transition[i][j] = next_state;
        }
    }

    int num_final_states;
    printf("Enter the number of final states: ");
    scanf("%d", &num_final_states);

    printf("Enter the final states: ");
    for (int i = 0; i < num_final_states; ++i) {
        int final_state;
        scanf("%d", &final_state);
        final_states[final_state] = true;
    }

    int current_state = 0;
    char inputstr[100];
    printf("Enter the input string: ");
    scanf("%s", inputstr);

    for (int i = 0; i < strlen(inputstr); ++i) {
        int symbol_index = -1;
        for (int j = 0; j < numofalphabet; ++j) {
            if (inputstr[i] == alphabet[j]) {
                symbol_index = j;
                break;
            }
        }

        if (symbol_index == -1) {
            printf("Invalid symbol '%c' in the input string.\n", inputstr[i]);
            return 1;
        }

        current_state = transition[current_state][symbol_index];
    }

    if (final_states[current_state]) {
        printf("Input string accepted!\n");
    } else {
        printf("Input string rejected.\n");
    }

    return 0;
}

