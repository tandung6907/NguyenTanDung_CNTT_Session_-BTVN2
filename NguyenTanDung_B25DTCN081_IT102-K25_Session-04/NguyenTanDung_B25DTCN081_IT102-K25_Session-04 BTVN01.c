#include<stdio.h>
int main(){
	int a;
	printf ("Nhap 1 so nguyen bat ky:",a);
	scanf ("%d",&a);
	if (a>0){
		printf("So vua nhap la so nguyen duong\n");
	} else if (a<0){
		printf("So vua nhap la so nguyen am\n");
	} else {
		printf("So vua nhap khong am khong duong");
	}
	
	
	return 0;
}
