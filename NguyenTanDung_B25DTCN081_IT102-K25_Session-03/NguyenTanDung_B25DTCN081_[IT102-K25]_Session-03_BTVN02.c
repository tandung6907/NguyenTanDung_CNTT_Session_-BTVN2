#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    // Nhap nhiet do theo do Celsius
    printf("Nhap nhiet do (do C): ");
    scanf("%f", &celsius);

    // Chuyen doi sang do Fahrenheit
    fahrenheit = celsius * 9 / 5 + 32;

    // In ket qua ra man hi0nh
    printf("%.2f do C = %.2f do F\n", celsius, fahrenheit);

    return 0;
}

