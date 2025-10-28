#include<stdio.h>


int main(){
	int avegoal;
	printf("Enter points:");
	scanf("%d",&avegoal);
	
	
	if(avegoal<0||avegoal>10){
		printf("Please enter a score from 1 to 10:\n");
	} 
    else if(avegoal<5){
            printf("Classification: poor academic performance\n");
        } 
        else if (avegoal<6.5){
           
            printf("Classification: average academic performance\n");
        } 
        else if (avegoal<8){
            
            printf("Classification: good academic performance\n");
        } 
        else {
            
            printf("Classification: excellent academic performance\n");
        }
        
        
    return 0;
    }
