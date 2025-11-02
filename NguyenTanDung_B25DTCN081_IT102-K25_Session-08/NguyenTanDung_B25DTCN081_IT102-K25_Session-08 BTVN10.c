#include<stdio.h>
#include<math.h>

int isPrime(int n) {
	int i;
    if (n < 2)
        return 0;
    for ( i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0; 
    }
    return 1;
}

int main() {
    int number,i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &number);

    int numbers[number];

    for ( i = 0; i < number; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Prime numbers in the array are: ");
    int found = 0;
    for ( i = 0; i < number; i++) {
        if (isPrime(numbers[i])) {
            printf("%d ", numbers[i]);
            found = 1;
        }
    }

    if (!found)
        printf("There are no prime numbers in the array.");

    return 0;
}

