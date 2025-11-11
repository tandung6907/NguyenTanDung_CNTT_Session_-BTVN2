#include <stdio.h>

// Binary Search
int timKiemNhiPhan(int arr[], int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;         
        else if (arr[mid] < x)
            left = mid + 1;    
        else
            right = mid - 1;   
    }

    return -1;
}

int main() {
    int n, x, i;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu trong mang (da sap xep tang dan):\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int kq = timKiemNhiPhan(arr, n, x);

    if (kq != -1)
        printf("Phan tu %d duoc tim thay tai vi tri index = %d\n", x, kq);
    else
        printf("Khong tim thay phan tu %d trong mang.\n", x);

    return 0;
}
