#include<stdio.h>

int main() {
    float income, taxrate, taxamount;

    
    printf("Enter your monthly income (in million VND): ");
    scanf("%f", &income);

   
    if (income < 0) {
        printf("Error: Invalid income amount!\n");
        return 0;
    }

   
    if (income <= 5) {
        taxrate = 5;
    } else if (income <= 10) {
        taxrate = 10;
    } else {
        taxrate = 15;
    }

    
    taxamount = income * (taxrate / 100);


    printf("\n--- Income Tax Calculation ---\n");
    printf("Monthly income: %.2f million VND\n", income);
    printf("Tax rate: %.0f%%\n", taxrate);
    printf("Tax amount: %.2f million VND\n", taxamount);

    return 0;
}

