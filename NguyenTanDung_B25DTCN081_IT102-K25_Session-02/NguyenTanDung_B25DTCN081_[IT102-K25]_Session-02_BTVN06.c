#include <stdio.h>

int main(){
int a,b,c,d;
int A;

 printf("nhap so thu nhat:");
 scanf("%d", &a);
 
 printf("nhap so thu hai: ");
 scanf("%d", &b);
 
 printf("nhap so thu ba: ");
 scanf("%d", &c);

printf("nhap so thu tu: ");
 scanf("%d", &d);
 
 // tinh gia tri cua bieu thuc
 
 A = a*b - 2*c + 3*(a- d);
printf("gia tri cua bieu thuc la: %d \n", A);
    return 0;
}
