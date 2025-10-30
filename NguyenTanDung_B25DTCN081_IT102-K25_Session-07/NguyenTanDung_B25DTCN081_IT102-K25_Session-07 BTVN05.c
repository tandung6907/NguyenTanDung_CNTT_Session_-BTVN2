#include<stdio.h>
#include<math.h>

int main() {
    int n, original, remainder, digits = 0;
    double result = 0.0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    original = n;

    // Count number of digits
    while (original != 0) {
        original /= 10;
        ++digits;
    }

    original = n;

    // Calculate sum of powers of digits
    while (original != 0) {
        remainder = original % 10;
        result += pow(remainder, digits);
        original /= 10;
    }

    // Check if n is Armstrong
    if ((int)result == n)
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is not an Armstrong number.\n", n);

    return 0;
}

