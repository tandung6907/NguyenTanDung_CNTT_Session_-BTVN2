#include<stdio.h>
int main() {
    int c;
    printf("Nhap 1 so nguyen bat ky: ");
    scanf("%d", &c);
    if (c % 3 == 0 && c % 5 == 0) {
        printf("%d chia het cho ca 3 va 5.\n", c);
    } 
    else if (c % 3 == 0) {
        printf("%d chia het cho 3.\n", c);
    }else if (c % 5 == 0) {
        printf("%d chia het cho 5.\n", c);
    } 
    else {
        printf("%d khong chia het cho 3 va 5.\n", c);
    }

    return 0;
}

