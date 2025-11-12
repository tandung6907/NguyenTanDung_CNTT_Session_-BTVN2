#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "lap trinh C co ban";
    char chr;                             
    int count = 0;      

    printf("Chuoi da khai bao: %s\n", str);

	int i;
    printf("Nhap mot ky tu bat ky: ");
    scanf("%c", &chr);
    for (i=0 ; i<strlen(str) ; i++) {
        if (str[i] == chr) {
            count++;
        }
    }

    printf("Ky tu '%c' xuat hien %d lan trong chuoi.\n", chr, count);

    return 0;
}

