#include <stdio.h>
#define MAX_SIZE 10

void print_array(const int *arr, int size) {
    printf("Mang hien tai (So phan tu %d): [", size);
    int i;
    for (i=0 ; i<size ; i++) {
        printf("%d", arr[i]);
        if (i<size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void remove_element(int *arr, int *current_size_ptr, int index) {
    int current_size = *current_size_ptr;
    int i;
    if (index<0 || index>=current_size) {
        printf("\Loi: chi muc xoa (%d) khong hop le. Vui long chen tu 0 den %d.\n", index, current_size - 1);
        return;
    }
    printf("   Dang dich chuyen cac phan tu co chi muc %d den cuoi mang...\n", index + 1);
    for (i=index ; i<current_size-1 ; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    (*current_size_ptr)--;

    printf("\Da xoa phan tu tai chi muc %d thanh cong!\n", index);
}
    
int main() {
    printf("Chuong trinh xoa phan tu mang voi con tro\n");
    printf("--- \n");

    int my_array[MAX_SIZE] = {10, 20, 30, 40, 50, 60};
    int current_elements = 6; 
    int position_to_remove = 2; 
    
    printf("1. TRANG THAI BAN DAU:\n");
    print_array(my_array, current_elements);
    printf("--- \n");

    printf("2.Goi ham remove_element de xoa phan tu tai chi muc %d.\n", position_to_remove);
    remove_element(my_array, &current_elements, position_to_remove);
    printf("--- \n");

    printf("3. TRANG THAI SAU KHI XOA:\n");
    print_array(my_array, current_elements);
    
    position_to_remove = 0;
    printf("\n4. Goi ham remove_element de xoa phan tu tai chi muc %d.\n", position_to_remove);
    remove_element(my_array, &current_elements, position_to_remove);
    printf("--- \n");
    
    printf("5. TRANG THAI SAU KHI XOA LAN HAI:\n");
    print_array(my_array, current_elements);

    return 0;
}
