#include<stdio.h>
#define MAX 100
#include<math.h>
int isPrime(int num) {
	int i;
    if (num < 2)
        return 0;
    for ( i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0; 
    }
    return 1;
}
int main () {
	int num, i, j, choice, index, value, searchvalue;
	int arr[MAX];
	int isPrime = 1,isSorted = 0, found = 0;
	int min,temp,imin;
	int left = 0, right = num -1;

	
	do {
		printf("************************MENU*********************");
		printf("\n1.Nhap so luong phan tu va gia tri cho mang");
		printf("\n2.In ra gia tri cac phan tu trong mang");
		printf("\n3.In cac so la so nguyen to trong mang");
		printf("\n4.Tim gia tri nho nhat trong mang");
		printf("\n5.Them moi mot phan tu vao vi tri cu the(nguoi dung nhap)");
		printf("\n6.Xoa phan tu tai 1 vi tri cu the (nguoi dung nhap)");
		printf("\n7.Sap xep theo thu tu tang dan(Selection sort)");
		printf("\n8.Kiem tra su ton tai cua phan tu trong mang(Binary search)");
		printf("\n9.In mang sao cho toan bo so le dung truoc so chan dung sau nhung khong lam thay doi thu tu cac so chan le ban dau");
		printf("\n10.Sap xep mang thep thu tu nguoc lai");
		printf("\n11.Thoat chuong trinh\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d",&choice);	
		switch(choice){
			case 1:
				printf("Nhap vao so phan tu cua mang: ");
				scanf("%d",&num);
				for (i=0 ; i<num ; i++){
					printf("Nhap vao gia tri cua phan tu thu %d: ",i+1);
					scanf("%d",&arr[i]);
				}
				printf("\n");
				break;
			case 2:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Chung ta co mang ban dau la: \n");
				for (i=0 ; i<num ; i++){
					printf("%d\t",arr[i]);
				}
				printf("\n");
				break;	
			case 3:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Cac so nguyen to trong mang la: ");
            	int found = 0;
    			for (i=0 ; i<num ; i++) {
        			if (isPrime(arr[i])) {
            			printf("%d ", arr[i]);
            			found = 1;
        		}
    		}
    				if (!found)
        				printf("Khong co so nguyen to nao trong mang!");
				printf("\n");
				break;	
			case 4:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
					min = arr[0];
				for (i=0 ; i<num ; i++) {
					if (arr[i]<min) {
						arr[i] = min;
					}					
				}
				printf("GTNN cua mang la: %d",min);
				printf("\n");
				break;	
			case 5:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Nhap chi so can chen: ");
				scanf("%d",&index);
				printf("Nhap gia tri can chen: ");
				scanf("%d",&value);
				if (index<0 || index>=num) {
					printf("Khong the chen!\n");
					break;
				}
				for (i=num ; i>index ; i--){
					arr[i] = arr[i-1];
				}
					arr[index] = arr[value];
					num++;
					printf("Da chen phan tu %d tai vi tri %d\n",value,index);
					break;				
				printf("\n");
				break;	
			case 6:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Nhap vao chi so can xoa: ");
				scanf("%d",&index);
				if (index<0 || index>=num){
					printf("Chi so khong hop le!!\n");
					break;
				}
				for (i=index ; i<num-1 ; i++) {
					arr[i] = arr[i+1];
			}
					num--;
					printf("Phan tu da xoa o vi tri %d\n",index);
					break;
				printf("\n");
				break;	
			case 7:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				for (i=0 ; i<num-1 ; i++) {
                    imin = i;
                    for (j=i+1 ; j<num ; j++) {
                        if (arr[j]<arr[imin]) {
                            imin = j;
                    }
                }
                            temp = arr[i];
                            arr[i] = arr[imin];
                            arr[imin] = temp;
                            isSorted = 1;
            }
						printf("\nMang sau khi sap xep tang dan: \n");
                        for (i=0 ; i<num ; i++) {
                        printf("%d \t", arr[i]);
                    }
                    printf("\n");
				break;	
			case 8:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Nhap gia tri can tim: ");
				scanf("%d",&searchvalue);
				if (isSorted == 1) {
					printf("Mang da duoc sap xep -> Su dung Binary Search\n");
					int mid, left = 0, right = num -1;
	                        do{
		                       mid = left + (right - left)/2;
		                        if (arr[mid]>searchvalue){
			                        right = mid -1;
		                        }
		                        if (arr[mid]<searchvalue){
			                        left = mid +1;
		                        }
	                        }while(arr[mid]!=searchvalue&&left<=right);
	
	                            if (arr[mid]==searchvalue){
	 	                            printf("Phan tu can tim co chi so %d va gia tri = %d\n",mid,searchvalue);
	                            }else {
	     	                        printf("Khong tim thay phan tu nao co gia tri = %d trong mang\n",searchvalue);
	                            }
			}
			    if(isSorted==0) {
			    	printf("Vui long sap xep mang theo thu tu tang dan!!!");
				}
				printf("\n");
				break;	
			case 9:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Mang sau khi duoc sap xep chan le la:\t");
				for (i=0 ; i<num ; i++) {
					if (arr[i]%2!=0) {
						printf("%d\t",arr[i]);
				}
			}
			    for (i=0 ; i<num ; i++) {
					if (arr[i]%2==0) {
						printf("%d\t",arr[i]);
				}
			}
				printf("\n");
				break;	
			case 10:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				
				break;
				printf("\n");	
			case 11:
				printf("Ban da thoat chuong trinh!! Xin henn gap lai<33");
				break;	
			default:
			printf("Lua chon cua ban khong hop le vui long chon tu 1 den 10!!");	
			printf("\n");
			break;
		}
		
	}while(choice!=11);
}
