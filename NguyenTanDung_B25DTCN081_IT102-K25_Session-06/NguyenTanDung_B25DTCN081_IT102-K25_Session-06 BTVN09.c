#include <stdio.h>

int main() {
    int a, b, c;
    int choice;
    int hasinput = 0; 

    do {
        printf("\n===== MENU =====\n");
        printf("1. Enter 3 integers\n");
        printf("2. Sum of 3 numbers\n");
        printf("3. Average of 3 numbers\n");
        printf("4. Smallest number\n");
        printf("5. Largest number\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter 3 integers: ");
                scanf("%d %d %d", &a, &b, &c);
                hasinput = 1;
                break;

            case 2:
                if (!hasinput) {
                    printf("Please enter 3 numbers first!\n");
                } else {
                    printf("Sum = %d\n", a + b + c);
                }
                break;

            case 3:
                if (!hasinput) {
                    printf("Please enter 3 numbers first!\n");
                } else {
                    printf("Average = %.2f\n", (a + b + c) / 3.0);
                }
                break;

            case 4:
                if (!hasinput) {
                    printf("Please enter 3 numbers first!\n");
                } else {
                    int min = a;
                    if (b < min) min = b;
                    if (c < min) min = c;
                    printf("Smallest number = %d\n", min);
                }
                break;

            case 5:
                if (!hasinput) {
                    printf("Please enter 3 numbers first!\n");
                } else {
                    int max = a;
                    if (b > max) max = b;
                    if (c > max) max = c;
                    printf("Largest number = %d\n", max);
                }
                break;

            case 6:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }

    } while (choice != 6);

    return 0;
}

