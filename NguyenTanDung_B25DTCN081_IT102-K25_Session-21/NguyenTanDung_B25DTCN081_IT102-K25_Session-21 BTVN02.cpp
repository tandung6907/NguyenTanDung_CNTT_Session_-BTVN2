#include<stdio.h>
#include<string.h>

struct Students {
	
	char nameStudent[50];
	int age;
	float grade;
	
};

int main () {
	
	struct Students student1;
	
	printf("Nhap vao ten cua sinh vien: ");
	fgets(student1.nameStudent, sizeof(student1.nameStudent), stdin);
	student1.nameStudent[strcspn(student1.nameStudent, "\n")] = 0;
	
	printf("Nhap vao tuoi cua sinh vien: ");
	scanf("%d",&student1.age);
	getchar();
	
	printf("Nhap vao diem trung binh cua sinh vien: ");
	scanf("%f",&student1.grade);
	
	printf("Ten Sinh Vien: %s || Tuoi Cua Sinh Vien: %d || Diem TB: %.1f", student1.nameStudent, student1.age, student1.grade);
	
	return 0;
}
