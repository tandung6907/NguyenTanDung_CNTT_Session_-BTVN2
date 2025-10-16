#include <stdio.h >
#include <math.h>
int main (){

int A;
int B;
int C;
float Bieu_thuc_1;
float Bieu_thuc_2; 
float Bieu_thuc_3;
printf("nhap so thu nhat:");
scanf("%d",&A);
printf("nhap so thu hai:");
scanf("%d",&B);
printf("nhap so thu ba:");
scanf("%d",&C);

Bieu_thuc_1 = (sqrt(pow(A,2)+pow(B,2)))/(C +1);
Bieu_thuc_2 = (A*B)/C;
Bieu_thuc_3 = sqrt(abs(A -B) + pow(C,2));

float S = Bieu_thuc_1 + Bieu_thuc_2 - Bieu_thuc_3;
printf(" Bieu thuc nay co gia tri la: %.2f", S);

return 0; 
}
