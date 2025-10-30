#include<stdio.h>
#include<math.h>
int main(){
	//khai baoo bien 
	int number ,a,b;
	//cho nguoi dung nhap vao number
	printf("Enter the positive integer number: ");
	scanf("%d",&number);
	//di tim cac cap so
	for(a=0;pow(a,3)<=number;a++){
		for(b=0;pow(b,3)<=numbber;b++){
			if(pow(a,3)+pow(b,3)==number){
				printf("(%d,%d)\n",a,b);
				
			}
		}
	}
	
	
	
	
	
	
	
	return 0;
}

