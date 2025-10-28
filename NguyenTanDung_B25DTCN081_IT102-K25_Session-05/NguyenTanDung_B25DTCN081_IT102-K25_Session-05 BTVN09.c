#include<stdio.h>

int main() {
    float salarycoefficient, salary, allowance, reward;
    int workday, position;
    const float ONE_DAYS_SALARY = 160000, REWARD_SALARY = 200000;

   
    printf("Enter the salary coefficient: ");
    scanf("%f", &salarycoefficient);
    printf("Enter the number of working days per month: ");
    scanf("%d", &workday);
    printf("Enter the position (1: Employee, 2: Leader, 3: Manager)): ");
    scanf("%d", &position);

    
    switch (position) {
        case 1:
            allowance = 500000;
            break;
        case 2:
            allowance = 1000000;
            break;
        case 3:
            allowance = 2000000;
            break;
        default:
            printf("Error: Invalid position!\n");
            return 0;
    }

    
    if (workday > 26) {
        reward = (workday - 26) * REWARD_SALARY;
    }

    
    salary = workday * ONE_DAYS_SALARY * salarycoefficient + allowance + reward;

   
    printf("\n--- Salary spreadsheet ---\n");
    printf("Salarycoefficient: %.2f\n", salarycoefficient);
    printf("Workday: %d\n", workday);
    printf("Position: %s\n", (position == 1) ? "Employee" :
                                 (position == 2) ? "Leader" : "Manager");
    printf("Allowance: %.0f VND\n", allowance);
    printf("Reward: %.0f VND\n", reward);
    printf("Salary: %.0f VND\n", salary);

    return 0;
}

