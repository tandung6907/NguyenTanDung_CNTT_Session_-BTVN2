#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define INITIAL_COUNT 7

int current_size = INITIAL_COUNT;

typedef struct {
	
	int id;
	char name[50];
	char phoneNumber[15];
	char email[50];
	
}Contact;

Contact list[MAX_SIZE] = {
	{1, "Nguyen Tan Dung", "0901111111", "ntd01@gmail.com"},
	{2, "Ha Duc Minh", "0902222222", "hdm02@gmail.com"},
	{3, "Quach Tran Anh", "0903333333", "qta03@gmail.com"},
	{4, "Vu Le Minh Hieu", "0904444444", "vlmh04@gmail.com"},
	{5, "Dang Viet Dung", "0905555555", "dvd05@gmail.com"},
	{6, "Pham Ho Nam Khanh", "0906666666", "phnk06@gmail.com"},
	{7, "Nguyen Minh Hien", "0907777777", "nmh07@gmail.com"}
};

void displayContactLists () {
	
	printf("------CONTACT LISTS------");
	printf("\n1.Them lien he moi\n");
	printf("\n2.Hien thi tat ca lien he\n");
	printf("\n3.Tim kiem theo ten\n");
	printf("\n4.Xoa lien he theo ten\n");
	printf("\n5.Thoat danh ba\n");
	
}

int getNextId() {
    int maxId = 0;
    for (int i = 0; i < current_size; ++i) {
        if (list[i].id > maxId) {
            maxId = list[i].id;
        }
    }
    return maxId + 1;
}

void addNewContact () {
	if (current_size>=MAX_SIZE) {
		printf("LOI: Mang da day khong the them lien lac!!");
		return;
	}
	
	Contact* new_contact = &list[current_size];
	new_contact->id = getNextId();
	
	printf("---NHAP THONG TIN LIEN HE MOI---\n");
	
	printf("Ho va ten: ");
	fgets(new_contact->name, sizeof(new_contact->name), stdin);
	new_contact->name[strcspn(new_contact->name, "\n")] = '\0';
	fflush(stdin);
	
	printf("SDT: ");
	fgets(new_contact->phoneNumber, sizeof(new_contact->phoneNumber), stdin);
	new_contact->phoneNumber[strcspn(new_contact->phoneNumber, "\n")] = '\0';
	fflush(stdin);
	
	printf("Email: ");
	fgets(new_contact->email, sizeof(new_contact->email), stdin);
	new_contact->email[strcspn(new_contact->email, "\n")] = '\0';
	fflush(stdin);

	current_size++;
	printf("DA THEM LIEN HE MOI THANH CONG!!!");
	
}

void findContact () {
	
	char nameNeedToFind[50];
	printf("Nhap ten lien he ban can tim: ");
	fgets(nameNeedToFind, sizeof(nameNeedToFind), stdin);
	nameNeedToFind[strcspn(nameNeedToFind, "\n")] = '\0';
	fflush(stdin);
	
	int i, found;
	for (i=0; i<current_size; i++) {
		found = 0;
		if (strcmp(list[i].name, nameNeedToFind) == 0) {
			found = 1;
		}
		if (found==1) {
			printf("Da tim thay lien he co ten: %s\n O vi tri: %d\n SDT va Email la: %s %s ", list[i].name, list[i].id, list[i].phoneNumber, list[i].email);
			break;
		}
	}
	if (!found) {
		printf("Khong tim thay lien he can tim trong danh sach!!!");
	}
}

void deleteContact () {
	
	char nameNeedToDelete[50];
	printf("Nhap vao ten lien he ban muon xoa: ");
	fgets(nameNeedToDelete, sizeof(nameNeedToDelete), stdin);
	nameNeedToDelete[strcspn(nameNeedToDelete, "\n")] = '\0';
	fflush(stdin);
	
	int i;
	int idNeedToDelete = -1;
	for (i=0; i<current_size; i++) {
		if (strcmp(nameNeedToDelete, list[i].name) == 0) {
			idNeedToDelete = i; 
			break;
		}
	}
	if (idNeedToDelete==-1) {
			printf("Khong tim thay ten liec lac %s trong danh ba!", nameNeedToDelete);
			return;
		}
	for (i=idNeedToDelete; i<current_size-1; i++) {
        list[i] = list[i + 1];
    }
	current_size--;
	printf("DA XOA THANH CONG!!");
	
}

void printContact (Contact arr[], int length) {
	if (length==0) {
		printf("Danh sach trong!!");
		return;
	}
	printf("------Danh sach lien lac------\n");
	int i;
	for (i=0; i<length; i++) {
		printf("ID: %d || Ten: %s || SDT: %s || Email: %s \n",arr[i].id, arr[i].name, arr[i].phoneNumber, arr[i].email);
	}
}

int main () {
	
	int choice;
	do {
		
		displayContactLists ();
		printf("Nhap vao lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		
		switch (choice) {
			case 1:
				addNewContact ();
				printf("\n");
				break;
			case 2:
				printContact (list, current_size);
				printf("\n");
				break;
			case 3:
				findContact ();
				printf("\n");
				break;
			case 4:
				deleteContact ();
				printf("\n");
				break;
			case 5:
				printf("Cam on vi da su dung chuong trinh cua toi<33");
				printf("\n");
				break;
			default:
				printf("LOI!! Vui long nhap lua chon co trong MENU!!");
				printf("\n");
				break;
		}
		
	} while (choice!=5);
	
	return 0;
}
