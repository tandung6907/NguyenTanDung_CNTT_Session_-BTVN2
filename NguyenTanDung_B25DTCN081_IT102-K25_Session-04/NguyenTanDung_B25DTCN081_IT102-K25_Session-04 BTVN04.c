#include<stdio.h>
int main() {
    int month, year;
    printf("Nhap thang (1-12): ");
    scanf("%d", &month);
    printf("Nhap nam: ");
    scanf("%d", &year);
    if (month < 1 || month > 12) {
        printf("Thang khong hop le.\n");
    } 
    else {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                printf("Thang %d co 31 ngay.\n", month);
                break;
            case 4: case 6: case 9: case 11:
                printf("Thang %d co 30 ngay.\n", month);
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    printf("Thang 2 co 29 ngay (nam nhuan).\n");
                } else {
                    printf("Thang 2 co 28 ngay (nam khong nhuan).\n");
                }
                break;
        }
    }

    return 0;
}

