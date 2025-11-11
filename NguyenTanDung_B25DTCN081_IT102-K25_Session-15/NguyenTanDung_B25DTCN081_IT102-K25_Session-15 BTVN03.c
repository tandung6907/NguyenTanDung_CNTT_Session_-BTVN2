#include <stdio.h>

int daoNguocSo(int n) {
    int soDaoNguoc = 0;
    int dau = 1;


    if (n < 0) {
        dau = -1;
        n = -n;
    }

    while (n > 0) {
        soDaoNguoc = soDaoNguoc * 10 + n % 10;
        n /= 10;
    }

    return soDaoNguoc * dau; 
}

int main() {
    int n;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);

    printf("So dao nguoc cua %d la: %d\n", n, daoNguocSo(n));

    return 0;
}
