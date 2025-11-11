#include <stdio.h>

int tinhTongMang(int arr[], int n) {
    int tong = 0, i;
    for (i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}

int main() {
    int n,i;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu trong mang:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int tong = tinhTongMang(arr, n);
    printf("Tong cac phan tu trong mang la: %d\n", tong);

    return 0;
}
