#include<stdio.h>
int main() {
    int b;
    printf("Nhap 1 so nguyen bat ky: ");
    scanf("%d", &b);
    if (b % 2 == 0) {
        printf("%d la so chan.\n", b);
    } else {
        printf("%d la so le.\n", b);
    }

    return 0;
}

