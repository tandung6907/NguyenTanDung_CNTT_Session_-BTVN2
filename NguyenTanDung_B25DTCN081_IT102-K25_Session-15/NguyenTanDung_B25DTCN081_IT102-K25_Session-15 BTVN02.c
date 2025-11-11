#include <stdio.h>

int tinhTongChuSo(int n) {
    int tong = 0;
    
    if (n < 0) {
        n = -n;
    }

    while (n > 0) {
        tong += n % 10;
        n /= 10;        
    }

    return tong;
}

int main() {
    int n;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &n);

    printf("Tong cac chu so cua %d la: %d\n", n, tinhTongChuSo(n));

    return 0;
}
