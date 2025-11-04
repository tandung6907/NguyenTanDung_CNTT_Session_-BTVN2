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


    for ( i = 0; i < n - 1; i++) {
        int swapped = 0;
        for ( j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
 
        if (swapped == 0) break;
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

