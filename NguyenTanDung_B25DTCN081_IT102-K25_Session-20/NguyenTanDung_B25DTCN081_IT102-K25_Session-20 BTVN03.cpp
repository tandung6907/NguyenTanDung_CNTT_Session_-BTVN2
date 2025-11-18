#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students {
    char name[50];          
    int age;                
    char phoneNumber[15];  
};

#define ARRAY_SIZE 5


void inputStudent(struct Students *sv) {
	
    while (getchar() != '\n'); 

    printf("Nhap Ten: ");
    fgets(sv->name, sizeof(sv->name), stdin);
    sv->name[strcspn(sv->name, "\n")] = 0; 

    printf("Nhap Tuoi: ");
    if (scanf("%d", &sv->age) != 1) {
        printf("Loi nhap lieu. Tuoi se duoc dat la 0.\n");
        sv->age = 0;
        while (getchar() != '\n'); 
    }

    while (getchar() != '\n'); 

    printf("Nhap So Dien Thoai: ");
    fgets(sv->phoneNumber, sizeof(sv->phoneNumber), stdin);
    sv->phoneNumber[strcspn(sv->phoneNumber, "\n")] = 0;
}


void printStudents(const struct Students arr[], int size) {
    printf("\n==========================================================\n");
    printf("          DANH SACH SINH VIEN DA NHAP (C)                 \n");
    printf("==========================================================\n");
    printf("%-5s %-30s %-10s %s\n", "STT", "Ten Sinh Vien", "Tuoi", "SDT");
    printf("----------------------------------------------------------\n");
	int i;
    for (i = 0; i < size; i++) {
        printf("%-5d %-30s %-10d %s\n", 
               i + 1, 
               arr[i].name, 
               arr[i].age, 
               arr[i].phoneNumber);
    }
    printf("==========================================================\n");
}

int main() {
	
    struct Students studentArray[ARRAY_SIZE]; 

    printf("--- NHAP THONG TIN CHO %d SINH VIEN ---\n", ARRAY_SIZE);
    
    int i;
    for (i = 0; i < ARRAY_SIZE; ++i) {
        printf("\n Nhap thong tin cho Sinh Vien thu %d:\n", i + 1);
        inputStudent(&studentArray[i]); 
    }

    printStudents(studentArray, ARRAY_SIZE);

    return 0;
}
