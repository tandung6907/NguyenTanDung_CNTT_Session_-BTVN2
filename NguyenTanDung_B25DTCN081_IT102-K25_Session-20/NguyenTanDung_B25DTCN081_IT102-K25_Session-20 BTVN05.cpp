#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
#define INITIAL_COUNT 7

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
    {7, "Nguyen Minh Hien", 18, "0907777777"},
};

int student_count = INITIAL_COUNT;

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

struct Students* findStudentById(int id) {
    for (int i = 0; i < student_count; ++i) {
        if (studentArray[i].id == id) {
            return &studentArray[i]; 
        }
    }
    return NULL; 
}

void editStudentInfo() {
    int search_id;
    struct Students* foundStudent = NULL;
    
    while (getchar() != '\n'); 

    printf("\n--- CHINH SUA THONG TIN SINH VIEN ---\n");
    printf("Nhap ID sinh vien can chinh sua: ");
    
    if (scanf("%d", &search_id) != 1) {
        printf("(!) Loi nhap lieu. Vui long nhap mot so nguyen cho ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    foundStudent = findStudentById(search_id);

    if (foundStudent == NULL) {
        printf("\n(!) KHONG TIM THAY sinh vien voi ID %d.\n", search_id);
    } else {
        printf("\nDa tim thay sinh vien ID %d: Ten hien tai: %s, Tuoi hien tai: %d\n", 
               foundStudent->id, foundStudent->name, foundStudent->age);

        while (getchar() != '\n'); 

        printf("\nNhap Ten moi (Bo qua neu khong muon thay doi): ");
        char newName[50];
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = 0; 
        
        if (strlen(newName) > 0) {
            strcpy(foundStudent->name, newName);
        }

        printf("Nhap Tuoi moi (Nhap 0 hoac gia tri bat ky khac de bo qua): ");
        int newAge = 0;
        
        if (scanf("%d", &newAge) == 1 && newAge > 0 && newAge < 100) {
            foundStudent->age = newAge;
        } else {
             printf("Gia tri Tuoi khong hop le hoac bi bo qua. Tuoi van giu nguyen.\n");
        }
        
        while (getchar() != '\n'); 
        
        printf("\n--> CHINH SUA HOAN TAT cho sinh vien ID %d.\n", foundStudent->id);
    }
}

int main() {
    
    printf("Menu sinh vien ban dau:\n");
    printStudents(studentArray, student_count);

    editStudentInfo();
    
    printf("\n--- DANH SACH SINH VIEN SAU KHI CHINH SUA ---\n");
    printStudents(studentArray, student_count);

    return 0;
}
