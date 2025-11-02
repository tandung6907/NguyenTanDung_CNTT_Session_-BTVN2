#include<stdio.h>
int main(){
	
	int numbers[5]={1,2,3,4,5}, i;
	printf("The previous numbers changed are:\t");
	for (i = 0; i < 5; i++) {
        printf("%d\t", numbers[i]);
    }
    printf("\n");

	printf("The following numbers change:   \t");
	for ( i=0 ; i<5 ; i++){
		if (numbers[i]%2==0){
			numbers[i]+=3;
			printf("%d\t",numbers[i]);
		}else{
			numbers[i]+=2;
			printf("%d\t",numbers[i]);
		}
	}

	return 0;
}
