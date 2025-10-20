#include <stdio.h>

int main() {
    int num;
    int d1, d2, d3, d4, sum;

    printf("Nhap vao mot so nguyen co 4 chu so: ");
    scanf("%d", &num);

    d1 = num / 1000;            
    d2 = (num / 100) % 10;       
    d3 = (num / 10) % 10;        
    d4 = num % 10;               

    sum = d1 + d2 + d3 + d4;

    printf("Tong cac chu so cua %d la: %d\n", num, sum);

    return 0;
}

