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
	
}Birthday;

typedef struct {
	
	char studentCode[15];
	char name[50];
	Birthday birth;
	char phoneNumber[15];
	char address[50];
	
}Student;

Student list[MAX_SIZE];	

void displayMenu () {
	
	printf("======================================================");
	printf("\n------------------QUAN LY SINH VIEN-------------------\n");
	printf("\n1.Nhap thong tin sinh vien\n");
	printf("\n2.Hien thi thong tin sinh vien\n");
	printf("\n3.Them sinh vien vao cuoi danh sach\n");
	printf("\n4.Xoa sinh vien theo ma sinh vien\n");
	printf("\n5.Cap nhat thong tin sinh vien theo ma sinh vien\n");
	printf("\n6.Sap xep sinh vien theo ho tu A den Z\n");
	printf("\n7.Tim kiem sinh vien theo ma sinh vien\n");
	printf("\n8.Thoat chuong trinh\n");
	printf("\n======================================================\n");
	
}

void enterInformationOfStudent () {
	
	printf("---NHAP THONG TIN SINH VIEN---\n");
	
	printf("Nhap so luong sinh vien trong danh sach ban dau: ");
	scanf("%d", &current_size);
	getchar();
	
	if (current_size<=0 || current_size>=MAX_SIZE) {
		printf("Vui long nhap so luong sinh vien lon hon 0 va nho hon 100");
		return;
	}
	
	int i;
	for (i=0; i<current_size; i++) {

		printf("Ma Sinh Vien: ");
		fgets(list[i].studentCode, sizeof(list[i].studentCode), stdin);
		list[i].studentCode[strcspn(list[i].studentCode, "\n")] = '\0';
		fflush(stdin);
		
		printf("Ho Ten: ");
		fgets(list[i].name, sizeof(list[i].name), stdin);
		list[i].name[strcspn(list[i].name, "\n")] = '\0';
		fflush(stdin);
		
		printf("SDT: ");
		fgets(list[i].phoneNumber, sizeof(list[i].phoneNumber), stdin);
		list[i].phoneNumber[strcspn(list[i].phoneNumber, "\n")] = '\0';
		fflush(stdin);
		
		printf("Thang Sinh: ");
		scanf("%d", &list[i].birth.month);
		getchar();
		printf("Ngay Sinh: ");
		scanf("%d", &list[i].birth.day);
		getchar();
		printf("Nam Sinh: ");
		scanf("%d", &list[i].birth.year);
		getchar();
		
		printf("Dia Chi: ");
		fgets(list[i].address, sizeof(list[i].address), stdin);
		list[i].address[strcspn(list[i].address, "\n")] = '\0';
		fflush(stdin);
		
	}
	
	printf("DA THEM DANH SACH THANH CONG!!!");
	
}

void printInformationOfStudent () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin sinh vien!!!");
		return;
	}
	
	int i;
    printf("           DANH SACH SINH VIEN HIEN TAI (%d)             \n", current_size);

    for (i=0; i<current_size; i++) {
        printf(" %-10s %-25s %d/%d/%d  %-10s  %-15s\n", 
               list[i].studentCode,
               list[i].name, 
               list[i].birth.day, list[i].birth.month, list[i].birth.year,
               list[i].phoneNumber,
               list[i].address);
    }
    
}

void addInformationOfStudent () { 
	
	if (current_size>=MAX_SIZE) {
		printf("Mang da day khong the them sinh vien vao danh sach!!");
		return;
	}
	
	printf("-----THEM THONG TIN SINH VIEN-----\n");
	
	getchar();
	printf("Ma Sinh Vien: ");
	fgets(list[current_size].studentCode, sizeof(list[current_size].studentCode), stdin);
	list[current_size].studentCode[strcspn(list[current_size].studentCode, "\n")] = '\0';
	fflush(stdin);
		
	printf("Ho Ten: ");
	fgets(list[current_size].name, sizeof(list[current_size].name), stdin);
	list[current_size].name[strcspn(list[current_size].name, "\n")] = '\0';
	fflush(stdin);
		
	printf("SDT: ");
	fgets(list[current_size].phoneNumber, sizeof(list[current_size].phoneNumber), stdin);
	list[current_size].phoneNumber[strcspn(list[current_size].phoneNumber, "\n")] = '\0';
	fflush(stdin);
	
	printf("Thang Sinh: ");
	scanf("%d", &list[current_size].birth.month);
	getchar();	
	printf("Ngay Sinh: ");
	scanf("%d", &list[current_size].birth.day);
	getchar();
	printf("Nam Sinh: ");
	scanf("%d", &list[current_size].birth.year);
	getchar();
		
	printf("Dia Chi: ");
	fgets(list[current_size].address, sizeof(list[current_size].address), stdin);
	list[current_size].address[strcspn(list[current_size].address, "\n")] = '\0';
	fflush(stdin);
	
	current_size++;
	printf("DA THEM THONG TIN SINH VUA NHAP THANH CONG!!!");
	
}

void deleteStuByStuCode () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin sinh vien!!!");
		return;
	}
	
	getchar();
	char stuCodeNeedToDelete[15];
	printf("Nhap MSV muon xoa khoi danh sach: ");
	fgets(stuCodeNeedToDelete, sizeof(stuCodeNeedToDelete), stdin);
	stuCodeNeedToDelete[strcspn(stuCodeNeedToDelete, "\n")] = '\0';
	fflush(stdin);
	
	int found = -1;
	int i;
	for (i=0; i<current_size; i++) {
		if (strcmp(list[i].studentCode, stuCodeNeedToDelete) == 0) {
			found = i;
			break;
		}
	}
	if (found==-1) {
		printf("Khong tim thay MSV %s trong danh sach!!",stuCodeNeedToDelete);
		return;
	}
	for (i=found; i<current_size-1; i++) {
		list[i] = list[i + 1];
	}
	current_size--;
	printf("DA XOA THANH CONG!!");
	
}

void updateInforStuByStuCode () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin sinh vien!!!");
		return;
	}
	
	getchar();
	char stuCodeNeedToUpdate[15];
	printf("Nhap MSV can cap nhat trong danh sach: ");
	fgets(stuCodeNeedToUpdate, sizeof(stuCodeNeedToUpdate), stdin);
	stuCodeNeedToUpdate[strcspn(stuCodeNeedToUpdate, "\n")] = '\0';
	fflush(stdin);
	
	int found = -1;
	int i;
	for (i=0; i<current_size; i++) {
		if (strcmp(list[i].studentCode, stuCodeNeedToUpdate) == 0) {
			found = i;
			break;
		}
	}
	if (found==-1) {
		printf("Khong tim thay MSV %s trong danh sach!!",stuCodeNeedToUpdate);
		return;
	}
	if (found==i) {
		
		printf("Ho Ten: ");
		fgets(list[found].name, sizeof(list[found].name), stdin);
		list[found].name[strcspn(list[found].name, "\n")] = '\0';
		fflush(stdin);
		
		printf("SDT: ");
		fgets(list[found].phoneNumber, sizeof(list[found].phoneNumber), stdin);
		list[found].phoneNumber[strcspn(list[found].phoneNumber, "\n")] = '\0';
		fflush(stdin);
		
		printf("Thang Sinh: ");
		scanf("%d", &list[found].birth.month);
		getchar();
		printf("Ngay Sinh: ");
		scanf("%d", &list[found].birth.day);
		getchar();
		
		printf("Nam Sinh: ");
		scanf("%d", &list[found].birth.year);
		getchar();
		
		printf("Dia Chi: ");
		fgets(list[found].address, sizeof(list[found].address), stdin);
		list[found].address[strcspn(list[found].address, "\n")] = '\0';
		fflush(stdin);
	}
	
	printf("DA CAP NHAT THONG TIN SINH VIEN THANH CONG!");
	
}

void sortStuByName () {
	
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin sinh vien!!!");
		return;
	}
	
	int i, j;
	for(i=0; i<current_size-1; i++){
        for(j=i+1; j<current_size; j++){
            if(strcmp(list[i].name, list[j].name) > 0){
                Student temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    printf("SAP XEP THANH CONG!!");
	
}

void findStuByStuCode () {
	
	if (current_size==0) {
		printf("Danh Sach Trong!! Vui long nhap them thong tin sinh vien!!!");
		return;
	}
	
	getchar();
	char stuCodeNeedToFind[15];
	printf("Nhap MSV ban muon tim trong danh sach: ");
	fgets(stuCodeNeedToFind, sizeof(stuCodeNeedToFind), stdin);
	stuCodeNeedToFind[strcspn(stuCodeNeedToFind, "\n")] = '\0';
	fflush(stdin);
	
	int found = -1;
	int i;
	for (i=0; i<current_size; i++) {
		if (strcmp(list[i].studentCode, stuCodeNeedToFind) == 0) {
			found = i;
		}
	}
	if (found==-1) {
		printf("Khong tim thay sinh vien nao co MSV: %s can tim", stuCodeNeedToFind);
		return;
	}	
		
	printf("Da tim thay sinh vien co MSV: %s Ten: %s || SDT: %s || Ngay Sinh: %d/%d/%d || Dia chi: %s",
		stuCodeNeedToFind,
		list[found].name,
		list[found].phoneNumber,
		list[found].birth.day,
		list[found].birth.month,
		list[found].birth.year,
		list[found].address);
}

int main () {

	
	int choice;
	do {
		
		displayMenu ();
		printf("Nhap vao lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				enterInformationOfStudent ();
				printf("\n");
				break;
			case 2:
				printInformationOfStudent ();
				printf("\n");
				break;
			case 3:
				addInformationOfStudent ();
				printf("\n");
				break;
			case 4:
				deleteStuByStuCode ();
				printf("\n");
				break;
			case 5:
				updateInforStuByStuCode ();
				printf("\n");
				break;
			case 6:
				sortStuByName ();
				printf("\n");
				break;
			case 7:
				findStuByStuCode ();
				printf("\n");
				break;
			case 8:
				printf("Cam On Vi Da Den!!!");
				printf("\n");
				break;
			default:
				printf("LOI!! Vui long nhap lua chon theo MENU");
				printf("\n");
				break;
		}
	} while (choice!=8);
	
	return 0;
}
