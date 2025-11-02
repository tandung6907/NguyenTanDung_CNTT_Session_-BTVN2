#include<stdio.h>
int main(){
	
	int i,numbers[5]={1,2,3,4,5};
	
	for (i=0;i<5;i++){
		if(numbers[i]%2==0){
			printf("The even number of elements in the array is: %d\n",numbers[i]);
		}else{
		printf("The elements are not even in number in the array: %d\n",numbers[i]);
	}
}
		printf("\n");
		
	return 0;
}
