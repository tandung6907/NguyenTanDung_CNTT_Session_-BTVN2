#include <stdio.h>
#include <stdbool.h>

bool laSoHoanHao(int n) {
    int tong = 0;
    int i;
    for (i=1; i<=n/2 ; i++) {
        if (n%i==0)
            tong += i;
    }

    return (tong==n && n>0);
}

int main() {
    int n, i;
    printf("Nhap mot so nguyen n: ");
    scanf("%d", &n);

    printf("Cac so hoan hao tu 1 den %d la:\n", n);
    for (i=1 ; i<=n; i++) {
        if (laSoHoanHao(i))
            printf("%d\t", i);
    }
    printf("\n");

    return 0;
}

