#include<stdio.h>
int caculateSum(int number1, int number2){
	int sum = number1 + number2;
	return sum;
}
int main () {
	int number1, number2;
	printf("Nhap vao so thu nhat: ");
	scanf("%d",&number1);
	printf("Nhap vao so thu hai: ");
	scanf("%d",&number2);
	
	int result;
	result = caculateSum(number1, number2);
	printf("Tong cua 2 so vua nhap la: %d",result);
	
	return 0;
} 
