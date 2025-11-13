#include<stdio.h>
#include<string.h>

int main () {
	
	char str01[200];
	printf("Nhap vao chuoi thu nhat: ");
	fgets(str01,100,stdin);
	printf("\nChuoi thu nhat la: %s\n",str01);
	
	char str02[100];
	printf("Nhap vao chuoi thu hai: ");
	fgets(str02,100,stdin);
	printf("\nChuoi thu hai la: %s\n",str02);
	
		
	strcat(str01,str02);
	printf("Chuoi sau khi duoc noi la: %s",str01);
	
	return 0;
}
