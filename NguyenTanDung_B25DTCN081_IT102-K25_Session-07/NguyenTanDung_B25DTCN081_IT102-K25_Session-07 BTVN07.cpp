#include<stdio.h>

int main(){
	
	int a, b, i, j;
	int isPrime;
	
	do{
	printf("Enter the intervals [a; b]: ",a,b);
		scanf("%d  %d",&a,&b);
		if(a<0||b<0){
			printf("That aren't interger position number!!\n");
		}else{
			if(a<b){
				break;
			}
			printf("The next number cannot be greater than the previous number!\n");
		}
	}while(1);
	for(i=a;i<=b;i++){
		if(i<2){
			continue;
		}
		isPrime = 1;
		for(j=2;j<i;j++){
			if(i%j==0){
				isPrime = 0;
				break;
			}
		}if(isPrime == 1){
			printf("%d \t",i);
		}
	}


    
	return 0;
}
