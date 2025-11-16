#include <stdio.h>

int main() {
    
    int a = 10;
    int *ptr_a = &a;

    printf("Khai bao: int a = 10; int *ptr_a = &a;\n");
    printf("--- \n");

    
    printf("Cach 1: Su dung ten bien truc tiep (a) va toan tu dia chi (&)\n");
    printf("* **Gia tri cua bien a (su dung a):** %d\n", a);
    printf("* **Dia chi cua bien a (su dung &a):** %p\n", &a);

    printf("--- \n");

   
    printf("Cach 2: Su dung con tro (ptr_a) va toan tu giai tham chieu (*)\n");
    printf("* **Gia tri cua bien a (su dung *ptr_a - Giai tham chieu):** %d\n", *ptr_a);
    printf("* **Dia chi cua bien a (su dung ptr_a - Gia tri cua con tro):** %p\n", ptr_a);

    return 0;
}
