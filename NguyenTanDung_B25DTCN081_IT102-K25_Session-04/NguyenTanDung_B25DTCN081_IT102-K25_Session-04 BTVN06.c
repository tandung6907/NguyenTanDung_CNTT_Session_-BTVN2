#include<stdio.h>
int main() {
    float chiSoCu, chiSoMoi, soDien, tienDien;
    printf("Nhap chi so cu (kWh): ");
    scanf("%f", &chiSoCu);
    printf("Nhap chi so moi (kWh): ");
    scanf("%f", &chiSoMoi);
    if (chiSoMoi < chiSoCu) {
        printf("Chi so moi phai lon hon chi so cu!\n");
        return 0;
    }
    soDien = chiSoMoi - chiSoCu;
    if (soDien <= 50)
        tienDien = soDien * 10000;
    else if (soDien <= 100)
        tienDien = 50 * 10000 + (soDien - 50) * 15000;
    else if (soDien <= 150)
        tienDien = 50 * 10000 + 50 * 15000 + (soDien - 100) * 20000;
    else if (soDien <= 200)
        tienDien = 50 * 10000 + 50 * 15000 + 100 * 20000 + (soDien - 200) * 25000;
    else
        tienDien = 50 * 10000 + 50 * 15000 + 100 * 20000 + 100 * 25000 + (soDien - 300) * 30000;
    printf("\nSo dien tieu thu: %.0f kWh\n", soDien);
    printf("Tien dien phai tra: %.0f VND\n", tienDien);
    return 0;
}

