#include <stdio.h>
int main() {
	// khai bao va khoi tao 3 bien 
	int a,b;
	float c;
	float tong;
	int tong_nguyen;
	
	printf(" nhap gia tri thu nhat :");
	scanf("%d", &a);
	
	printf(" nhap gia tri thu hai :");
	scanf("%d", &b);
	
	printf(" nhap gia tri thu ba :");
	scanf("%f", &c);
	
	// tinh 
	
	tong = a + b + c;
	tong_nguyen = a + b + (int)c ;
	
	// in gia tri 
	
	printf("\n Vay tong 3 so (float) la: %.2f \n", tong);
	printf("Vay tong 3 so (int) la: %d \n", tong_nguyen);
	
	return 0;
}
