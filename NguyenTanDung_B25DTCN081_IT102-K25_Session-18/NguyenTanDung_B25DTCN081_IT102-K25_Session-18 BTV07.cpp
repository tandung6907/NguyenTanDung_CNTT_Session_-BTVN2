#include <stdio.h>

void print_array(const int *arr, int size) {
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

void sort_array(int *arr, int size) {
    int i, j, temp;
    
    for (i=0 ; i<size-1; i++) {
        for (j=0; j<size-i-1 ; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j); 
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int unsorted_numbers[] = {50, 20, 80, 10, 40, 70, 30};
    int array_size = sizeof(unsorted_numbers) / sizeof(unsorted_numbers[0]);

    printf("Chuong trinh Sap xep mang voi con tro (Bubble sort)\n");
    printf("--- \n");

    printf("1. MANG BAN DAU:\n");
    print_array(unsorted_numbers, array_size);
    printf("--- \n");

    printf("2. Tien hanh goi ham sort_array de sap xep...\n");
    sort_array(unsorted_numbers, array_size);
    printf("--- \n");

    printf("3. MANG SAU KHI SAP XEP (Tang dan):\n");
    print_array(unsorted_numbers, array_size);

    return 0;
}
