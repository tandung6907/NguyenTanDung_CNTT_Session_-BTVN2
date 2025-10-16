# include <stdio.h>
 int main(){
 	int Number = 12345;
 	int d1 = Number % 10;
 	int d2 = (Number/10)%10;
 	int d3 = (Number/100)%10;
 	int d4 = (Number/1000)%10;
 	int d5 = (Number/10000)%10;
 	int Tong = d1 + d2 + d3 + d4 +d5;
 	printf("So ban dau la: %d \n ", Number);
 	printf("Tong cac chu so la: %d", Tong);
 	
 	return 0; 
 }
