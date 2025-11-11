#include <stdio.h>


int removeDuplicates(int arr[], int size) {
    if (size == 0)
        return 0;

    int newSize = 0,i,j;

    for (i = 0; i < size; i++) {
        int isDuplicate = 0;


        for (j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

 
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize;
}

int main() {
    int n,i;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu trong mang:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int newSize = removeDuplicates(arr, n);

    printf("\nMang sau khi loai bo phan tu trung lap:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSo luong phan tu sau khi loai trung: %d\n", newSize);

    return 0;
}
