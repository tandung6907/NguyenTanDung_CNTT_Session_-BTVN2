/*
Kh?i t?o m?t m?ng s? nguyên dã du?c s?p x?p theo th? t? tang d?n.
Yêu c?u ngu?i dùng nh?p vào m?t ph?n t? và s? d?ng thu?t toán tìm ki?m nh? phân (Binary Search) d? tìm ki?m ph?n t? trong m?ng.
In ra ch? s? c?a ph?n t? n?u tìm th?y, n?u không thì thông báo không tìm th?y ph?n t?.
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
	printf("Mang truoc khi sap xep la: \n");
	for (i=0 ; i<num ; i++){
		printf("%d\t",arr[i]);
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
		printf("%d\t",arr[i]);
	}
	
	printf("\n");
	int searchvl;
	printf("Nhap gia tri can tim: ");
	scanf("%d",&searchvl);
	int mid, left = 0, right = num -1;
	do{
		mid = left + (right - left)/2;
		if (arr[mid]>searchvl){
			right = mid -1;
		}
		if (arr[mid]<searchvl){
			left = mid +1;
		}
	}while(arr[mid]!=searchvl&&left<=right);
	
	 if (arr[mid]==searchvl){
	 	printf("Phan tu can tim co chi so %d va gia tri = %d",mid,searchvl);
	 }else {
	 	printf("Khong tim thay phan tu nao co gia tri = %d trong mang",searchvl);
	 }
	
	return 0;
}
