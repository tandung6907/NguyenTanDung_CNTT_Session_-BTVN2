#include<stdio.h>
#include<math.h>

int main(){
	int count = 0, number, x;
	
	printf("Enter the number n: ");
	scanf("%d",&number);
	printf("Enter the x:");
	scanf("%d",&x);
	
	while(number>0){
		int i = number%10;
		if(i==x){
			count++;
		}
	number/=10;
	}
	printf("number of times %d appeared: %d ",x,count);
	
	
	return 0;
}
