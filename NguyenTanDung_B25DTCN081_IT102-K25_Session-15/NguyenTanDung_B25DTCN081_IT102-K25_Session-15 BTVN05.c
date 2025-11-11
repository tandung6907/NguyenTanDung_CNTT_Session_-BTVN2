#include <stdio.h>

void timPhanTuXuatHienNhieuNhat(int arr[], int n, int *phanTu, int *soLan) {
    int maxCount = 0,i,j;

    for (i = 0; i < n; i++) {
        int count = 0;

        for (j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            *phanTu = arr[i];
        }
    }

    *soLan = maxCount;
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

    int phanTu, soLan;
    timPhanTuXuatHienNhieuNhat(arr, n, &phanTu, &soLan);

    printf("Phan tu xuat hien nhieu nhat la: %d (xuat hien %d lan)\n", phanTu, soLan);

    return 0;
}
