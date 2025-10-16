#include <stdio.h>
#include <math.h>
int main(){
	
	int A;
	int B;
	int C;
	float Bieu_thuc_1;
	float Bieu_thuc_2;
	float Bieu_thuc_3;
	float S;
	//nhap 3 so A, B, C 
	
	printf("Nhap so A:");
	scanf("%d",&A);
	
	printf("Nhap so B:");
	scanf("%d",&B);
	
	printf("Nhap so C:");
	scanf("%d",&C);
	
	// tinh bieu thuc 1 + 2 +3
	
	Bieu_thuc_1 = (pow(A,2) + sqrt(pow(B,2) + (4*A*C)))/(2*A);
	Bieu_thuc_2 = (pow(B,3) / pow(C,2));
	Bieu_thuc_3 = sqrt(fabs(A -B));
	
	// tinh tong S
	
	S = Bieu_thuc_1 - Bieu_thuc_2 + Bieu_thuc_3;
	
	printf("Vay bieu thuc S co gia tri la %.2f \n", S);
	
	return 0;
}
