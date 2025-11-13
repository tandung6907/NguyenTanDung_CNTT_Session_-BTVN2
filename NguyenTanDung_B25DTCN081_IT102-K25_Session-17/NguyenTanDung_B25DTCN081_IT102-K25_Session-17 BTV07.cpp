#include <stdio.h>
#include <string.h>

int main() {
    
    char A[100];
    char B[100];
    
    printf("Nhap chuoi A (co the chua khoang trang): ");
    if (fgets(A,100,stdin) == NULL) {
        printf("Loi khi nhap chuoi A.\n");
        return 1;
    }
    A[strcspn(A, "\n")] = 0; 

    printf("Nhap chuoi B: ");
    if (fgets(B,100,stdin) == NULL) {
        printf("Loi khi nhap chuoi B.\n");
        return 1;
    }
    B[strcspn(B, "\n")] = 0;
    
    printf("Kiem tra B co phai chuoi con cua A khong: \n");
    if (strstr(A, B) != NULL) {
        printf("Co\n");
    } else {
        printf("Khong\n");
    }

    return 0;
}

