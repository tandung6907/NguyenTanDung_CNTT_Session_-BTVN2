#include<stdio.h>

int main() {
    int number,i;
    

    printf("Enter the number of elements in the array: ");
    scanf("%d", &number);
    
    int numbers[number];
    

    for ( i = 0; i < number; i++) {
        int temp;
        do {
            printf("Enter the %d element (odd): ", i + 1);
            scanf("%d", &temp);
            if (temp % 2 == 0) {
                printf("The value you entered is an even number. Please re-enter!!\n");
            }
        } while (temp % 2 == 0);
        
        numbers[i] = temp;
    }
    

    printf("\nThe array just entered is: ");
    for ( i = 0; i < number; i++) {
        printf("%d ", numbers[i]);
    }
    
    printf("\n");
    return 0;
}
