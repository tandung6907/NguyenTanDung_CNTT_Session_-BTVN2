#include <stdio.h>

int main(){
	
	int n;
	float A, d1, d2, d3;
	
	
	printf(" Nhap so n: \n ");
	scanf("%d", &n); 
	
	d1 =  1.0 / ((n - 1 )*n);
	d2 =  1.0 / ((n + 1 )*n);
	d3 =  1.0 / ((n + 1 )*(n + 2));
	if (n > 0){
		A = d1 + d2 + d3;
		printf("bieu thuc co gia tri la: %.5f", A);
	}else{
		printf("xin vui long nhap lai so n !");
		
		
	return 0; 
	}	
}
