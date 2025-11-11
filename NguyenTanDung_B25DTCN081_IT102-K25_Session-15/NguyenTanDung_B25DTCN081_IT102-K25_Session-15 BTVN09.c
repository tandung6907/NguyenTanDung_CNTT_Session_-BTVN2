#include <stdio.h>

int findLeastFrequent(int arr[], int size) {
    int minCount = size + 1;
    int leastElement = arr[0],i,j;

    
    for (i = 0; i < size; i++) {
        int count = 0;


        for (j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

 
        if (count < minCount) {
            minCount = count;
            leastElement = arr[i];
        }
    }

    return leastElement;
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

    int result = findLeastFrequent(arr, n);
    printf("\nPhan tu xuat hien it nhat trong mang la: %d\n", result);

    return 0;
}
