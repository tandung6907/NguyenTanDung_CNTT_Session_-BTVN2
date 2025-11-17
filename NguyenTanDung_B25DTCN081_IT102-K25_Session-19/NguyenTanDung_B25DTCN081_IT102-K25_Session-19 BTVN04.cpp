#include <stdio.h>

int countValue(int *arr, int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == x) { 
            count++;
        }
    }
    return count;
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

    int x;
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);

    int result = countValue(arr, n, x);

    printf("So lan xuat hien cua %d trong mang la: %d\n", x, result);

    return 0;
}

