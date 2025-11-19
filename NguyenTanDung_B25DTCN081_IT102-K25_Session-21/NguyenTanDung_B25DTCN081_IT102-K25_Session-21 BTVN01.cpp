#include<stdio.h>

struct Car {
	
	char model[50];
	int year;
	long long price;
	
};

int main () {
	
	struct Car myCar = {"Lamborghini Aventador SVJ (LP770-4)",2025,517700};
	
	printf("Ten Xe: %s || Nam San Xuat: %d || Gia Ban: %lld USD", myCar.model, myCar.year, myCar.price);
	
	return 0;
}
