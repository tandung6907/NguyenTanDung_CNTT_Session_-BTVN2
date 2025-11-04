#include <stdio.h>

#define MAX 100

void hienThiMang(int a[], int n) {
	int i;
    if (n == 0) {
        printf("\nMang rong!\n");
        return;
    }
    printf("\nCac phan tu trong mang: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void themPhanTu(int a[], int *n, int x, int pos) {
	int i;
    if (*n >= MAX) {
        printf("\nMang da day, khong the them!\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("\nVi tri khong hop le!\n");
        return;
    }
    for ( i = *n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = x;
    (*n)++;
    printf("\nDa them %d vao vi tri %d.\n", x, pos);
}

void xoaPhanTu(int a[], int *n, int pos) {
	int i;
    if (pos < 0 || pos >= *n) {
        printf("\nVi tri khong hop le!\n");
        return;
    }
    for ( i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
    printf("\nDa xoa phan tu tai vi tri %d.\n", pos);
}

void capNhatPhanTu(int a[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("\nVi tri khong hop le!\n");
        return;
    }
    a[pos] = value;
    printf("\nDa cap nhat phan tu tai vi tri %d thanh %d.\n", pos, value);
}

void timKiemPhanTu(int a[], int n, int x) {
    int found = 0, i;
    printf("\nCac vi tri co phan tu %d: ", x);
    for ( i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found)
        printf("Khong tim thay!");
    printf("\n");
}

void sapXepMang(int a[], int n) {
	int i,j;
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
        if (swapped == 0)
            break;
    }
    printf("\nMang da duoc sap xep tang dan.\n");
}

int main() {
    int a[MAX], n = 0, choice, x, pos;

    do {
        printf("\n******************* Quan ly danh sach so nguyen *********************\n");
        printf("1. Them phan tu vao vi tri bat ky\n");
        printf("2. Xoa phan tu o vi tri bat ky\n");
        printf("3. Cap nhat gia tri tai vi tri bat ky\n");
        printf("4. Tim kiem phan tu trong mang\n");
        printf("5. Hien thi mang\n");
        printf("6. Sap xep mang (Bubble Sort)\n");
        printf("7. Thoat chuong trinh\n");
        printf("----------------------------------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                printf("Nhap vi tri can them (0 -> %d): ", n);
                scanf("%d", &pos);
                themPhanTu(a, &n, x, pos);
                break;

            case 2:
                printf("Nhap vi tri can xoa (0 -> %d): ", n - 1);
                scanf("%d", &pos);
                xoaPhanTu(a, &n, pos);
                break;

            case 3:
                printf("Nhap vi tri can cap nhat (0 -> %d): ", n - 1);
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &x);
                capNhatPhanTu(a, n, pos, x);
                break;

            case 4:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                timKiemPhanTu(a, n, x);
                break;

            case 5:
                hienThiMang(a, n);
                break;

            case 6:
                sapXepMang(a, n);
                hienThiMang(a, n);
                break;

            case 7:
                printf("\nThoat chuong trinh. Tam biet!\n");
                break;

            default:
                printf("\nLua chon khong hop le. Vui long nhap lai!\n");
        }
    } while (choice != 7);

    return 0;
}

