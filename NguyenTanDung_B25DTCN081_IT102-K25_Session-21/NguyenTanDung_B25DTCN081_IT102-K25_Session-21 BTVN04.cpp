#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Book {
	
	char title[100];
	char author[50];
	float price;
	
};

int main () {
	
	struct Book books[3];
	
	int i;
	for (i=0; i<3; i++) {
		
		printf("Nhap ten cua cuon sach thu %d: ",i+1);
		fgets(books[i].title,sizeof(books[i].title),stdin);
		books[i].title[strcspn(books[i].title, "\n")] = '\0';
		fflush(stdin);
		
		printf("Nhap ten tac gia cua cuon sach thu %d: ",i+1);
		fgets(books[i].author,sizeof(books[i].author),stdin);
		books[i].author[strcspn(books[i].author, "\n")] = '\0';
		fflush(stdin);
		
		printf("Nhap gia ban cua cuon sach thu %d: ",i+1);
		scanf("%f",&books[i].price);
		getchar();
		
	}
	for (i=0; i<3; i++) {
			printf("Ten Sach: %s || Ten Tac Gia: %s || Gia Ban: %.1f VND\n", books[i].title, books[i].author, books[i].price);
	}

	
	return 0;
}
