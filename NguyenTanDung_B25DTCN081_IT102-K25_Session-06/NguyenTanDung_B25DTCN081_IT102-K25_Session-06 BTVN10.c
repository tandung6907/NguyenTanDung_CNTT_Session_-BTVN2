#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
    long n;
    printf("Enter an integer: ");
    scanf("%ld", &n);

    if (n < 0) {
        n = -n;
        printf("The digits of the number are: - ");
    } else {
        printf("The digits of the number are: ");
    }

    char str[20];
    sprintf(str, "%ld", n);

    for ( i = 0; str[i] != '\0'; i++) {
        printf("%c ", str[i]);
    }

    printf("\n");
    return 0;
}

