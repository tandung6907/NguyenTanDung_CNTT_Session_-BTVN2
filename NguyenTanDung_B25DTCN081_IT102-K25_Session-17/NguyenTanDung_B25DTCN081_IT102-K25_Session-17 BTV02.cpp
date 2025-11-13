#include<stdio.h>
#include<string.h>
#include<ctype.h>

void displaymenu() {
	printf("==============MENU===========");
	printf("\n1.Nhap 1 --> In ra chuoi duoc in ra voi cac ky tu duoc viet hoa hoan toan");
	printf("\n2.Nhap 2 --> In ra chuoi duoc in ra voi cac ky tu duoc viet thuong hoan toan");
	printf("\n3.Thoat\n");
}

char convertToUppercase(char str[]) {
	int i;
	if (isalpha(str[0])) {
        str[0] = toupper(str[0]);
    }
    for (i=1 ; i<strlen(str); i++) {
            str[i] = toupper(str[i]);
    }
    printf("Chuoi sau khi duoc thay doi la: %s",str);
}

char convertToLowercase(char str[]) {
	int i;
	if (isalpha(str[0])) {
        str[0] = tolower(str[0]);
    }
    for (i=1 ; i<strlen(str); i++) {
            str[i] = tolower(str[i]);
    }
    printf("Chuoi sau khi duoc thay doi la: %s",str);
}

int main () {
	char str[100];
	printf("Nhap vao 1 chuoi bat ky: ");
	fgets(str,100,stdin);
	
	printf("Chuoi ban dau la: %s",str);
	printf("\n");
	int choice;
	do {
		displaymenu();
		printf("Nhap vao su lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice) {
			case 1:
				convertToUppercase(str);
				printf("\n");
				break;	
			case 2:
				convertToLowercase(str);
				printf("\n");
				break;	
			case 3:
				printf("Ban da thoat chuong trinh! Hen gap lai<3");
				printf("\n");
				break;	
			default:
				printf("Vui long nhap lua chon tu 1 den 3!!!");
				printf("\n");
				break;		
		}
	}while(choice!=3);
	
	return 0;
}
