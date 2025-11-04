/*
Vi?t chuong trình tìm ki?m m?t s? nguyên trong m?ng b?ng phuong pháp tìm ki?m tu?n t?. N?u s? dó t?n t?i, in ra t?ng s? l?n xu?t hi?n c?a s? dó trong m?ng.
*/
#include<stdio.h>
int main () {
	
	int num,i;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&num);
	
	int arr[num];
	for (i=0 ; i<num ; i++){
		printf("Number[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	
	int searchvl;
	printf("Nhap gia tri can tim: ");
	scanf("%d",&searchvl);
	
	int cnt =0;
	for (i=0 ; i<num ; i++){
		if (arr[i]==searchvl){
		
			cnt++;
		}
	}
	if (cnt>0) {
		printf("So lan xuat hien cua so can tim la: %d",cnt);
	}else {
		printf("Khong tim thay gia tri can tim!!");
	}
	
	
	
	return 0;
}
