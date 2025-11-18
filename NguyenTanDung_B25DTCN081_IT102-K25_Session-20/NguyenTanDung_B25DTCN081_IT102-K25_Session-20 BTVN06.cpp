#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
#define INITIAL_COUNT 6

struct Students {
    int id;              
    char name[50];          
    int age;              
    char phoneNumber[15]; 
};

struct Students studentArray[MAX_SIZE] = {
    {1, "Nguyen Tan Dung", 18, "0901111111"},
    {2, "Ha Duc Minh", 18, "0902222222"},
    {3, "Vu Le Minh Hieu", 18, "0903333333"},
    {4, "Pham Ho Nam Khanh", 18, "0904444444"},
    {5, "Quach Tran Anh", 18, "0905555555"},
    {6, "Dang Viet Dung", 18, "0906666666"},
};

int student_count = INITIAL_COUNT;

int getNextId() {
    int maxId = 0;
    for (int i = 0; i < student_count; ++i) {
        if (studentArray[i].id > maxId) {
            maxId = studentArray[i].id;
        }
    }
    return maxId + 1;
}

void addStudent() {
    if (student_count >= MAX_SIZE) {
        printf("\n(!) Loi: Mang da day, khong the them sinh vien moi.\n");
        return;
    }
    
    struct Students* new_sv = &studentArray[student_count];
    
    new_sv->id = getNextId();
    
    while (getchar() != '\n'); 

    printf("\n--- THEM SINH VIEN MOI (ID: %d) ---\n", new_sv->id);
    
    printf("Nhap ten cua sinh vien: ");
    fgets(new_sv->name, sizeof(new_sv->name), stdin);
    new_sv->name[strcspn(new_sv->name, "\n")] = 0; 

    printf("Nhap tuoi cua sinh vien: ");
    if (scanf("%d", &new_sv->age) != 1 || new_sv->age <= 0 || new_sv->age > 100) {
        printf("(!) Loi nhap lieu. Tuoi se duoc dat mac dinh la 18.\n");
        new_sv->age = 18;
        while (getchar() != '\n'); 
    }

    while (getchar() != '\n'); 

    printf("Nhap so dien thoai cua sinh vien: ");
    fgets(new_sv->phoneNumber, sizeof(new_sv->phoneNumber), stdin);
    new_sv->phoneNumber[strcspn(new_sv->phoneNumber, "\n")] = 0;

    student_count++;
    printf("\n--> Da them sinh vien ID %d vao vi tri cuoi cung (%d) thanh cong.\n", 
           new_sv->id, student_count);
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

    addStudent();
    
    printf("\n--- DANH SACH SINH VIEN SAU KHI THEM MOI ---\n");
    printStudents(studentArray, student_count);

    return 0;
}
