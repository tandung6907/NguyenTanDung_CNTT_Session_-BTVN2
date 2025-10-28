#include<stdio.h>

int main() {
    int age;
    const int COST_BUS = 20000;
    float price;

    printf("Enter passenger age: ");
    scanf("%d", &age);

    if (age < 0 || age > 120) {
        printf("Error: Invalid age!\n");
    } else {
        if (age < 6) {
            price = COST_BUS * 0.0;
        } else if (age <= 18) {
            price = COST_BUS * 0.5;
        } else if (age <= 60) {
            price = COST_BUS * 1.0;
        } else {
            price = COST_BUS * 0.7;
        }

        printf("Ticket price must be paid: %.0f VND\n", price);
    }


    return 0;
}

