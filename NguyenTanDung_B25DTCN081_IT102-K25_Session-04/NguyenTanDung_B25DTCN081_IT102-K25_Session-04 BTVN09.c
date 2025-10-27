#include<stdio.h>
int main() {
    int day, month, year;
    int maxDay;
    printf("Nhap ngay: ");
    scanf("%d", &day);
    printf("Nhap thang: ");
    scanf("%d", &month);
    printf("Nhap nam: ");
    scanf("%d", &year);
    if (month < 1 || month > 12) {
        printf("Ngay thang nam khong hop le.\n");
        return 0;
    }
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                maxDay = 29;
            else
                maxDay = 28;
            break;
        default:
            maxDay = 0; 
    }
    if (day >= 1 && day <= maxDay)
        printf("Ngay thang nam hop le.\n");
    else
        printf("Ngay thang nam khong hop le.\n");

    return 0;
}

