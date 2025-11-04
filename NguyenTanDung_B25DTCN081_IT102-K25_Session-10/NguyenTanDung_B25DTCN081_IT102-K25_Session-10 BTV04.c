/*
Vi?t chuong trình s?p x?p m?t m?ng s? nguyên theo th? t? tang d?n b?ng thu?t toán Bubble Sort. Sau khi s?p x?p, in ra m?ng dã s?p x?p.
*/
#include<stdio.h>
int main () {
	
	int num,i,j,temp;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&num);
	
	int arr[num];
	for ( i=0 ; i<num ; i++){
		printf("Number[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	//bubble sort
	printf("\nMang sau khi sap xep la: \n");
	for (i=0 ; i<num-1 ; i++){
		for (j=0 ; j<num-1-i ; j++){
			if (arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}	
		}	
	}
	for (i=0 ; i<num ; i++){
			printf("%d \t",arr[i]);
		}
	return 0;
	
}
