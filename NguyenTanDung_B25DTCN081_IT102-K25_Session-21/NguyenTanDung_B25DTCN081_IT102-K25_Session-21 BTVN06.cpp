#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define INITIAL_COUNT 6

int count = INITIAL_COUNT;

struct Student {
	
	char name[50];
	int age;
	float grade;
	
};

struct Student student1[MAX_SIZE] = {
	{"Nguyen Tan Dung",18,9.6},
	{"Ha Duc Minh",19,5.1},
	{"Vu Le Minh Hieu",20,4.19},
	{"Quach Tran Anh",21,3.4},
	{"Dang Viet Dung",22,10.0},
	{"Pham Ho Nam Khanh",23,0.0}
};

void printStudent(const struct Student arr[], int count) {
    if (count == 0) {
        printf("\nKhong co san pham nao trong danh sach.\n");
        return;
    }
    
    printf("\n=================================================================\n");
    printf("               DANH SACH SINH VIEN NHOM I                  \n");
    printf("=================================================================\n");
    
    printf("%-20s %-30s %-10s \n", "Ten Sinh Vien", "Tuoi", "Diem Trung Binh");
    printf("-----------------------------------------------------------------\n");

	int i;
    for (i=0; i<count; ++i) {
        printf("%-20s %-30d %-10.2f \n", 
               arr[i].name,
               arr[i].age,
               arr[i].grade);
    }
    printf("=================================================================\n");
}

void searchStudent(const struct Student arr[], int count) {
	
	char searchNameStu[50];
	int compare, i;
	printf("Nhap vao ten sinh vien can tim: ");
	fgets(searchNameStu,sizeof(searchNameStu),stdin);
	searchNameStu[strcspn(searchNameStu,"\n")] = 0;
	fflush(stdin);
	
	for (i = 0; i < count; i++) {
        if (strcmp(arr[i].name, searchNameStu) == 0) {
            compare = 1;; 
        }
        if(compare==1) {
		printf("Da tim thay sinh vien %s voi tuoi la %d va diem TB la %.2f ",searchNameStu, arr[i].age, arr[i].grade);
		break;
		}
	
    }
	
	if(compare!=1) {
		printf("Khong tim thay sinh vien nao nhu the trong danh sach!!!");
	}
}

int main () {
	
	searchStudent(student1, count);
	
	printStudent(student1, count);
		
	return 0;
}
