#include<stdio.h>
#include<string.h>

struct PrivateInformation {
	char name[50];
	int age;
	long long phoneNumber;
};

int main () {
	struct PrivateInformation in4;
	
	printf("Nhap vao ho va ten cua ban: ");
	fgets(in4.name,sizeof(in4.name),stdin);
	in4.name[strcspn(in4.name, "\n")] = '\0';
	printf("\n");
	
	printf("Nhap vao tuoi cua ban: ");
	scanf("%d",&in4.age);
	printf("\n");
	
	printf("Nhap vao so dien thoai cua ban: ");
	scanf("%lld",&in4.phoneNumber);
	printf("\n");
	fflush(stdin);
	
	printf("Ho va ten: %s || Tuoi: %d || So dien thoai: %lld\n",in4.name, in4.age, in4.phoneNumber);

	
	return 0;
}
