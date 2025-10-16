#include <stdio.h>
int main(){
	// khai bao 2 bien chieu dai va chieu rong 
	int Chieu_dai, Chieu_rong;
	float Chu_vi, Dien_tich;
	// nhap 2 so tu chieu dai va chieu rong
	printf("nhap chieu dai: ");
	scanf("%d",&Chieu_dai);
	
	printf("nhap chieu rong: ");
	scanf("%d", &Chieu_rong);
	
	// tinh dien tich va chu vi 
	
	Dien_tich = (float)Chieu_dai * Chieu_rong;
	
	Chu_vi = (float)(Chieu_dai + Chieu_rong)*2;
	
	printf("Vay chu vi hinh chu nhat la: %f \n ", Chu_vi);
	printf("Vay dien tich cua hinh chu nhat la: %f \n", Dien_tich);
	return 0; 
}
