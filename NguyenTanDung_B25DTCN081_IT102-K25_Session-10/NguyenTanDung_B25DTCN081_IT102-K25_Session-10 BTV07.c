#include <stdio.h>

int main() {
    int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int a[n];
    printf("Nhap cac phan tu (theo thu tu tang dan):\n");
    for ( i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nNhap so can tim: ");
    scanf("%d", &x);

    int left = 0, right = n - 1;
    int found = 0, mid;

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

