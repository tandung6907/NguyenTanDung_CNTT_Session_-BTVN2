# include <stdio.h>
#include <math.h>
int main (){

int A;
int B;
int C;
float Bieu_thuc_1;
float Bieu_thuc_2; 
printf("nhap so thu nhat:");
scanf("%d",&A);
printf("nhap so thu hai:");
scanf("%d",&B);
printf("nhap so thu ba:");
scanf("%d",&C);
Bieu_thuc_1 = pow(A,2) + pow(B,2) + (2*C);
Bieu_thuc_2 = sqrt(A+B-C);
double S = Bieu_thuc_1 + Bieu_thuc_2;
printf(" Bieu thuc co gia tri la: %f", S);
return 0;
}
