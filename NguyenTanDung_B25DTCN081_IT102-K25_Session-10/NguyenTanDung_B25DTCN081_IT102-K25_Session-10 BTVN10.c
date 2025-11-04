#include <stdio.h>

int main() {
    int n, x, i, j;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int a[n];
    for ( i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }


    int min = a[0];
    for ( i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    printf("\nSo nho nhat trong mang la: %d\n", min);


    for ( i = 0; i < n - 1; i++) {
        int minIndex = i;
        for ( j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    printf("\nMang sau khi sap xep tang dan: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }


    printf("\n\nNhap so can tim: ");
    scanf("%d", &x);

    int left = 0, right = n - 1, mid;
    int found = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == x) {
            found = 1;
            break;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found)
        printf("\nTim thay %d tai chi so %d.\n", x, mid);
    else
        printf("\nKhong tim thay %d trong mang.\n", x);

    return 0;
}

