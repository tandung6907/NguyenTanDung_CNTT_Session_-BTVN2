#include<stdio.h>
#include<string.h>

struct PrivateInformation {
	char name[50] = "Nguyen Tan Dung";
	int age = 18;
	char phoneNumber[15];
};

int main () {
	
	struct PrivateInformation in4;
	
	strcpy(in4.phoneNumber, "0964859095");

	printf("Ho va ten: %s || Tuoi: %d || So dien thoai: %s\n",in4.name, in4.age, in4.phoneNumber);

	
	return 0;
}

