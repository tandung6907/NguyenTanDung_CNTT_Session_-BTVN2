#include<stdio.h>
#include<math.h>
int main(){
	//khai baoo bien n
	int n,a,b;
	//cho nguoi dung nhap vao n
	printf("Enter the positive integer n: ");
	scanf("%d",&n);
	//di tim cac cap so
	for(a=0;pow(a,3)<=n;a++){
		for(b=0;pow(b,3)<=n;b++){
			if(pow(a,3)+pow(b,3)==n){
				printf("(%d,%d)\n",a,b);
				
			}
		}
	}
	
	
	
	
	
	
	
	return 0;
}
