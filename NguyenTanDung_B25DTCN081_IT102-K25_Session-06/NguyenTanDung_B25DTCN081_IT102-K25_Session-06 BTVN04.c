#include<stdio.h>

int main() {
    int n,i;

    do {
        printf("Enter a positive integer 1 to 10: ");
        scanf("%d", &n);

        if (n < 1 || n > 10) {
            printf("Invalid input! Please enter a number between 1 and 10.\n");
        }

    } while (n < 1 || n > 10);

    printf("Multiplication table for %d:\n", n);
    for ( i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}

