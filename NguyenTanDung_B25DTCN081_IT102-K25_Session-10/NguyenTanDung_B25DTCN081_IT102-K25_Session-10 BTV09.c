#include <stdio.h>
#include <string.h>

#define MAX 100


typedef struct {
    int maSP;
    float giaBan;
} SanPham;

int main() {
    SanPham ds[MAX];
    int n, i, j;

    printf("Nhap so luong san pham: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%d", &ds[i].maSP);
        printf("Gia ban: ");
        scanf("%f", &ds[i].giaBan);
    }
    
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (ds[j].maSP > ds[j + 1].maSP) {
                SanPham temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }

    int maTim;
    printf("\nNhap ma san pham can tim: ");
    scanf("%d", &maTim);

    int left = 0, right = n - 1, mid;
    int found = -1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (ds[mid].maSP == maTim) {
            found = mid;
            break;
        } else if (ds[mid].maSP < maTim) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found != -1) {
        printf("\nTim thay san pham co ma %d:\n", maTim);
        printf("Ma SP: %d\tGia ban: %.2f\n", ds[found].maSP, ds[found].giaBan);
    } else {
        printf("\nKhong tim thay san pham co ma %d.\n", maTim);
    }

    for ( i = 0; i < n - 1; i++) {
        int swapped = 0;
        for ( j = 0; j < n - i - 1; j++) {
            if (ds[j].giaBan > ds[j + 1].giaBan) {
                SanPham temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }

    printf("\nDanh sach san pham sau khi sap xep theo gia ban tang dan:\n");
    for ( i = 0; i < n; i++) {
        printf("Ma SP: %d\tGia ban: %.2f\n", ds[i].maSP, ds[i].giaBan);
    }

    return 0;
}

