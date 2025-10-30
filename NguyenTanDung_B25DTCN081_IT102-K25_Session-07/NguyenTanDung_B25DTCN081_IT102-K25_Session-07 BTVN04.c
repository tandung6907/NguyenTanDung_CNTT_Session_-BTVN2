#include<stdio.h>

int main() {
    int row, column, i, j;

    // Input the number of rows and columns
    printf("Enter the number of rows (m): ");
    scanf("%d", &row);

    printf("Enter the number of columns (n): ");
    scanf("%d", &column);

    // Print the rectangle
    for ( i = 0; i < row; i++) {
        for ( j = 0; j < column; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

