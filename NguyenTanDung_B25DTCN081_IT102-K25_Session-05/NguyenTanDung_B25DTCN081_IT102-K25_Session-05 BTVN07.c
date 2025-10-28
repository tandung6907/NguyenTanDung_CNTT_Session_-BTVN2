#include<stdio.h>
#include<ctype.h>


int main() {
    char ch;

    printf("Enter any character: ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z') {
        printf("Corresponding uppercase letters: %c\n", ch - 32); 
    } 
    else if (ch >= 'A' && ch <= 'Z') {
        printf("Corresponding lowercase letters: %c\n", ch + 32);  
    } 
    else {
        printf("Not letters!!!\n");
    }




    return 0;
}

