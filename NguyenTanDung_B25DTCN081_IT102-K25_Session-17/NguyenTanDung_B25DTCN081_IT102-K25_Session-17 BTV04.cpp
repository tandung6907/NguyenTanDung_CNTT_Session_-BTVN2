#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char chr;                    
    int i, j;
    
	printf("Moi ban nhap mot chuoi ky tu bat ky: ");
	fgets(str,100,stdin);
    printf("Chuoi ban dau: %s\n", str);
    
    printf("Nhap mot ky tu can xoa: ");
    scanf("%c",&chr);

    j = 0; 
    for (i=0 ; i< strlen(str) ; i++) {
        if (str[i] != chr) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';

    printf("Chuoi sau khi xoa ky tu '%c': %s\n", chr, str);

    return 0;
}
