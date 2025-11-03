#include <stdio.h>

int main() {
    int number, i, j, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &number);
    
    int numbers[number];
    for(i=0; i<number ; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &numbers[i]);
    }
    
    i = 0;
    j = number - 1;
    while(i < j) {
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
        i++;
        j--;
    }

    printf("\nReversed array:\n");
    for(i=0 ; i<number ; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
    return 0;
}

