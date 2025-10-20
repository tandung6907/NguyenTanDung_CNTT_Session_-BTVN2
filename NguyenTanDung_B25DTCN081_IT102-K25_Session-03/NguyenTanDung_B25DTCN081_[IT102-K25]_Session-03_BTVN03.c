#include <stdio.h>
#include <math.h>
int main(){
	 
	 float R;
	 const float PI = 3.14;
	 float C;
	 float S;
	
	
	printf(" nhap ban kinh :");
	scanf("%f", &R);
	
	C = 2 * PI * R;
	S = PI * pow(R,2);
	
	printf("Chu vi hinh tron la: %.2f \n ",C);
	printf("Dien tich hinh tron la: %.2f \n ",S);
	
	return 0; 
}
