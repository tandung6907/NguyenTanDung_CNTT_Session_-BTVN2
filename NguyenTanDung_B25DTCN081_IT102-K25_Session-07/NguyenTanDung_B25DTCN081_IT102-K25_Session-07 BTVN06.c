#include<stdio.h>
int main(){
	int number, reversenumber=0,i;
	printf("Enter the number:");
	scanf("%d",&number);
	
	while(number!=0){
		i = number%10;
		reversenumber = reversenumber*10+i;
		number/=10;		
	}
	
    printf("The reverse number is: %d",reversenumber);
	

	return 0;
}
