#include <stdio.h>
#include <string.h>

// Function to check if a string is in L1: {0^n 1^n | n >= 1}
int is_in_L1(char* str) {
    int n = strlen(str) / 2;  // Since the string is of the form 0^n 1^n
    for (int i = 0; i < n; i++) {
        if (str[i] != '0' || str[i + n] != '1') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is in L2: {0^n 1^2n | n >= 1}
int is_in_L2(char* str) {
    int n = strlen(str) / 3;  // Since the string is of the form 0^n 1^2n
    for (int i = 0; i < n; i++) {
        if (str[i] != '0' || str[i + 2 * n] != '1' || str[i + n] != '1') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter the string in the format 0^n 1^n or 0^n 1^2n (e.g., 0011): ");
    scanf("%s", str);

    if (is_in_L1(str)) {
        printf("The string is in L1.\n");
    } else if (is_in_L2(str)) {
        printf("The string is in L2.\n");
    } else {
        printf("The string is not in L1 or L2.\n");
    }

    return 0;
}

