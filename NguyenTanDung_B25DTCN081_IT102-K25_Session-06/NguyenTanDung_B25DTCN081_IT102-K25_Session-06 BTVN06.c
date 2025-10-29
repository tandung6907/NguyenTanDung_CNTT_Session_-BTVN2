#include<stdio.h>

int main() {
    double num1, num2;
    int choice;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Sum of two numbers\n");
        printf("2. Difference of two numbers\n");
        printf("3. Product of two numbers\n");
        printf("4. Quotient of two numbers\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Sum = %.2lf\n", num1 + num2);
                break;
            case 2:
                printf("Difference = %.2lf\n", num1 - num2);
                break;
            case 3:
                printf("Product = %.2lf\n", num1 * num2);
                break;
            case 4:
                if (num2 != 0)
                    printf("Quotient = %.2lf\n", num1 / num2);
                else
                    printf("Error: Division by zero is not allowed.\n");
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}

