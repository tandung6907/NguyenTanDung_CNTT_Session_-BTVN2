#include<stdio.h>

int main() {
    int a, b;

    printf("Enter the first positive integer: ");
    scanf("%d", &a);
    printf("Enter the second positive integer: ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0) {
        printf("Both numbers must be positive integers.\n");
        return 0;
    }

    int tempA = a, tempB = b;

    while (tempA != tempB) {
        if (tempA > tempB)
            tempA -= tempB;
        else
            tempB -= tempA;
    }

    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", a, b, tempA);

    return 0;
}

