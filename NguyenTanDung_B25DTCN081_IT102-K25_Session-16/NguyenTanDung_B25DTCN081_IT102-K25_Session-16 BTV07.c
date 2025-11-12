#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[] = "N.tan_dung06092007@@!#$%^&*()";

    int letters = 0;
    int digits = 0; 
    int special = 0; 
    int i;

    printf("Chuoi da khai bao: %s\n", str);

  
    for (i=0 ; i<strlen(str) ; i++) {
        if (isalpha(str[i])) {
            letters++;
        } else if (isdigit(str[i])) {
            digits++;
        } else if (!isspace(str[i])) { 
            special++;
        }
    }

    printf("So chu cai: %d\n", letters);
    printf("So chu so: %d\n", digits);
    printf("So ky tu dac biet: %d\n", special);

    return 0;
}

