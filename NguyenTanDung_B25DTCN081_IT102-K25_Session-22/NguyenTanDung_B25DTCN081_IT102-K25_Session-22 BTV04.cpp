#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define ORIGINAL_SIZE 0

int current_size = ORIGINAL_SIZE;

typedef struct {
	
	int day;
	int month;
	int year;
	
}Date;

typedef struct {
	
	char productCode[15];
	char customerName[50];
	Date order;
	double totalBill;
	char status[50];
	
}InforAboutProduct;

InforAboutProduct list[MAX_SIZE];

void displayMenu () {
	
	printf("======================================================");
	printf("\n------------------QUAN LY DON HANG-------------------\n");
	printf("\n1.Nhap thong tin don hang\n");
	printf("\n2.Hien thi thong tin don hang\n");
	printf("\n3.Cap nhat trang thai don hang\n");
	printf("\n4.Xoa don hang theo ma don hang\n");
	printf("\n5.Sap xep don hang theo tong tien\n");
	printf("\n6.Tim kiem don hang theo ma don hang\n");
	printf("\n7.Thoat chuong trinh\n");
	printf("\n======================================================\n");
	
}

void enterInformationOfProduct () {
	printf("---NHAP THONG TIN DON HANG---\n");
	
	printf("Nhap so luong don hang trong danh sach ban dau: ");
	scanf("%d", &current_size);
	getchar();
	
	if (current_size<=0 || current_size>=MAX_SIZE) {
		printf("Vui long nhap so luong don hang lon hon 0 va nho hon 100");
		return;
	}
	
	int i;
	for (i=0; i<current_size; i++) {

		printf("Ma Don Hang: ");
		fgets(list[i].productCode, sizeof(list[i].productCode), stdin);
		list[i].productCode[strcspn(list[i].productCode, "\n")] = '\0';
		fflush(stdin);
		
		printf("Ten Khach Hang: ");
		fgets(list[i].customerName, sizeof(list[i].customerName), stdin);
		list[i].customerName[strcspn(list[i].customerName, "\n")] = '\0';
		fflush(stdin);
		
		printf("--Ngay Dat Hang--\n");
		printf("Ngay: ");
		scanf("%d", &list[i].order.day);
		getchar();
		printf("Thang: ");
		scanf("%d", &list[i].order.month);
		getchar();
		printf("Nam: ");
		scanf("%d", &list[i].order.year);
		getchar();
		
		printf("Tong tien hang: ");
		scanf("%lf",&list[i].totalBill);
		getchar();
		
		printf("Ghi chu - Trang thai don hang: ");
		fgets(list[i].status, sizeof(list[i].status), stdin);
		list[i].status[strcspn(list[i].status, "\n")] = '\0';
		fflush(stdin);
		
	}
	
	printf("DA THEM DANH SACH THANH CONG!!!");
}

void printInformationOfProduct () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin don hang!!!");
		return;
	}
	
	int i;
    printf("           DANH SACH DON HANG HIEN TAI (%d)             \n", current_size);

    for (i=0; i<current_size; i++) {
        printf(" %-10s %-25s %d/%d/%d  %-10.2lf  %-15s\n", 
               list[i].productCode,
               list[i].customerName, 
               list[i].order.day, list[i].order.month, list[i].order.year,
               list[i].totalBill,
               list[i].status);
    }
	
}

void updateOrderStatus () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin don hang!!!");
		return;
	}
	getchar();
	char productCodeNeedToUpdate[15];
	printf("Nhap vao MDH can cap nhat: ");
	fgets(productCodeNeedToUpdate, sizeof(productCodeNeedToUpdate), stdin);
	productCodeNeedToUpdate[strcspn(productCodeNeedToUpdate, "\n")] = '\0';
	fflush(stdin);
	
	int found = -1;
	int i;
	for (i=0; i<current_size; i++) {
		if (strcmp(list[i].productCode, productCodeNeedToUpdate)==0) {
			found = i;
			break;
		}
	}
	if (found==-1) {
		printf("Khong tim thay don hang nao theo ma don hang vua nhap!!!");
		return;
	}
	if (found==i) {
		
		printf("Ghi chu - Trang thai don hang: ");
		fgets(list[found].status, sizeof(list[found].status), stdin);
		list[found].status[strcspn(list[found].status, "\n")] = '\0';
		fflush(stdin);
		
	}
	printf("DA CAP NHAT THANH CONG!!!!");
	
}

void deleteOrderByProCode () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin don hang!!!");
		return;
	}
	getchar();
	char proCodeNeedToDelete[15];
	printf("Nhap MDH muon xoa khoi danh sach: ");
	fgets(proCodeNeedToDelete, sizeof(proCodeNeedToDelete), stdin);
	proCodeNeedToDelete[strcspn(proCodeNeedToDelete, "\n")] = '\0';
	fflush(stdin);
	
	int found = -1;
	int i;
	for (i=0; i<current_size; i++) {
		if (strcmp(list[i].productCode, proCodeNeedToDelete) == 0) {
			found = i;
			break;
		}
	}
	if (found==-1) {
		printf("Khong tim thay don hang nao theo ma don hang can tim!!!");
		return;
	}
	for (i=found; i<current_size-1; i++) {
		list[i] = list[i + 1];
	}
	current_size--;
	printf("DA XOA THANH CONG!!");
	
}

void sortOrderByTotalBill () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin don hang!!!");
		return;
	}
	int i, j, temp;
	for (i=0; i<current_size; i++) {
		for (j=i+1; j<current_size; j++) {
			if(list[i].totalBill>list[j].totalBill){
				InforAboutProduct temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	printf("DANH SACH DA SAP XEP THANH CONG!!");
}

void findOrderByProCode () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin sinh vien!!!");
		return;
	}
	
	getchar();
	char proCodeNeedToFind[15];
	printf("Nhap MSP ban muon tim trong danh sach: ");
	fgets(proCodeNeedToFind, sizeof(proCodeNeedToFind), stdin);
	proCodeNeedToFind[strcspn(proCodeNeedToFind, "\n")] = '\0';
	fflush(stdin);
	
	int found = -1;
	int i;
	for (i=0; i<current_size; i++) {
		if (strcmp(list[i].productCode, proCodeNeedToFind) == 0) {
			found = i;
		}
	}
	if (found==-1) {
		printf("Khong tim thay san pham nao co MSP: %s can tim", proCodeNeedToFind);
		return;
	}	
		
	printf("Da tim thay san pham co MSP: %s Ten Khach Hang: %s || Tong Tien Hang: %s || Ngay Dat Hang: %d/%d/%d || Trang Thai: %s",
		proCodeNeedToFind,
		list[found].customerName,
		list[found].totalBill,
		list[found].order.day,
		list[found].order.month,
		list[found].order.year,
		list[found].status);
		
	
}

int main () {
	
	int choice;
	do {
		
		displayMenu ();
		printf("Vui long nhap vao lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		
		switch (choice) {
			case 1:
				enterInformationOfProduct ();
				printf("\n");
				break;
			case 2:
				printInformationOfProduct ();
				printf("\n");
				break;
			case 3:
				updateOrderStatus ();
				printf("\n");
				break;
			case 4:
				deleteOrderByProCode ();
				printf("\n");
				break;
			case 5:
				sortOrderByTotalBill ();
				printf("\n");
				break;
			case 6:
				findOrderByProCode ();
				printf("\n");
				break;
			case 7:
				printf("Cam On Vi Da Den!!!");
				printf("\n");
				break;
			default:
				printf("Vui long nhap lua chon theo Menu!!");
				printf("\n");
				break;
		}
		
	} while (choice!=7);
	
	return 0;
}
