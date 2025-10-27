#include<stdio.h>
int main() {
	
	char name[50];
    int birthday, age;
    float avegoal;
    const int NOW_YEAR = 2025;
    char learning[20];
    
    
    printf("Nhap ten sinh vien: ");
    fgets(name, sizeof(name), stdin);
    printf("Nhap nam sinh: ");
    scanf("%d", &birthday);
    printf("Nhap diem trung binh: ");
    scanf("%f", &avegoal);
    
    
    if (birthday <= 1900 || birthday > NOW_YEAR) {
        printf("Nam sinh khong hop le.\n");
        return 0;
}
    age = NOW_YEAR - birthday;
    if (avegoal < 5.0)
        sprintf(learning, "Yeu");
    else if (avegoal < 6.5)
        sprintf(learning, "Trung binh");
    else if (avegoal < 8.0)
        sprintf(learning, "Kha");
    else if (avegoal < 9.0)
        sprintf(learning, "Gioi");
    else
        sprintf(learning, "Xuat Sac");
    printf("\n--- Thong tin sinh vien ---\n");
    printf("Ho va Ten: %s sai dep chieuu. \n", name);
    printf("Nam sinh: %d\n", birthday);
    printf("Tuoi: %d\n", age);
    printf("Diem trung binh: %.2f\n", avegoal);
    printf("Hoc luc: %s\n", learning);

    if (age >= 18)
        printf("Sinh vien da du tuoi di tu.\n");
    else
        printf("Sinh vien chua du tuoi di tu.\n");

    return 0;
}

