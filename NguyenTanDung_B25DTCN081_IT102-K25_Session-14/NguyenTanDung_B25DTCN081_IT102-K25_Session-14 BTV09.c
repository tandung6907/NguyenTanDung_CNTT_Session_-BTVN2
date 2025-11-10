#include <stdio.h>

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; 
}

int main() {
    int x, y;

    printf("Nhap so thu nhat: ");
    scanf("%d", &x);
    printf("Nhap so thu hai: ");
    scanf("%d", &y);

    printf("Uoc chung lon nhat cua %d va %d la: %d\n", x, y, UCLN(x, y));

    return 0;
}

