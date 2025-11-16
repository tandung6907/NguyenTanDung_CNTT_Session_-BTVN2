#include <stdio.h>

void swap(int *ptr1, int *ptr2) {

    int temp;

    temp = *ptr1; 

    *ptr1 = *ptr2;

    *ptr2 = temp;
}

int main() {
	
    int a = 5;
    int b = 10;

    printf("Chuong trinh Hoan doi gia tri su dung Con Tro (Truyen tham chieu) \n");
    printf("--- \n");

    printf("1. Gia tri ban dau:\n");
    printf("   Bien a = %d\n", a);
    printf("   Bien b = %d\n", b);

    printf("--- \n");

    printf("2. Goi ham swap(&a, &b) de hoan doi...\n");
    swap(&a, &b);

    printf("--- \n");

    printf("3. Gia tri sau khi hoan doi:\n");
    printf("   Bien a = %d\n", a);
    printf("   Bien b = %d\n", b);

    if (a == 10 && b == 5) {
        printf("\n Hoan doi thanh cong!\n");
    } else {
        printf("\n Hoan doi that bai.\n");
    }

    return 0;
}
