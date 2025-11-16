#include <stdio.h>

void print_array_elements(int *arr_ptr, int size) {
    printf("--- \n");
    printf(" Cac phan tu cua mang duoc in bang con tro:\n");
    int i;
    
    for (i=0 ; i<size ; i++) {
        printf("Phan tu thu %d: %d\n", i+1, *(arr_ptr + i));
    }
}

int main() {

    int numbers[] = {10, 20, 30, 40, 50, 60};
    
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Chuong trinh in mang voi con tro\n");
    printf("--- \n");
    printf("Mang duoc khai bao: {10, 20, 30, 40, 50, 60}\n");
    printf("Kich thuoc mang: %d phan tu\n", array_size);
    
    print_array_elements(numbers, array_size); 

    printf("--- \n");
    printf("In mang hoan tat.\n");

    return 0;
}
