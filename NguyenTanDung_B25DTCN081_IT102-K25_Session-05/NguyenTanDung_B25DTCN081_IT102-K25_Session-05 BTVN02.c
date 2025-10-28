#include<stdio.h>
int main(){
	
	int a, b;
	printf("Enter an integer a: ");
	scanf("%d",&a);
	printf("Enter an integer b: ");
	scanf("%d",&b);
	if(a==0 && b==0){
		printf("Equation with infinite solutions");
	}else if(a==0 && b!=0){
		printf("Equation with no solution");
	}else{
		float x=-b/a;
		printf("The equation has only one solution: %.1f",x);
	}
	return 0;
}
