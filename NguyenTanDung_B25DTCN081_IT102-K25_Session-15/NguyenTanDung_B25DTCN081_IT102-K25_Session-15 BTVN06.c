#include <stdio.h>

void hoanDoi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble Sort
void bubbleSort(int arr[], int n) {
	int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                hoanDoi(&arr[j], &arr[j + 1]);
            }
        }
    }
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

    bubbleSort(arr, n);

    printf("Mang sau khi sap xep tang dan la:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
