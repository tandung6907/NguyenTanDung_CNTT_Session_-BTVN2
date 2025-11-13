#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, length;
    int isPalindrome = 1; 

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(str,sizeof(str),stdin); 

    length = strlen(str);

    if (str[length-1] == '\n') {
        str[length-1] = '\0';
        length--;
    }

    for (i=0 ; i<length/2 ; i++) {
        if (str[i]!=str[length-i-1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("La palindrome\n");
    else
        printf("Khong phai palindrome\n");

    return 0;
}

