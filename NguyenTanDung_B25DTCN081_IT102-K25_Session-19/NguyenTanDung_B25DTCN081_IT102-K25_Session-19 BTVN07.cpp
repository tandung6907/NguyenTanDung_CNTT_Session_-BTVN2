#include<stdio.h>
#define MAX_SIZE 100
#include<string.h>

void displaymenu() {
	printf("================================");
	printf("\n1.Nhap vao so phan tu va tung phan tu cua mang");
	printf("\n2.Hien thi cac phan tu trong mang");
	printf("\n3.Tinh do dai mang");
	printf("\n4.Tinh tong cac phan tu trong mang");
	printf("\n5.Hien thi phan tu lon nhat");
	printf("\n6.Thoat");
	printf("\n================================\n");
}

void enterElements(int *num, int *arr) {
	int n;
	printf("Nhap vao so phan tu cua mang: ");
	scanf("%d",&n);
	*num = n;
	if (n<0 || n>MAX_SIZE) {
		printf("Vui long nhap lai so phan tu cua mang!\n");
		return;
	}
	
	int i;
	for (i=0 ; i<*num ; i++) {
		printf("Nhap so thu %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\n");
}

void printElements(int *num, int *arr) {
	int i;
	printf("Cac phan tu cua mang la: ");
	for (i=0 ; i<*num ; i++) {
		printf("%d\t",*(arr+i));
	}
	printf("\n");
}

int sumElements(int *arr, int *num) {
	int i;
	int sum = 0;
	for (i=0 ; i<*num ; i++) {
		sum += *(arr+i);
	}
	return sum;
}

int maxElements(int *num, int *arr){
	int max = arr[0];
	int i;
	for (i=0 ; i<*num ; i++) {
		if (arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}

int main () {
	
	int choice, num, arr[MAX_SIZE];
	do {
		displaymenu();
		printf("Nhap vao lua chon cua ban: ");
		scanf("%d",&choice);
		
		switch (choice) {
			case 1: {
				enterElements(&num, arr);
				break;
			}
			case 2: {
				printElements(&num, arr);
				break;
			}
			case 3: {
				printf("Do dai cua mang la: %d",num);
				printf("\n");
				break;
			}
			case 4: {
				int sum = sumElements(arr, &num);
				printf("Tong cac phan tu trong mang: %d",sum);
				printf("\n");
				break;
			}
			case 5: {
				int max = maxElements(&num, arr);
				printf("Gia tri lon nhat trong mang la: %d",maxElements(&num, arr));
				printf("\n");
				break;
			}
			case 6: {
				printf("Ban da thoat chuong trinh Hen gap lai<33");
				break;
			}
			default: {
				printf("LOI: Lua chon cua ban khong hop le. Vui long nhap lua chon tu 1 den 6!!!");
				printf("\n");
				break;
			}
		}
		
	}while(choice!=6);
	
	return 0;
}
