#include <stdio.h>

int main() {
    int a, b; // Khai bao hai bien so nguyen
    int tong; // Bien de luu ket qua tong
    int hieu; // bien hieu cua 2 so
    int tich; // bien tich cua 2 so
    float thuong; // bien thuong cua 2 so

    // Nhap hai so tu ban phim
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);

    printf("Nhap so thu hai: ");
    scanf("%d", &b);

    // Tinh 
    
    tong = a + b;
    hieu = a - b;
    tich = a*b;
    thuong = (float)a/b;
    
    // Hien thi ket qua
    printf("Tong cua %d va %d la: %d\n", a, b, tong);
    printf("hieu cua %d va %d la: %d\n", a, b, hieu);
    printf("Tich cua %d va %d la: %d\n", a, b, tich);
    // dieu kien khi thuc hien phep chia
    if (b !=0){
    	printf("Thuong cua %d va %d la: %f \n", a, b, thuong);
	}else{
		printf("loi phep tinh (khong the chia cho 0) ");
	}
    return 0;
}
