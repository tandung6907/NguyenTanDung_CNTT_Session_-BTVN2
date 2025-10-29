#include<stdio.h>

int main() {
    int N, sum = 0,i;

    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N must be a positive number.\n");
    } else {
        for ( i = 1; i <= N; i++) {
            sum += i;
        }
        printf("The sum of numbers from 1 to %d is: %d\n", N, sum);
    }

    return 0;
}

