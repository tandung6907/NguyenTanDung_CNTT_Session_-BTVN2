#include <stdio.h>

void calculate_sum(const int *num1_ptr, const int *num2_ptr, int *result_ptr) {
    *result_ptr = *num1_ptr + *num2_ptr;
}

int main() {
   
    int number1,number2;
    printf("Vui long nhap so thu nhat: ");
    scanf("%d",&number1);
    printf("Vui long nhap so thu hai: ");
    scanf("%d",&number2);
    int sum_result = 0;

    printf("Chuong trinh tinh tong voi con tro: \n");
    printf("--- \n");

    printf("1. Gia tri ban dau:\n");
    printf("   So thu nhat: %d\n", number1);
    printf("   So thu hai: %d\n", number2);
    printf("   Tong hai so: %d\n", sum_result);
    printf("--- \n");

    printf("2. Goi ham calculate_sum(&number1, &number2, &sum_result)...\n");
    calculate_sum(&number1, &number2, &sum_result);
    printf("--- \n");

    printf("3. Ket qua sau khi goi ham:\n");
    printf("   Tong cua %d va %d la: %d\n", number1, number2, sum_result);

	return 0;
}
