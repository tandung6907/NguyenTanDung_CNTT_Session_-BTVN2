#include<stdio.h>
int main () {
	
	char str[68];
	printf("Moi ban nhap vao mot chuoi bat ky: ");
	fgets(str, 68, stdin);
	str[strcspn(str, "\n")] = '\0';
	printf("%s",str);
	printf("\n");
	
	int length = strlen(str);
	printf("Do dai cua chuoi vua nhap la: %d",length);
	
	return 0;
}
