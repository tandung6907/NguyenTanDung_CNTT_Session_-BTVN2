#include<stdio.h>
#define MAX_SIZE 35
#define INITIAL_COUNT 6

int product_count = INITIAL_COUNT;

struct Product {
	
	char name[50];
	float price;
	int quanlity;
	
};

struct Product products[MAX_SIZE] = {
	{"Ha Duc Minh",360,1},
	{"Vu Le Minh Hieu",340,1},
	{"Pham Ho Nam Khanh",180,1},
	{"Quach Tran Anh",340,1},
	{"Nguyen Minh Hien",340,10},
	{"Dang Viet Dung",120,3}
};

void printProducts(const struct Product arr[], int count) {
    if (count == 0) {
        printf("\nKhong co san pham nao trong danh sach.\n");
        return;
    }
    
    printf("\n=================================================================\n");
    printf("           DANH SACH SAN PHAM HIEN TAI (%d)             \n", count);
    printf("=================================================================\n");
    
    printf("%-20s %-30s %-10s \n", "Ten San Pham", "Gia Ban", "So Luong");
    printf("-----------------------------------------------------------------\n");

	int i;
    for (i=0; i<count; ++i) {
        printf("%-20s %-30.1f %-10d \n", 
               products[i].name,
               products[i].price,
               products[i].quanlity);
    }
    printf("=================================================================\n");
}

int main () {
	
	printProducts(products, product_count);
	
	float sumOfEachProduct = 0, totalBill;
	int i;
	for (i=0; i<5; i++) {
		sumOfEachProduct = products[i].price*products[i].quanlity;
		totalBill += sumOfEachProduct;
	}
	
	printf("Tong tien cac san pham trong cua hang: ");
	for (i=0; i<5; i++) {
		printf("%.1f USD",totalBill);
		break;
	}
	
	return 0;
}
