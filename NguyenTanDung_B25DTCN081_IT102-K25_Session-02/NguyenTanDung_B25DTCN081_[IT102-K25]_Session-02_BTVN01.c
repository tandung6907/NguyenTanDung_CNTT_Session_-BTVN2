#include <stdio.h>

int main() {
    // Kieu short: so nguyen nho, thuong 2 byte (pham vi khoang -32768 den 32767)
    short a = -120;

    // Kieu int: so nguyen thong thuong, thuong 4 byte
    int b = 12345;

    // Kieu long: so nguyen lon hon int, kich thuoc tuy may tinh (4 hoac 8 byte)
    long c = 123456789L;

    // Kieu long long: so nguyen rat lon, thuong 8 byte
    long long d = 123456789012345LL;

    // Kieu unsigned short: so nguyen khong dau, chi luu gia tri duong (0 -> 65535)
    unsigned short e = 60000;

    // Kieu unsigned int: so nguyen khong dau, thuong 4 byte
    unsigned int f = 4000000000U;

    // Kieu unsigned long: so nguyen khong dau lon hon int
    unsigned long g = 3000000000UL;

    // Kieu unsigned long long: so nguyen khong dau rat lon (toi da ~18 ty ty)
    unsigned long long h = 18446744073709551615ULL;

    // Kieu char: luu mot ky tu, thuong 1 byte
    char ch = 'A';

    // In ra cac gia tri
    printf("short a = %hd\n", a);
    printf("int b = %d\n", b);
    printf("long c = %ld\n", c);
    printf("long long d = %lld\n", d);
    printf("unsigned short e = %hu\n", e);
    printf("unsigned int f = %u\n", f);
    printf("unsigned long g = %lu\n", g);
    printf("unsigned long long h = %llu\n", h);
    printf("char ch = %c\n", ch);

    return 0;
}

