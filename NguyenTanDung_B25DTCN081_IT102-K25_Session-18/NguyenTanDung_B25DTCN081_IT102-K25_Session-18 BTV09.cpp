#include <stdio.h>
#define MAX_SIZE 10

void print_array(const int *arr, int size) {
    printf("Mang hien tai (kich thuoc %d): [", size);
    int i;
    for (i=0 ; i<size ; i++) {
        printf("%d", arr[i]);
        if (i<size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void add_element(int *arr, int *current_size_ptr, int new_value, int index) {
    int current_size = *current_size_ptr;

    if (current_size >= MAX_SIZE) {
        printf("\Loi: Khong the tham phan tu. Mang da day (MAX_SIZE = %d).\n", MAX_SIZE);
        return;
    }

    if (index<0 || index>current_size) {
        printf("\Loi: Chi muc chen (%d) khong hop le. Vui long chen tu 0 den %d.\n", index, current_size);
        return;
    }
    printf("   Dang dich chuyen %d phan tu tu chi muc %d den %d...\n", current_size - index, index, current_size - 1);
    int i;
    for (i=current_size ; i>index ; i--) {
        *(arr+i) = *(arr+i-1);
    }
    *(arr+index) = new_value;
    (*current_size_ptr)++;

    printf("\nDa them phan tu thanh cong!\n");
    printf("   Gia tri: %d | Vi tri chen: Chi muc %d\n", new_value, index);
}

int main() {
    printf("Chuong trinh them phan tu mang voi con tro\n");
    printf("--- \n");

    int my_array[MAX_SIZE] = {10, 20, 40, 50};
    int current_elements = 4;
    int value_to_add = 30;
    int position_to_insert = 2; 
    
    printf("1. TRANG THAI BAN DAU:\n");
    print_array(my_array, current_elements);
    printf("--- \n");

    printf("2. Goi ham add_element de chen %d vao chi muc %d.\n", value_to_add, position_to_insert);
    add_element(my_array, &current_elements, value_to_add, position_to_insert);
    printf("--- \n");

    printf("3. TRANG THAI SAU KHI THEM MOI:\n");
    print_array(my_array, current_elements);
    
    value_to_add = 99;
    position_to_insert = 0;
    printf("\n4. Goi ham add_element de chen %d vao chi muc %d.\n", value_to_add, position_to_insert);
    add_element(my_array, &current_elements, value_to_add, position_to_insert);
    printf("--- \n");
    
    printf("5. TRANG THAI SAU LAN THEM THU HAI:\n");
    print_array(my_array, current_elements);

    return 0;
}
