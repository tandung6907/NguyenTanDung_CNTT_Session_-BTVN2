#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[] = "Lap trinh C 2025!";  
    int count = 0, i;                    

    printf("Chuoi da khai bao: %s\n", str);

    for (i=0 ; i<strlen(str) ; i++) {
        if (isalpha(str[i])) { 
            count++;
        }
    }

    printf("So ky tu la chu cai trong chuoi la: %d\n", count);

    return 0;
}

