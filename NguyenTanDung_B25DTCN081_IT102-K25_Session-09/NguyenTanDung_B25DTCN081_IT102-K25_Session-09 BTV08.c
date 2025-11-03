#include <stdio.h>
#include <math.h>

int isPrime(int num) {
	int i;
    if (num < 2)
        return 0;
    for (i=2 ; i<=sqrt(num) ; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int num, i;
    int sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);
    int numbers[num]; 

    for (i=0 ; i<num ; i++) {
        printf("Enter element %d: ",i);
        scanf("%d", &numbers[i]);
    }

    for (i=0 ; i<num ; i++) {
        if (isPrime(numbers[i])) {
            sum += numbers[i];
        }
    }
    printf("\nThe sum of all prime numbers in the array is: %d\n", sum);

    return 0;
}

