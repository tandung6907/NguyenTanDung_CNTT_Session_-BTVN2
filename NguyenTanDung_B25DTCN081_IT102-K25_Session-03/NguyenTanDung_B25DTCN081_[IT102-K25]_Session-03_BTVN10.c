#include <stdio.h>
#include <math.h>

int main(){
	
	int A, B;
	double S, d1, d2;
	
	
	printf("nhap so nguyen duong thu nhat: ");
	scanf("%d", &A);
	
	printf("nhap so nguyen duong thu hai: ");
	scanf("%d", &B);
	
	d1 = sqrt( A + sqrt(B + 1));
	d2 = sqrt( B + sqrt(pow(A, 2) + pow(B, 2)));
	
	if (A && B > 0){
		
		S = d1 + d2;
		printf("S = %.2lf", S);
	}else{
		printf("Vo ly !!!");
		
	return 0;
	
	}
}
