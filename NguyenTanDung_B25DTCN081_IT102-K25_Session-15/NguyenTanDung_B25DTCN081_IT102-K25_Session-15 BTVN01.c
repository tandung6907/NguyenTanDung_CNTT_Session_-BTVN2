#include <stdio.h>


int hieu(int a, int b) {
    return a - b;
}


int tich(int a, int b) {
    return a * b;
}

int main() {
    int x, y;
    printf("Nhap hai so nguyen: ");
    scanf("%d %d", &x, &y);

    printf("Hieu cua hai so: %d\n", hieu(x, y));
    printf("Tich cua hai so: %d\n", tich(x, y));

    return 0;
}
