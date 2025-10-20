#include <stdio.h>

int main(){
	float a;
	float h;
	
	printf(" nhap canh day cua tam giac:\n");
	scanf("%f",&a);
	
	printf(" nhap chieu cao cua tam giac:\n");
	scanf("%f",&h);
	
	float S = (1.0/2)* a * h;
	
	printf("dien tich cua tam giac la: %.2f", S);
	
	return 0; 
	
}
