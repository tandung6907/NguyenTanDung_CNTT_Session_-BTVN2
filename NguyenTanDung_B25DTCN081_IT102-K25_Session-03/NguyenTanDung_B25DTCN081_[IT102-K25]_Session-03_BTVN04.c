#include <stdio.h>
#include <math.h>

int main(){
	
	float Toan;
	float Van;
	float TiengAnh;
	float Tong;
	
	printf(" Nhap diem mon Toan: ");
	scanf("%f", &Toan);
	
	printf(" Nhap diem mon Van: ");
	scanf("%f", &Van);
	
	printf(" Nhap diem mon Tieng Anh: ");
	scanf("%f", &TiengAnh);
	
    Tong = (float) Toan + Van + TiengAnh;
	float TrungBinh = (float) Tong / 3 ;
	
	printf( "Tong ba mon la: %.2f \n", Tong);
	printf("Trung binh ba mon la: %.2f\n", TrungBinh);
	
	return 0; 
	
}
