/*
Kh?i t?o m?t m?ng s? nguyên b?t k?.
S? d?ng thu?t toán s?p x?p n?i b?t (Bubble Sort) d? s?p x?p m?ng theo th? t? tang d?n.
In ra m?ng dã du?c s?p x?p.
*/
#include<stdio.h>
int main () {
	
	int num,i,j;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&num);
	
	int arr[num];
	for (i=0 ; i<num ; i++){
		printf("Number[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	printf("Mang truoc khi duoc sap xep la: \n");
	for (i=0 ; i<num ; i++){
		printf("%d \t",arr[i]);
	}
	
	printf("\n");
	int temp;	
	for (i=0 ; i<num-1 ; i++){
		for (j=0 ; j<num-i-1 ; j++){
			if (arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("Mang sau khi duoc sap xep la: \n");
	for (i=0 ; i<num ; i++){
		printf("%d \t",arr[i]);
	}
	
	return 0;
}
