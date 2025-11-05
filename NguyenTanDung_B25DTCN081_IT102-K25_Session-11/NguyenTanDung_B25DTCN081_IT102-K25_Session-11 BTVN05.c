#include <stdio.h>
#include <string.h>

int main() {

    char arr[5][50] = {"apple", "banana", "cherry", "mango", "orange"};
    char target[50];
    int found = 0,i;

    printf("Nhap chuoi can tim: ");
    fgets(target, sizeof(target), stdin);

    target[strcspn(target, "\n")] = '\0';

    for ( i = 0; i < 5; i++) {
        if (strcmp(arr[i], target) == 0) {
            printf("Chuoi '%s' duoc tim thay tai vi tri %d.\n", target, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay chuoi '%s' trong mang.\n", target);
    }

    return 0;
}

