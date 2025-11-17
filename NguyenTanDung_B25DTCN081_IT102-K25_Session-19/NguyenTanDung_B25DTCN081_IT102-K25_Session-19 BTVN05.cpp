#include <stdio.h>

int compareArrays(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) != *(b + i)) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    int arr1[n], arr2[n];

    printf("Nhap cac phan tu mang 1:\n");
    for (int i = 0; i < n; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }

    printf("Nhap cac phan tu mang 2:\n");
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    int result = compareArrays(arr1, arr2, n);

    if (result == 1)
        printf("Hai mang giong nhau.\n");
    else
        printf("Hai mang khac nhau.\n");

    return 0;
}

