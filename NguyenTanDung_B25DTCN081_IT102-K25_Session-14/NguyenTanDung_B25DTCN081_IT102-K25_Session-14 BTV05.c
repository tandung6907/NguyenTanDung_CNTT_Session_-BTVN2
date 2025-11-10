#include<stdio.h>
long long factorial(int num, int i) {
	long long factorial=1;
	for (i=1 ; i<=num ; i++) {
		factorial *= i;
	}
	return factorial;
}
int main () {
	int num, i;
	printf("Nhap mot so nguyen duong bat ky: ");
	scanf("%d",&num);
		if (num<=0) {
			printf("Vui long nhap mot so nguyen duong!!");
		}
	
	printf("Gia thua cua so nguyen duong vua nhap la: %d",factorial(num,i));
	
}
