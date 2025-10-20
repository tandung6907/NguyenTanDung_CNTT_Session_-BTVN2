#include <stdio.h>

int main() {
    char name[50]; 

    printf("Nhap ten cua ban: ");
    fgets(name, sizeof(name), stdin); 

    printf("Xin Chao %s <33", name); 

    return 0;
}

