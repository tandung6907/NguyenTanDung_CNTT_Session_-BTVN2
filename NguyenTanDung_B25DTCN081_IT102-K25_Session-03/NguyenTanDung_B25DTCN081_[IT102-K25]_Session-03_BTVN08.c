#include <stdio.h>

int main() {
    int num;
    int d1, d2, d3, d4, reverse;

    printf("Nhap vao mot so nguyen co 4 chu so: ");
    scanf("%d", &num);

   
    d1 = num / 1000;             
    d2 = (num / 100) % 10;      
    d3 = (num / 10) % 10;        
    d4 = num % 10;               

  
    reverse = d4 * 1000 + d3 * 100 + d2 * 10 + d1;

    printf("So nghich dao cua %d la: %d\n", num, reverse);

    return 0;
}

