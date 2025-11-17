#include<stdio.h>
#define MAX 100

void displayMenu() {
	printf("========================================");
	printf("\n------------------MENU------------------");
	printf("\n1.Nhap vao so phan tu va phan tu trong mang");
	printf("\n2.In ra cac phan tu la so chan");
	printf("\n3.In ra cac phan tu la so nguyen to");
	printf("\n4.Dao nguoc mang");
	printf("\n5.Sap xep mang");
	printf("\n6.Nhap mot phan tu va tim kiem phan tu trong mang");
	printf("\n7.Thoat");
	printf("\n========================================\n");
}

void enterElements(int *num,int *arr) {
	int i, n;
	printf("Nhap vao so phan tu cua mang: ");
	scanf("%d",&n);
	if (n<0 || n>MAX) {
		printf("Vui long nhap so phan tu lon hon 0 va nho hon 100");
		return;
	}
	*num = n;
	for (i=0 ; i<*num ; i++) {
		printf("Nhap vao so thu %d: ",i+1);
		scanf("%d",&arr[i]);
	}
}

void printElements(int *num, int *arr) {
	if (*num==0) {
		printf("Mang rong. Vui long nhap so phan tu va gia tri cua phan tu cho mang");
		return;
	}
	int i;
	printf("Cac phan tu la so chan trong mang la: \n");
	for (i=0 ; i<*num ; i++) {
		if (*(arr+i)%2==0) {
			printf("%d\t",*(arr+i));
		}
	}
}

int primeElements(int *arr, int num) {
	int isPrime=0,found=0;
	int i, j;
	for(i=0 ; i<num ; i++){
		if(arr[i]<=1){
			isPrime=0;
		}
	
	for(j=2 ; j*j<=arr[i] ; j++){
		if(arr[i]%j==0){
			isPrime=0;
			break;
		}
	}
}
	for(i=0 ;i<num ; i++){
	if(isPrime){
		printf("Cac phan tu la so nguyen to la %d",arr[i]);
		found=1;
	}
}
	if(!found){
		printf("Khong co so nguyen to");
	}

}

int reverseArray(int *arr, int num) {
	int temp, i;
    for (i=0 ; i<num/2 ; i++) {
        temp = arr[i];
        arr[i] = arr[num - 1 - i];
        arr[num - 1 - i] = temp;
    }
    printf("Mang da duoc dao nguoc");
}

void bubbleSort(int *arr, int num) {
	int i, j;
	for (i=0 ; i<num-1 ; i++) {
        for (j=i+1 ; j<num ; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang da sap xep tang dan");
}

void bubbleSort2(int *arr, int num) {
	int i, j;
	for (i=0 ; i<num-1 ; i++) {
        for (j=i+1 ; j<num ; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang da sap xep giam dan");
}

void findValue(int *arr,int num){
	int found =0;
	int value, i;
	printf("Nhap phan tu can tim: ");
	scanf("%d",&value);
	for(i=0 ; i<num ; i++){
		if(arr[i]==value){
			printf("Phan tu can tim co gia tri %d o vi tri %d",value,i);
			found=1;
		}
	}
	if (!found) {
        printf("Khong tim thay phan tu %d trong mang", value);
    }
}

int main () {
	
	int choice, num=0, arr[MAX];
	do {
		displayMenu();
		printf("Vui long nhap lua chon cua ban: ");
		scanf("%d",&choice);
		
		switch (choice) {
			case 1: 
				enterElements(&num, arr);
				printf("\n");
				break;
			case 2: 
				printElements(&num, arr);
				printf("\n");
				break;
			case 3: 
				primeElements(arr, num);
				printf("\n");
				break;
			case 4:
				reverseArray(arr, num);
				printf("\n");
				break;
			case 5: 
				int choice2;
			do{
				printf("========================================");
				printf("\n------------------MENU------------------");
				printf("\n1.Sap xep tang dan");
				printf("\n2.Sap xep giam dan");
				printf("\n3.Thoat chuong trinh sap xep");
				printf("\n========================================");
				printf("\nChon cach sap xep cua ban: ");
				scanf("%d",&choice2);
				switch (choice2) {
					case 1:
						bubbleSort(arr, num);
						printf("\n");
						break;
					case 2:
						bubbleSort2(arr, num);
						printf("\n");
						break;
					case 3:
						printf("Ban da thoat chuong trinh sap xep!");
						printf("\n");
						break;
					default:
						printf("Vui long nhap 1 trong 2 lua chon sap xep!!");
						printf("\n");
						break;
				}
			}while(choice2!=3);
				printf("\n");
				break;
			case 6:
				findValue(arr, num);
				printf("\n");
				break;
			case 7: 
				printf("Ban da thoat chuong trinh. Hen gap lai<33");
				printf("\n");
				break;
			default: 
				printf("Lua chon cua ban khong hop le. Vui long nhap lua chon theo MENU!!");
				printf("\n");
				break;
		}
	} while (choice!=7);
	
	return 0;
}
