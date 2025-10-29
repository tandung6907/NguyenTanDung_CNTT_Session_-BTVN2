#include<stdio.h>

int main() {
    int a, b, tempA, tempB, gcd, lcm;

    printf("Enter the first positive integer: ");
    scanf("%d", &a);
    printf("Enter the second positive integer: ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0) {
        printf("Both numbers must be positive integers.\n");
        return 0;
    }

    tempA = a;
    tempB = b;

    while (tempB != 0) {
        int temp = tempB;
        tempB = tempA % tempB;
        tempA = temp;
    }
    gcd = tempA;

    lcm = (a * b) / gcd;

    printf("The Least Common Multiple (LCM) of %d and %d is: %d\n", a, b, lcm);

    return 0;
}

