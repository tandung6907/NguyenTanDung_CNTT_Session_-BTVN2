#include <stdio.h>

int main() {
    int number, i, valuesearch, found = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &number);
    
    int numbers[number];
    for(i=0 ; i<number ; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &numbers[i]);
    }
    
    printf("Enter the value to search for (x): ");
    scanf("%d", &valuesearch);
    printf("\n");
    for(i=0 ; i<number ; i++) {
        if(numbers[i]==valuesearch) {
            printf("Value %d found at position %d.\n", valuesearch, i);
            found = 1;
        }
    }

    if(!found)
        printf("Value %d not found in the array.\n", valuesearch);

    return 0;
}


