#include <stdio.h>

void update_element(int *arr, int new_value, int index, int size) {
    if (index<0 || index>=size) {
        printf("\ Loi: Chi muc (%d) khong hop le. Vui long chon tu 0 den %d.\n", index, size - 1);
        return;
    }
    *(arr + index) = new_value; 

    printf("\Da cap nhat thanh cong!\n");
    printf("   Vi tri cap nhat: Chi muc %d\n", index);
    printf("   Gia tri moi: %d\n", new_value);
}

print_array(int *arr, int size) {
    printf("[");
    int i;
    for (i=0 ; i<size ; i++) {
        printf("%d", arr[i]);
        if (i<size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}


int main() {
    int data[] = {100, 200, 300, 400, 500};
    int data_size = sizeof(data) / sizeof(data[0]);

    int position_to_update = 2;
    int value_to_set = 999;  

    printf("Chuong trinh cap nhat phan tu mang bang con tro\n");
    printf("--- \n");

    printf("1. MANG BAN DAU:\n");
    print_array(data, data_size);
    printf("--- \n");

    printf("2. Thuc hien cap nhat:\n");
    printf("   - Can cap nhat vi tri chi muc: %d\n", position_to_update);
    printf("   - Gia tri moi la: %d\n", value_to_set);

	update_element(data, value_to_set, position_to_update, data_size);
	printf("--- \n");

    printf("3. MANG SAU KHI CAP NHAT:\n");
    print_array(data, data_size);

    return 0;
}
