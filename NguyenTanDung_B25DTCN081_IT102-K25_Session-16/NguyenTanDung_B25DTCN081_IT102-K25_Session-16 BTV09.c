#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "lap trinh c co ban"; 
    char ch;                    
    int i, j;

    printf("Chuoi ban dau: %s\n", str);
    printf("Nhap mot ky tu can xoa: ");
    scanf("%c", &ch);


    j = 0; 
    for (i=0 ; i< strlen(str) ; i++) {
        if (str[i] != ch) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';

    printf("Chuoi sau khi xoa ky tu '%c': %s\n", ch, str);

    return 0;
}

