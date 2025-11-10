#include<stdio.h>
int searchMax(int num, int i, int arr[]) {
	int max = arr[0];
	for (i=0 ; i<num ; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
int main () {
	
	int num, i, max;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&num);
	
	int arr[num];
	for (i=0 ; i<num ; i++) {
		printf("So thu %d la: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	int result;
	result = searchMax(num,i,arr);
	printf("GTLN trong mang la: %d",result);
	
	return 0;
}
