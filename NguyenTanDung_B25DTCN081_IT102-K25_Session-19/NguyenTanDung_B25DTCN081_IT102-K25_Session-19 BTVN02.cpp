#include <stdio.h>

void countEvenOdd(int *arr, int n, int *even, int *odd) {
    *even = 0;
    *odd = 0;

    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
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

    int evenCount, oddCount;

    countEvenOdd(arr, n, &evenCount, &oddCount);

    printf("So phan tu chan: %d\n", evenCount);
    printf("So phan tu le: %d\n", oddCount);

    return 0;
}

