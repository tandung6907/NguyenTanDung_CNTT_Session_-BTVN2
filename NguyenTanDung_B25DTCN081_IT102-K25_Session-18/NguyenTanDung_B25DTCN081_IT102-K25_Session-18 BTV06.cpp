#include <stdio.h>

int find_element_index(const int *arr, int size, int target_value) {
    printf("   Bat dau tim kiem gia tri %d...\n", target_value);
    
    int i;
    for (i=0 ; i<size ; i++) {
        if (*(arr+i) == target_value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int scores[] = {85, 92, 78, 95, 88, 70, 92};
    int array_size = sizeof(scores) / sizeof(scores[0]);
    
    int search_value = 95;
    int search_value_not_found = 50;

    printf("Chuong trinh tim kiem phan tu mang bang con tro\n");
    printf("--- \n");

    printf("Mang da khai bao: {85, 92, 78, 95, 88, 70, 92}\n");
    printf("Kich thuoc mang: %d phan tu\n", array_size);
    printf("--- \n");

    printf("1. THU TIM KIEM: %d\n", search_value);
    int index_found = find_element_index(scores, array_size, search_value);

    if (index_found != -1) {
        printf("\nKET QUA: Tim thay gia tri %d tai vi tri chi muc: **%d**\n", search_value, index_found);
    } else {
        printf("\nKET QUA: Khong tim thay gia tri %d trong mang.\n", search_value);
    }

    printf("--- \n");

    printf("2. THU TIM KIEM: %d\n", search_value_not_found);
    int index_not_found = find_element_index(scores, array_size, search_value_not_found);

    if (index_not_found != -1) {
        printf("\nKET QUA: Tim thay gia tri %d tai vi tri chi muc: **%d**\n", search_value_not_found, index_not_found);
    } else {
        printf("\nKET QUA: Khong tim thay gia tri %d trong mang.\n", search_value_not_found);
    }

    return 0;
}
