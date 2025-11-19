#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Address {
	
	char street[100];
	char city[50];
	int zip;
	
};

struct Person  {
	
	char name[50];
	int age;
	struct Address address;
	
};

int main () {
	
	struct Person person1;
	
	printf("---THONG TIN NGUOI DUNG---\n");
	printf("=============================\n");
	
	printf("---Dia Chi---\n");
	printf("Nhap ten thanh pho: ");
	fgets(person1.address.city, sizeof(person1.address.city), stdin);
	person1.address.city[strcspn(person1.address.city, "\n")] = 0;
	fflush(stdin);
	
	printf("Nhap ten duong: ");
	fgets(person1.address.street, sizeof(person1.address.street), stdin);
	person1.address.street[strcspn(person1.address.street, "\n")] = 0;
	fflush(stdin);
	
	printf("Nhap ma buu dien: ");
	scanf("%d",&person1.address.zip);
	getchar();
	
	printf("==============================\n");
	
	printf("---Thong tin ca nhan---\n");
	printf("Nhap ten nguoi dung: ");
	fgets(person1.name, sizeof(person1.name), stdin);
	person1.name[strcspn(person1.name, "\n")] = 0;
	fflush(stdin);
	
	printf("Nhap tuoi nguoi dung: ");
	scanf("%d",&person1.age);
	getchar();
	
	printf("Ten Thanh Pho: %s || Ten Duong: %s || Ma Buu Dien: %d\n",person1.address.city, person1.address.street, person1.address.zip);
	printf("Ho va ten: %s || Tuoi: %d",person1.name, person1.age);
	
	return 0;
}
