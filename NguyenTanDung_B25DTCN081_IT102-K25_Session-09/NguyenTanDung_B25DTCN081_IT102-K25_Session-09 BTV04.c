#include <stdio.h>

int main() {
    int number, i;
    float sum = 0, average;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &number);
    int numbers[number];
    for(i = 0; i < number; i++) {  
        printf("Enter element %d: ", i);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = sum / number;


    printf("The average value of the elements is: %.2f\n", average);

    return 0;
}

