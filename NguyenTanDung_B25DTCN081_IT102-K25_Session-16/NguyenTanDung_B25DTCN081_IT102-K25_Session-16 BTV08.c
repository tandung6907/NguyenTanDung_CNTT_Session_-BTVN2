#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[] = "lap trinh c co ban";
    int i;

    printf("Chuoi ban dau: %s\n", str);

    if (isalpha(str[0])) {
        str[0] = toupper(str[0]);
    }

    for (i = 1; i < strlen(str); i++) {
        if (str[i - 1] == ' ' && isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    printf("Chuoi sau khi viet hoa: %s\n", str);

    return 0;
}

