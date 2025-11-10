#include <stdio.h>

// ===================== KHAI BAO HAM =====================
void nhapMang(int arr[], int *n);
void inMang(int arr[], int n);
void themPhanTu(int arr[], int *n, int pos, int value);
void suaPhanTu(int arr[], int n, int pos, int value);
void xoaPhanTu(int arr[], int *n, int pos);
void sapXepTangDan(int arr[], int n);
void sapXepGiamDan(int arr[], int n);
int timKiemTuyenTinh(int arr[], int n, int x);
int timKiemNhiPhan(int arr[], int n, int x);

// ===================== CHUONG TRINH CHINH =====================
int main() {
    int arr[100];
    int n = 0;
    int choice;

    do {
        printf("\n==================== MENU ====================\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra cac phan tu\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("==============================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                nhapMang(arr, &n);
                break;
            }
            case 2: {
                inMang(arr, n);
                break;
            }
            case 3: {
                int pos, value;
                printf("Nhap vi tri muon them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri muon them: ");
                scanf("%d", &value);
                themPhanTu(arr, &n, pos, value);
                break;
            }
            case 4: {
                int pos, value;
                printf("Nhap vi tri muon sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                suaPhanTu(arr, n, pos, value);
                break;
            }
            case 5: {
                int pos;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &pos);
                xoaPhanTu(arr, &n, pos);
                break;
            }
            case 6: {
                char c;
                printf("\n--- SAP XEP ---\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Chon (a/b): ");
                scanf(" %c", &c);
                if (c == 'a' || c == 'A')
                    sapXepGiamDan(arr, n);
                else if (c == 'b' || c == 'B')
                    sapXepTangDan(arr, n);
                else
                    printf("Lua chon khong hop le!\n");
                break;
            }
            case 7: {
                char c;
                int x;
                printf("\n--- TIM KIEM ---\n");
                printf("a. Tuyen tinh\n");
                printf("b. Nhi phan\n");
                printf("Chon (a/b): ");
                scanf(" %c", &c);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                if (c == 'a' || c == 'A') {
                    int kq = timKiemTuyenTinh(arr, n, x);
                    if (kq == -1)
                        printf("Khong tim thay %d trong mang.\n", x);
                    else
                        printf("Tim thay %d tai vi tri %d.\n", x, kq);
                } else if (c == 'b' || c == 'B') {
                    int kq = timKiemNhiPhan(arr, n, x);
                    if (kq == -1)
                        printf("Khong tim thay %d trong mang (co the mang chua duoc sap xep tang dan).\n", x);
                    else
                        printf("Tim thay %d tai vi tri %d.\n", x, kq);
                } else
                    printf("Lua chon khong hop le!\n");
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

// ===================== CAC HAM CHUC NANG =====================

// 1. Nhap mang
void nhapMang(int arr[], int *n) {
	int i;
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for ( i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// 2. In mang
void inMang(int arr[], int n) {
	int i;
    printf("Cac phan tu trong mang: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 3. Them phan tu
void themPhanTu(int arr[], int *n, int pos, int value) {
	int i;
    if (pos < 0 || pos > *n || *n >= 100) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for ( i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
    printf("Da them thanh cong!\n");
}

// 4. Sua phan tu
void suaPhanTu(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    arr[pos] = value;
    printf("Da sua thanh cong!\n");
}

// 5. Xoa phan tu
void xoaPhanTu(int arr[], int *n, int pos) {
	int i;
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for ( i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
    printf("Da xoa thanh cong!\n");
}

// 6a. Sap xep tang dan
void sapXepTangDan(int arr[], int n) {
	int i, j;
    for ( i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    printf("Da sap xep tang dan!\n");
}

// 6b. Sap xep giam dan
void sapXepGiamDan(int arr[], int n) {
	int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    printf("Da sap xep giam dan!\n");
}

// 7a. Tim kiem tuyen tinh
int timKiemTuyenTinh(int arr[], int n, int x) {
	int i;
    for ( i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// 7b. Tim kiem nhi phan (Yeu cau mang duoc sap xep tang dan) 
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

