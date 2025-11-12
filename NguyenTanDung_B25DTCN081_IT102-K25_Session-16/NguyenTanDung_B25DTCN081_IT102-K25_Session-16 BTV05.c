#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Lap trinh C co ban";  
    int count = 0;                     
    int i;

    printf("Chuoi da khai bao: \"%s\"\n", str);


    for (i = 0; i < strlen(str); i++) {
        if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') &&
            (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n')) {
            count++;
        }
    }

    printf("So tu trong chuoi la: %d\n", count);

    return 0;
}

