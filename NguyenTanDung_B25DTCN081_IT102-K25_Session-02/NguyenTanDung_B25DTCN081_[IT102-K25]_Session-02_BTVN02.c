#include <stdio.h>

int main(){
	int a, b; // khai bao 2 bien
	int tong; // khai bao bien tong
	
	// nhap 2 so a va b
	printf("nhap so thu nhat: ");
	scanf("%d", &a);
	
	printf("nhap so thu hai: ");
	scanf("%d", &b);
	
	// tinh tong
	
	tong = a + b; 
	
	// hien thi dap an
	
	printf(" vay tong cua %d va %d la: %d \n", a, b, tong);
	
	return 0;
	
}
