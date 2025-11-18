#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
#define INITIAL_COUNT 8

struct Students {
    int id;             
    char name[50];        
    int age;              
    char phoneNumber[15];  
};

struct Students studentArray[MAX_SIZE] = {
    {1, "Nguyen Tan Dung", 20, "0901111111"},
    {2, "Ha Minh Duc", 22, "0902222222"},
    {3, "Vu Le Minh Hieu", 19, "0903333333"},
    {4, "Pham Ho Nam Khanh", 21, "0904444444"},
    {5, "Quach Tran Anh", 20, "0905555555"},
    {6, "Dang Viet Dung", 20, "0905555555"},
    {7, "Tran Bao Hung", 20, "0905555555"},
	{8, "Nguyen Minh Hien", 20, "0905555555"}
	
};

int student_count = INITIAL_COUNT;

int findStudentIndexById(int id) {
    for (int i = 0; i < student_count; ++i) {
        if (studentArray[i].id == id) {
            return i; 
        }
    }
    return -1; 
}

void deleteStudent() {
    int search_id;
    int index_to_delete;
    
    while (getchar() != '\n'); 

    printf("\n--- XOA SINH VIEN ---\n");
    printf("Nhap ID sinh vien can xoa: ");
    
    if (scanf("%d", &search_id) != 1) {
        printf("(!) Loi nhap lieu. Vui long nhap mot so nguyen cho ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    index_to_delete = findStudentIndexById(search_id);

    if (index_to_delete == -1) {
        printf("\n(!) KHONG TIM THAY sinh vien voi ID %d de xoa.\n", search_id);
    } else {

        for (int i = index_to_delete; i < student_count - 1; ++i) {
            studentArray[i] = studentArray[i + 1];
        }

        student_count--;
        
        printf("\n--> Da XOA thanh cong sinh vien co ID %d.\n", search_id);
    }
}

void printStudents(const struct Students arr[], int count) {
    if (count == 0) {
        printf("\nKhong co sinh vien nao trong danh sach.\n");
        return;
    }
    
    printf("\n=================================================================\n");
    printf("           DANH SACH SINH VIEN HIEN TAI (%d)             \n", count);
    printf("=================================================================\n");
    
    printf("%-5s %-30s %-10s %s\n", "ID", "Ten Sinh Vien", "Tuoi", "SDT");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < count; ++i) {
        printf("%-5d %-30s %-10d %s\n", 
               arr[i].id, 
               arr[i].name, 
               arr[i].age, 
               arr[i].phoneNumber);
    }
    printf("=================================================================\n");
}

int main() {
    
    printf("Danh sach sinh vien ban dau (so luong: %d):\n", student_count);
    printStudents(studentArray, student_count);

    deleteStudent();
    
    printf("\n--- DANH SACH SINH VIEN SAU KHI XOA ---\n");
    printStudents(studentArray, student_count);

    return 0;
}
