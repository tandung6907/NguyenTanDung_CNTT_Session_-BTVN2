#include<stdio.h>
int main() {
    int a, b, c;
    printf("Nhap canh thu nhat: ");
    scanf("%d", &a);
    printf("Nhap canh thu hai: ");
    scanf("%d", &b);
    printf("Nhap canh thu ba: ");
    scanf("%d", &c);
    if (a > 0 && b > 0 && c > 0 && 
        a + b > c && a + c > b && b + c > a) {
        printf("La 3 canh tam giac.\n");
    } else {
        printf("Khong phai 3 canh tam giac.\n");
    }

    return 0;
}

