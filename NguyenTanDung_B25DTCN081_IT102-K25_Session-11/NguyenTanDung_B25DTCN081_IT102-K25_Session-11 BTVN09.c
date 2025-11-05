#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i,j,k;

    printf("Mang ban dau: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;  ) {
            if (arr[i] == arr[j]) {

                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }

    printf("\nMang sau khi loai bo trung lap: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

