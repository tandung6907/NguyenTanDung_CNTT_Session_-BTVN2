#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "lap trinh c co ban"; 
    int freq[256] = {0};            
    int i;

    printf("Chuoi da khai bao: %s\n", str);

  
    for (i = 0; i < strlen(str); i++) {
        unsigned char ch = str[i];
        freq[ch]++;
    }

    printf("\nCac ky tu va so lan xuat hien:\n");

 
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}

