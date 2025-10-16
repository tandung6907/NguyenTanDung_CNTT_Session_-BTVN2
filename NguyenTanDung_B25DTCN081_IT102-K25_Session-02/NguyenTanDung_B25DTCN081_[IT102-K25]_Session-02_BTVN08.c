#include <stdio.h>

int main(){
	
	int number;
	int result = 0;
	printf("nhap so tuy thich: ");
	scanf("%d",&number);
	int donvi = number % 10;
	number = number / 10;
	result += donvi;
	result = result * 10;
	printf("%d \n ",result);
	// so digit 2
	int chuc = number%10;
	number = number / 10;
	result += chuc;
	result *= 10;
	printf("%d \n ",result);
	// so digit 3
	int tram = number%10;
	number = number/10;
	result += tram;
	result *= 10;
	printf("%d \n ",result);
	int nghin = number%10;
	number = number / 10;
	result += nghin;
	result *= 10;
	printf("%d \n ",result);
	int chucnghin = number%10;
	result += chucnghin;
	printf("%d \n ",result);
	printf("So dao nguoc bang: %d \n", result);
	return 0;
	
}
