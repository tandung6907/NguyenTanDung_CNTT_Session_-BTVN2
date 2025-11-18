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
    {2, "Ha Minh Duc", 18, "0902222222"},
    {3, "Vu Le Minh Hieu", 18, "0903333333"},
    {4, "Pham Ho Nam Khanh", 18, "0904444444"},
    {5, "Quach Tran Anh", 18, "0905555555"},
    {6, "Dang Viet Dung", 18, "0906666666"}
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

void inputNewStudent(struct Students *sv, int newId) {
    sv->id = newId;

    while (getchar() != '\n'); 

    printf("\n--- Nhap thong tin cho Sinh Vien ID: %d ---\n", sv->id);
    
    printf("Nhap ten cua sinh vien: ");
    fgets(sv->name, sizeof(sv->name), stdin);
    sv->name[strcspn(sv->name, "\n")] = 0; 

    printf("Nhap tuoi cua sinh vien: ");
    if (scanf("%d", &sv->age) != 1 || sv->age <= 0 || sv->age > 100) {
        printf("(!) Loi nhap lieu. Tuoi se duoc dat mac dinh la 18.\n");
        sv->age = 18;
        while (getchar() != '\n'); 
    }

    while (getchar() != '\n'); 

    printf("Nhap so dien thoai cua sinh vien: ");
    fgets(sv->phoneNumber, sizeof(sv->phoneNumber), stdin);
    sv->phoneNumber[strcspn(sv->phoneNumber, "\n")] = 0;
}

void insertStudent() {
    int position;
    struct Students new_student;

    if (student_count >= MAX_SIZE) {
        printf("\n(!) Loi: Mang da day, khong the them sinh vien moi.\n");
        return;
    }

    printf("\n--- CHEN SINH VIEN VAO VI TRI CHI DINH ---\n");
    printf("So luong sinh vien hien tai: %d\n", student_count);
    printf("Nhap vi tri muon chen (1 den %d): ", student_count + 1);

    if (scanf("%d", &position) != 1) {
        printf("(!) Loi nhap lieu. Vui long nhap mot so nguyen cho vi tri.\n");
        while (getchar() != '\n');
        return;
    }

    if (position < 1 || position > student_count + 1) {
        printf("(!) Loi: Vi tri nhap vao khong hop le.\n");
        return;
    }

    inputNewStudent(&new_student, getNextId());
    
    int index_to_insert = position - 1; 

    for (int i = student_count; i > index_to_insert; --i) {
        studentArray[i] = studentArray[i - 1];
    }

    studentArray[index_to_insert] = new_student;

    student_count++;
    
    printf("\n--> Da CHEN thanh cong sinh vien ID %d vao vi tri %d.\n", 
           new_student.id, position);
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

    insertStudent();
    
    printf("\n--- DANH SACH SINH VIEN SAU KHI CHEN ---\n");
    printStudents(studentArray, student_count);

    return 0;
}
