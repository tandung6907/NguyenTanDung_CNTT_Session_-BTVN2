#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void display_array(const int *arr, int size) {
    if (size == 0) {
        printf("   (Mang rong)\n");
        return;
    }
    printf("   Mang hien tai (So phan tu: %d): [", size);
    int i;
    for (i=0 ; i<size ; i++) {
        printf("%d", *(arr + i)); 
        if (i < size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void add_element(int *arr, int *size_ptr, int value, int index) {
    int size = *size_ptr;
    int i;

    if (size >= MAX_SIZE) {
        printf("\nLoi: Mang da day.\n");
        return;
    }
    if (index<0 || index>size) {
        printf("\nLoi: Chi muc chen (%d) khong hop le (0 den %d).\n", index, size);
        return;
    }

    for (i=size ; i>index ; i--) {
        arr[i] = arr[i - 1]; 
    }
    *(arr + index) = value; 
    (*size_ptr)++; 

    printf("\nDa them %d tai vi tri %d thanh cong.\n", value, index);
}

void remove_element(int *arr, int *size_ptr, int index) {
    int size = *size_ptr;

    if (size == 0) {
        printf("\nLoi: mang rong khong the xoa.\n");
        return;
    }
    if (index<0 || index>=size) {
        printf("\nLoi: Chi muc xoa (%d) khong hop le (0 den %d)\n", index, size - 1);
        return;
    }
    int removed_value = *(arr + index);
    int i;
    for (i=index ; i<size-1 ; i++) {
        arr[i] = arr[i + 1];
    }
    (*size_ptr)--;

    printf("\nDa xoa phan tu %d tai vi tri %d thanh cong.\n", removed_value, index);
}

void update_element(int *arr, int size, int value, int index) {
    if (size == 0) {
        printf("\nLoi: mang rong khong the cap nhat.\n");
        return;
    }
    if (index<0 || index>=size) {
        printf("\nLoi: Chi muc cap nhat (%d) khong hop le (0 den %d).\n", index, size - 1);
        return;
    }
    int old_value = *(arr + index);
    *(arr + index) = value;

    printf("\nDa cap nhat phan tu %d tai vi tri %d thanh cong.\n", index, old_value, value);
}

int main() {

    int list[MAX_SIZE];
    int current_size = 0;
    add_element(list, &current_size, 11, 0);
    add_element(list, &current_size, 22, 1);
    add_element(list, &current_size, 33, 2);

    int choice;
    int value, index;

    do {
        printf("\n\n==============================================\n");
        printf("***************** QUAN LY DANH SACH SO NGUYEN ****************\n");
        printf("1. Them phan tu vao vi tri bat ky\n");
        printf("2. Xoa phan tu tai vi tri bat ky\n");
        printf("3. Cap nhat phan tu tai vi tri bat ky\n");
        printf("4. Hien thi mang\n");
        printf("5. Thoat chuong trinh\n");
        printf("==============================================\n");
        printf("Vui long nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- THEM PHAN TU ---\n");
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri (chi muc) can chen (0 den %d): ", current_size);
                scanf("%d", &index);
                add_element(list, &current_size, value, index); 
                break;
            
            case 2:
                printf("\n--- XOA PHAN TU ---\n");
                if (current_size == 0) {
                    printf("\nLoi: Mang rong khong the xoa.\n");
                    break;
                }
                printf("Nhap vi tri (chi muc) can xoa (0 den %d): ", current_size - 1);
                scanf("%d", &index);
                remove_element(list, &current_size, index);
                break;
            
            case 3:
                printf("\n--- CAP NHAT GIA TRI ---\n");
                if (current_size == 0) {
                    printf("\nLoi: Mang rong khong the cap nhat.\n");
                    break;
                }
                printf("Nhap vi tri (chi muc) can cap nhat (0 den %d): ", current_size - 1);
                scanf("%d", &index);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                update_element(list, current_size, value, index); 
                break;

            case 4:
                printf("\n--- HIEN THI MANG ---\n");
                display_array(list, current_size); 
                break;

            case 5:
                printf("\nBan da thoat chuong trinh!! Hen gap lai!!\n");
                exit(0);
                break;

            default:
                printf("\nLua chon cua ban khong hop le vui long chon tu 1 den 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
