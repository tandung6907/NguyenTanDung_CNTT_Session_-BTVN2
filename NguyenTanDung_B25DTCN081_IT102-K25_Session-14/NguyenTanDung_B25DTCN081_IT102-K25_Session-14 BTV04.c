#include<stdio.h>
void printArr(int num, int i, int arr[]){
	printf("Cac phan tu trong mang la: \n");
	for (i=0 ; i<num ; i++) {
		printf("%d\t",arr[i]);
	}
}
int main () {
	int num, i;
	printf("Nhap vao so phan tu cua bang: ");
	scanf("%d",&num);
	
	int arr[num];
	for (i=0 ; i<num ; i++) {
		printf("Nhap vao so thu %d trong mang: ",i+1);
		scanf("%d",&arr[i]);
	}	

	printArr(num, i, arr);
	
	return 0;
}
