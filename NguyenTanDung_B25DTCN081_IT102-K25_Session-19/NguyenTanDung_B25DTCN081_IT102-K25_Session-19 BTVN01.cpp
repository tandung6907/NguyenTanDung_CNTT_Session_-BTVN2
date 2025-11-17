#include <stdio.h>

int findMax(int *arr, int n) {
    int max = *arr;  
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) { 
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int maxValue = findMax(arr, n);

    printf("Phan tu lon nhat la: %d\n", maxValue);

    return 0;
}

