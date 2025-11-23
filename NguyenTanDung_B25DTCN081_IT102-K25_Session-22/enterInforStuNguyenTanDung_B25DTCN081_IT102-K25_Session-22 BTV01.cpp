#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Student {
	
	char name[50];
	int age;
	float grade;
	
};

struct Student students[MAX_SIZE];

void enterInforStudents (struct Student arr[], int* length) {
	
		printf("Nhap vao so luong hoc sinh trong danh sach: ");
		scanf("%d",length);
		getchar();
		if (*length<0 || *length>MAX_SIZE) {
			printf("Vui long nhap so luong hoc sinh lon hon 0 va nho hon 100");
			return;
		}

	int i;
	for (i=0; i<*length; i++) {
		
		printf("Nhap ten cua sinh vien: ");
		fgets(students[i].name,sizeof(students[i].name),stdin);
		students[i].name[strcspn(students[i].name, "\n")] = 0;
  		fflush(stdin);
		
		printf("Nhap tuoi cua sinh vien: ");
		scanf("%d",&students[i].age);
		getchar();
		
		printf("Nhap diem tong ket cua sinh vien: ");
		scanf("%f",&students[i].grade);
		getchar();
		
	}
	printf("DA CAP NHAT DANH SACH SINH VIEN THANH CONG!!!");
	printf("\n");
}

void printInforStudents (struct Student arr[], int length) {
	
	if (length==0) {
		printf("Danh sach trong!!! Vui long nhap thong tin cua sinh vien truoc!!!!");
		return;
	}
	
	int i;
	printf("------DANH SACH SINH VIEN------\n");
	for (i=0; i<length; i++) {
		printf("Ten: %s || Tuoi: %d || Diem: %.2f \n",arr[i].name, arr[i].age, arr[i].grade);
	}
	
}

void averageOfGoalOfStudents (struct Student arr[], int length) {
	
	if (length==0) {
		printf("Danh sach trong!!! Vui long nhap thong tin cua sinh vien truoc!!!!");
		return;
	}
	
	int i;
	int sum = 0;
	float averageGoal;
	for (i=0; i<length; i++) {
		sum += arr[i].grade;
		averageGoal = sum/length;
	}
	printf("Diem trung binh cua tat ca sinh vien trong danh sach la: %.2f",averageGoal);
	printf("\n");
	
}

void displayMenu () {
	printf("==========================================================");
	printf("\n----------DANH SACH DIEM TRUNG BINH CUA HOC SINH----------\n");
	printf("\n1.Nhap vao thong tin cua hoc sinh\n");
	printf("\n2.Hien thi thong tin cua hoc sinh\n");
	printf("\n3.Tinh diem trung binh cua tat ca hoc sinh trong danh sach\n");
	printf("\n4.Thoat chuong trinh\n");
	printf("\n==========================================================\n");
}

int main () {
	
	int i, size, choice;
	do{
		displayMenu ();
		printf("Moi ban nhap vao lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		
		switch (choice) {
			case 1:
				enterInforStudents (students, &size);
				printf("\n");
				break;
			case 2:
				printInforStudents (students, size);
				printf("\n");
				break;
			case 3:
				averageOfGoalOfStudents (students, size);
				printf("\n");
				break;
			case 4:
				printf("Cam on vi da su dung chuong trinh cua toi!!");
				printf("\n");
				break;
			default:
				printf("LOI: Lua chon cua ban khong hop le! Vui long nhap lua chon theo MENU!!");
				printf("\n");
				break;
		}
	} while (choice!=4);
	
	
	return 0;
}
