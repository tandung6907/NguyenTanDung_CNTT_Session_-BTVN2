#include<stdio.h>

int main () {
	int i, j, num, choice, index, value, searchvl;
	int arr[100];
	int max,temp,sum,found;
	do {
		printf("*****************MENU******************");
		printf("\n1.Nhap so phan tu cua mang ");
		printf("\n2.In ra cac gia tri trong mang");
		printf("\n3.In ra cac so hoan hao trong mang");
		printf("\n4.Tim gia tri lon nhat trong mang");
		printf("\n5.Them moi mot phan tu vao dau mang");
		printf("\n6.Xoa phan tu o mot vi tri cu the(Nguoi dung nhap)");
		printf("\n7.In mang theo tu tu giam dan (Insertion sort)");
		printf("\n8.Tim kiem va hien thi vi tri cua 1 phan tu (Linear sort)");
		printf("\n9.In mang sao cho so chan dung truoc so le dung sau ma khong thay doi thu tu ban dau cua phan tu");
		printf("\n10.Sap xep mang theo thu tu nguoc lai");
		printf("\nThoat chuong trinh");
		printf("\nVui long nhap lua chon cua ban: ");
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
				if (num==0){
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Mang gia tri ban dau la: \n");
				for (i=0 ; i<num ; i++){
					printf("%d\t",arr[i]);
				}
				printf("\n");
				break;
			case 3:
				if (num==0){
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
    			found = 0;
    			for (i=0 ; i<num ; i++) {
        			sum = 0;
        			for (j=1 ; j<=arr[i]/2; j++) {
            			if (arr[i]%j==0){
            				sum += j;
						}
					}				
        			if (sum==arr[i]&&arr[i]>0) {
        				printf("Cac so hoan hao co trong mang la: \n");
            			printf("%d\t", arr[i]);
            			found = 1;
            			break;
        			}
    			}
    				if (!found){
    					printf("Khong co so hoan hao nao trong mang.");
					}
				printf("\n");
				break;
			case 4:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
					max = arr[0];
				for (i=0 ; i<num ; i++) {
					if (arr[i]>max) {
						max = arr[i];
					}					
				}
				printf("GTLN cua mang la: %d",max);
				printf("\n");
				break;
			case 5:
				printf("Nhap gia tri can chen: ");
				scanf("%d",&value);					
				for (i=num ; i>=1 ; i--){
					arr[i] = arr[i-1];
				}
				arr[0] = value;
				num++;
				printf("Da chen them phan tu %d vao dau mang",value);
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
				for (i=1 ; i<num ; i++) {
        			temp = arr[i];
        			j = i-1;

        		while (j>=0&&arr[j]<temp) {
            		arr[j+1] = arr[j];
            		j--;
        	}
        			arr[j+1] = temp;
    	}

    			printf("\nMang sau khi sap xep giam dan:\n");
    			for (i=0 ; i<num ; i++) {
        			printf("%d\t", arr[i]);
    		}
				printf("\n");
				break;	
			case 8:
				if (num==0) {
					printf("Vui long nhap so phan tu va gia tri phan tu truoc!!\n");
					break;
				}
				printf("Nhap gia tri can tim: ");
				scanf("%d",&searchvl);
				for (i=0 ; i<num ; i++){
				    if (arr[i]==searchvl){
					printf("Phan tu co chi so %d co gia tri bang: %d\n",i,searchvl);
					break;
				}else {
					printf("Khong tim thay gia tri can tim trong mang!");
					break;
				}
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
					if (arr[i]%2==0) {
						printf("%d\t",arr[i]);
				}
			}
			    for (i=0 ; i<num ; i++) {
					if (arr[i]%2!=0) {
						printf("%d\t",arr[i]);
				}
			}
				printf("\n");
				break;
			case 10:
				printf("\n");
				break;	
			case 11:
				printf("Ban da thoat chuong trinh!!! Hen gap lai<33");
				printf("\n");
				break;	
		    default:
		    	printf("Lua chon cua ban khong hop le vui long chon tu 1 den 10!!");	
				printf("\n");
		    	break;
	}	
	}while(choice!=11);

}

