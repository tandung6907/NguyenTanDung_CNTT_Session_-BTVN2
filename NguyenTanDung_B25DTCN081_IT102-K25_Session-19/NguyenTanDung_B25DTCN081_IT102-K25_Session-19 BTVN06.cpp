#include <stdio.h>

void copyArray(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) {
        *(dest + i) = *(src + i); 
    }
}

int main() {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    int A[n], B[n];

    printf("Nhap cac phan tu mang A:\n");
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    copyArray(A, B, n);

    printf("Mang B sau khi sao chep la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;
}

