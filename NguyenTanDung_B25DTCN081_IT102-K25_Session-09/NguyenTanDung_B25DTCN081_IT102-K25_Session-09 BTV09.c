#include <stdio.h>

int main() {
    
    int num,j,i;
    int maxCount = 0, mostFrequent, count;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int numbers[num];
    for (i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    
    for (i=0 ; i<num ; i++) {
        count = 0;
        for (j=0; j<num ; j++) {
            if (numbers[i] == numbers[j])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = numbers[i];
        }
    }
    printf("The element that appears most frequently is: %d\n", mostFrequent);
    printf("It appears %d times.\n", maxCount);

    return 0;
}

