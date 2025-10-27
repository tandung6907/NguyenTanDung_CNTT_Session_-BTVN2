#include<stdio.h>
int main() {
    int a, b, c;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    printf("Nhap so thu ba: ");
    scanf("%d", &c);
    if ((c > a && c < b) || (c > b && c < a)) {
        printf("So thu 3 nam trong khoang giua so 1 va so 2.\n");
    } else {
        printf("So thu 3 khong nam trong khoang giua so 1 va so 2.\n");
    }

    return 0;
}

