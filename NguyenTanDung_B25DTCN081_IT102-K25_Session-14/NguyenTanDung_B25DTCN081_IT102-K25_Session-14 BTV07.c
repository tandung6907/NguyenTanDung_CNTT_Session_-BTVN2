#include <stdio.h>
#include <stdbool.h>


bool laSoNguyenTo(int n) {
	int i;
    if (n<2) return false;
    for (i=2 ; i*i<=n ; i++) {
        if (n%i==0)
            return false;
    }
    return true;
}

int main() {
    int n,i;
    printf("Nhap mot so nguyen n: ");
    scanf("%d", &n);

    printf("Cac so nguyen to tu 1 den %d la:\n", n);
    for (i=2 ; i<=n ; i++) {
        if (laSoNguyenTo(i))
            printf("%d\t", i);
    }
    printf("\n");

    return 0;
}

