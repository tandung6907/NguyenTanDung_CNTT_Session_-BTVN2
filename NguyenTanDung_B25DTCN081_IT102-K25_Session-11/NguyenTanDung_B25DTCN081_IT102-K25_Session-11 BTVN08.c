#include <stdio.h>

int main() {
    int arr[] = {4, 2, 4, 3, 2, 4, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i,j;

    int max_count = 0; 
    int most_frequent;

    for (i = 0; i < n; i++) {
        int count = 0;

        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            most_frequent = arr[i];
        }

    }

    printf("Phan tu xuat hien nhieu nhat: %d\n", most_frequent);
    printf("So lan xuat hien: %d\n", max_count);

    return 0;
}

