#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digit(const char *s) {
    while (*s) {
        if (*s < '0' || *s > '9') {
            return 0;
        }
        s++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2])) {
        printf("Error\n");
        return 1;
    }

    const char *num1 = argv[1];
    const char *num2 = argv[2];
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;

    int *result = (int *)calloc(len, sizeof(int));
    if (!result) {
        printf("Error\n");
        return 1;
    }

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int digit1 = num1[i] - '0';

        for (int j = len2 - 1; j >= 0; j--) {
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2 + result[i + j + 1] + carry;
            carry = product / 10;
            result[i + j + 1] = product % 10;
        }

        result[i] += carry;
    }

    int printed = 0;
    for (int i = 0; i < len; i++) {
        if (result[i] != 0 || printed) {
            printf("%d", result[i]);
            printed = 1;
        }
    }

    if (!printed) {
        printf("0");
    }

    printf("\n");
    free(result);
    return 0;
}
