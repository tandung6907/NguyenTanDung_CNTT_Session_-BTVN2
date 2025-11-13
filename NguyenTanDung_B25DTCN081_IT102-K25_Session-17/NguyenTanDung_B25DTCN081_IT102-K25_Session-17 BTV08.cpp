#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PASS_LENGTH 100 
#define MIN_LENGTH 8 

int checkPassword(const char *password) {
    size_t len = strlen(password);

    if (len < MIN_LENGTH) {
        printf("Loi: Do dai phai it nhat %d ky tu.\n", MIN_LENGTH);
        return 0; 
    }

    int upperCase = 0;
    int lowerCase = 0;
    int number = 0;
    int specialCharacters = 0;

    for (size_t i = 0; i < len; i++) {
        char characters = password[i];

        if (isupper(characters)) {
            upperCase = 1;
        } else if (islower(characters)) {
            lowerCase = 1;
        } else if (isdigit(characters)) {
            number = 1;
        } else {
            specialCharacters = 1;
        }

        if (upperCase && lowerCase && number && specialCharacters) {
            break;
        }
    }
    
    if (upperCase && lowerCase && number && specialCharacters) {
    	printf("\nKet qua: **Hop le**\n");
        return 1;
    } else {
        printf("\nKet qua: **Khong hop le**\n");
        return 0;
    }
}

int main() {
    char password[MAX_PASS_LENGTH];
    
    printf("Nhap mat khau (toi da %d ky tu):\n", MAX_PASS_LENGTH - 1);
    
    if (fgets(password, MAX_PASS_LENGTH, stdin) == NULL) {
        printf("Loi khi nhap.\n");
        return 1;
    }
    password[strcspn(password, "\n")] = 0; 

    if (checkPassword(password)) {
        printf("Mau khau hop le - Ban dat mau khau thanh cong");
    } else {
        printf("Loi: Thieu mot hoac nhieu loai ky tu.\n");
    }

    return 0;
}
