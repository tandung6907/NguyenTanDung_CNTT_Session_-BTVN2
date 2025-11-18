#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
#define NUM_STUDENTS_TO_INPUT 5

struct Students {
    int id;                 
    char name[50];       
    int age;                
    char phoneNumber[15];  
};

void inputStudent(struct Students arr[], int index, int start_id) {
	
    arr[index].id = start_id + index; 

    while (getchar() != '\n'); 

    printf("\nNhap thong tin cho ID Sinh Vien: %d \n", arr[index].id);
    
    printf("Nhap ten cua sinh vien: ");
    fgets(arr[index].name, sizeof(arr[index].name), stdin);
    arr[index].name[strcspn(arr[index].name, "\n")] = 0; 

    printf("Nhap tuoi cua sinh vien: ");
    if (scanf("%d", &arr[index].age) != 1) {
        printf("(!) Loi nhap lieu. Tuoi se duoc dat la 0.\n");
        arr[index].age = 0;
        while (getchar() != '\n'); 
    }

    while (getchar() != '\n'); 

    printf("Nhap so dien thoai cua sinh vien: ");
    fgets(arr[index].phoneNumber, sizeof(arr[index].phoneNumber), stdin);
    arr[index].phoneNumber[strcspn(arr[index].phoneNumber, "\n")] = 0;
}


void printStudents(const struct Students arr[], int count) {
    if (count == 0) {
        printf("\nKhong co sinh vien nao de in.\n");
        return;
    }
    
    printf("\n=================================================================\n");
    printf("           DANH SACH %d SINH VIEN DA NHAP               \n", count);
    printf("=================================================================\n");
    
    printf("%-5s %-5s %-30s %-10s %s\n", "STT", "ID", "Ten Sinh Vien", "Tuoi", "SDT");
    printf("-----------------------------------------------------------------\n");
	int i;
    for (i = 0; i < count; ++i) {
        printf("%-5d %-5d %-30s %-10d %s\n", 
               i + 1, 
               arr[i].id, 
               arr[i].name, 
               arr[i].age, 
               arr[i].phoneNumber);
    }
    printf("=================================================================\n");
}

int main() {
	
    struct Students studentArray[MAX_SIZE]; 

    int student_count = 0; 
    
    printf(" NHAP THONG TIN CHO %d SINH VIEN (Mang co the chua %d phan tu) \n", 
           NUM_STUDENTS_TO_INPUT, MAX_SIZE);
    
    for (int i = 0; i < NUM_STUDENTS_TO_INPUT; ++i) {
        inputStudent(studentArray, i, 1); 
        student_count++;
    }

    printStudents(studentArray, student_count);

    return 0;
}
