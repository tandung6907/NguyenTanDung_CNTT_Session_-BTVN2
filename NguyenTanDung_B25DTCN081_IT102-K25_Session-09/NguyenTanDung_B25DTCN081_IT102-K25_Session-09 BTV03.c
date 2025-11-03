#include<stdio.h>

int main() {
   
   int i, number;

   printf("Enter the number of elements in the array: ");
   scanf("%d",&number);
   
   int numbers[number];
   for ( i=0 ; i<number ; i++){
   	printf("Enter the %d element:",i);
   	scanf("%d",&numbers[i]);
   }
   printf("The elements in the array are:");
   for ( i=0 ; i<number ; i++ ){
   	printf("%d ",numbers[i]);
   	
   }
   
    return 0;
}

