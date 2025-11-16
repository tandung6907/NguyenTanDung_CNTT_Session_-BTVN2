#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 

void reverse_string_ptr(const char *source_str, char *destination_str) {
	
    int len = strlen(source_str);
    const char *p_source = source_str;
    char *p_dest = destination_str;
    p_source += len - 1; 
    int i;
    for (i=0 ; i<len ; i++) {
        *p_dest = *p_source;
        p_source--;
        p_dest++;
    }
    *p_dest = '\0';
}

int main() {

    char inputString[MAX_SIZE];
    char reverseString[MAX_SIZE];

    printf("Chuong trinh dao nguoc chuoi voi con tro\n");
    printf("--- \n");

    printf("Vui long nhap mot chuoi toi da %d ky tu:\n> ", MAX_SIZE - 1);
    fgets(inputString, MAX_SIZE, stdin);
    inputString[strcspn(inputString, "\n")] = 0;

    reverse_string_ptr(inputString, reverseString);
    printf("--- \n");

    printf("Chuoi ban dau (inputString): **%s**\n", inputString);
    printf("Chuoi dao nguoc (reverseString): **%s**\n", reverseString);
    printf("\Dao nguoc chuoi thanh cong bang con tro.\n");

    return 0;
}
