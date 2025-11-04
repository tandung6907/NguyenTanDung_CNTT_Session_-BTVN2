#include<stdio.h>

int main() {
    int num,i,j;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &num);
    int arr[num];
    for ( i = 0; i < num; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    for ( i = 0; i < num - 1; i++) {
        int swapped = 0;

        for ( j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }

    printf("\nMang sau khi sap xep tang dan la: ");
    for ( i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}


	

