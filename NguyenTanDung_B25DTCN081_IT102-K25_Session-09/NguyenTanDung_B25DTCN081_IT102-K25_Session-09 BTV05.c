#include <stdio.h>
int main() {
	
    int number, i;
    int evencnt = 0, oddcnt = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &number);
    
    int numbers[number];
    for(i = 0 ; i < number ; i++) {
        printf("Enter the %d element : ", i);
        scanf("%d", &numbers[i]);
    }    

    printf("Even numbers: ");
    for(i = 0 ; i < number ; i++) {
        if(numbers[i]%2==0){
        	 printf("%d ", numbers[i]);
		}     
    }
    printf("\nOdd numbers: ");
    for(i = 0 ; i < number ; i++) {
        if(numbers[i]%2!=0){
        	printf("%d ", numbers[i]);
		}   
    }

    for(i=0 ; i<number ; i++) {
        if(numbers[i]%2==0){
        	evencnt++;
		}else{
			oddcnt++;
		}
    }
    printf("\nThere are %d even numbers and %d odd numbers.\n", evencnt, oddcnt);

    return 0;
}

	
	
	

