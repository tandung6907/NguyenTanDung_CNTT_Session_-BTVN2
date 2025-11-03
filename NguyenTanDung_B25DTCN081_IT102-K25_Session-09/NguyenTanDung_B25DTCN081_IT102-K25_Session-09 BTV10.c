#include <stdio.h>

int main() {
    int arr[] = {2, 3, 5, 3, 2, 5, 2, 3}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements
    int count, maxCount = 0;
    int i,j,k;

    // Find the maximum frequency
    for ( i = 0; i < n; i++) {
        count = 0;
        for ( j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > maxCount)
            maxCount = count;
    }

    // Print all elements with the highest frequency (avoid duplicates)
    printf("Elements that appear the most (%d times): ", maxCount);
    for ( i = 0; i < n; i++) {
        count = 0;
        for ( j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        // Print only if count == maxCount and not printed before
        int alreadyPrinted = 0;
        for ( k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                alreadyPrinted = 1;
                break;
            }
        }

        if (count == maxCount && !alreadyPrinted)
            printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

