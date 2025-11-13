#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char word[50];
    char maxWord[50];
    int i = 0, j = 0, maxLen = 0, len = 0;

    printf("Nhap vao chuoi bat ky: ");
    fgets(str,sizeof(str),stdin);

    int n = strlen(str);

    while (i<=n) {
        if (str[i]!=' '&&str[i]!='\0') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';
            len = strlen(word);

            if (len>maxLen) {
                maxLen = len;
                strcpy(maxWord, word);
            }
            j = 0;
        }
        i++;
    }

    printf("Tu dai nhat: %s\n", maxWord);
    printf("Do dai: %d\n", maxLen);

    return 0;
}

