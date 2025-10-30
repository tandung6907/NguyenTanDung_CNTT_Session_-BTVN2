#include <stdio.h>

int main() {
    int n, original, reversed = 0, remainder;

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    original = n;

    // Reverse the number
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    // Check if palindrome
    if (original == reversed)
        printf("%d is a palindrome number.\n", original);
    else
        printf("%d is not a palindrome number.\n", original);

    return 0;
}

