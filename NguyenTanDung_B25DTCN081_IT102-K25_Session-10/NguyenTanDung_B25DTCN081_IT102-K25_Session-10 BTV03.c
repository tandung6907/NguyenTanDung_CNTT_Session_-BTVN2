/*
Vi?t chuong trình tìm ki?m m?t s? nguyên trong m?ng b?ng phuong pháp tìm ki?m tu?n t? (Linear Search). N?u s? dó t?n t?i, in ra ch? s? c?a ph?n t? d?u tiên tìm du?c, n?u không, in ra "Không tìm th?y".
*/
#include<stdio.h>
int main () {
	
	int num,i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&num);
    
    int arr[num];
    for (i=0 ; i<num ; i++){
    	printf("number[%d]: ",i);
    	scanf("%d",&arr[i]);
	}
	
	int searchvl;
	int isExist;
	printf("Nhap gia tri can tim: ");
	scanf("%d",&searchvl);
	for (i=0 ; i<num ; i++){
		if (arr[i]==searchvl){
			isExist = 1;
			printf("Phan tu co chi so %d co gia tri la %d : ",i,searchvl);
			break;
		}
		if (!isExist){
		printf("Khong tim thay phan tu nao co gia tri can tim!!",searchvl);		
		break;
	    }   
	
	}
	return 0;
}


