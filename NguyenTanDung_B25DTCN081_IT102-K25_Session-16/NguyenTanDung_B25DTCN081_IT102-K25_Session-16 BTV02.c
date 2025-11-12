#include <stdio.h>

int main() {
	
	int i;
    char str[] = "Hello, World!";
    for (i=0 ; str[i]!='\0' ; i++) {
        printf("%c ",str[i]);
    }
    printf("\n");
    return 0;
}

