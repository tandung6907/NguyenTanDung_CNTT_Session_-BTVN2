#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Hello World"; 
    int length = strlen(str);

    printf("Chuoi goc: %s\n", str);
    
    int i;
    printf("Chuoi dao nguoc: ");
    for (i=length-1 ; i>=0 ; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}

