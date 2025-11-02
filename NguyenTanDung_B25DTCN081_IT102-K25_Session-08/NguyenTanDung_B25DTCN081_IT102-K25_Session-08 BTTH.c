#include <stdio.h>
#define MAX 100

void displayMenu() {
    printf("\n——————————————— Integer List Management ———————————————\n");
    printf("1. Add an element at any position\n");
    printf("2. Delete an element at any position\n");
    printf("3. Update value at any position\n");
    printf("4. Search for an element in the array\n");
    printf("5. Display the array\n");
    printf("0. Exit the program\n");
    printf("----------------------------------------------------------------\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, pos, value, found, i;

    printf("Enter the number of initial elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          
            case 1:
                if (n >= MAX) {
                    printf("Array is full. Cannot add more elements.\n");
                    break;
                }
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
               
                for (i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                printf("Element added successfully!\n");
                break;

           
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }
                for (i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully!\n");
                break;

            
            case 3:
                printf("Enter position to update (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter new value: ");
                scanf("%d", &value);
                arr[pos] = value;
                printf("Value updated successfully!\n");
                break;

           
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Value found at position %d\n", i);
                        found = 1;
                    }
                }
                if (!found)
                    printf("Value not found in the array.\n");
                break;

          
            case 5:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 0:
                printf("Exiting program... Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

