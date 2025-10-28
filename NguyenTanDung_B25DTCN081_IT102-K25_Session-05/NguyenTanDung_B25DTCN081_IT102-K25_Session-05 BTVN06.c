#include<stdio.h>

int main() {
    float a, b, result;
    char math;

    printf("Enter the first number (a): ");
    scanf("%f", &a);
    printf("Enter the second number (b): ");
    scanf("%f", &b);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &math);

    switch (math) {
        case '+':
            result = a + b;
            printf("Result: %.2f + %.2f = %.2f\n", a, b, result);
            break;
        case '-':
            result = a - b;
            printf("Result: %.2f - %.2f = %.2f\n", a, b, result);
            break;
        case '*':
            result = a * b;
            printf("Result: %.2f * %.2f = %.2f\n", a, b, result);
            break;
        case '/':
            if (b == 0) {
                printf("Error: Cannot divide by 0\n");
            } else {
                result = a / b;
                printf("Result: %.2f / %.2f = %.2f\n", a, b, result);
            }
            break;
        default:
            printf("Invalid operator error\n");
    }

    return 0;
}

