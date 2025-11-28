#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<stdbool.h>
//Gán giá trị cho số lượng hàng hóa + hàng giao dịch
#define MAX_PRODUCTS 100
#define MAX_TRANSACTIONS 500
//Độ dài tên, đơn vị
#define NAME_LENGTH 50
#define UNIT_LENGTH 20
//Số phần tử trong 1 trang
#define ITEMS_PER_PAGE 5
//Cho số hàng hóa ban đầu = 0
int productCount = 10;
int transactionCount = 0;

typedef struct {
	
	char productId[10];
	char name[NAME_LENGTH];
	char unit[UNIT_LENGTH];
	int qty; 
	int status; 
	
}Product;

typedef struct {
    char transactionId[10]; 
    char productId[10];
    int amount;
    char type[4]; 
    char date[20]; 
} Transaction;
//Khai báo mảng cấu trúc
Transaction transactions[MAX_TRANSACTIONS];
Product products[MAX_PRODUCTS] = {

	{"001","LENOVO LEGION R7000Y", "Chiec", 68, 1},
	{"002","C2 OI HONG", "Chai", 69, 1},
	{"003","DUA HAU", "Kg", 1000, 1}, 
	{"004","KHUYEN TAI NAM TRON", "Chiec", 2000, 1},
	{"005","ACER NITRO 5", "Chiec", 100, 1},
	{"006","REDMI TURBO 4", "Chiec", 100, 1},
	{"007","CAMEL TRA DEN", "Bao", 100, 1},
	{"008","IP17 PRO MAX", "Chiec", 100, 1},
	{"009","THUOC LAO HAT DO", "Goi", 100, 1},
	{"010","SAMSUNG S25 ULTRA", "Chiec", 100, 1}

};
//Kiểm tra số nguyên
int getNumber (const char* suggest, int min, int max) {

	char string[10];
	do {
		printf("%s", suggest);
		fgets(string, sizeof(string), stdin);
		string[strcspn(string, "\n")] = '\0';
		if (string[0]=='\0') {
			printf("Khong duoc de trong thong tin!!\n");
			continue;
		} else {
			int isDigit = 1;
			int i;
			for (i=0; i<strlen(string); i++) {
				if (string[i]<48 || string[i]>57) {
					isDigit = 0;
					break;
				}
			}
			if (isDigit==1) {
				return atoi(string);
			} else {
				printf("Vui long nhap thong tin la so nguyen duong!!!\n");
			}
		}
	} while (1);

}
//In Menu chính
void displayMenuMain () {
	
	printf("============================================");
	printf("\n--------------------MAIN--------------------\n");
	printf("\n1.MENU Quan Ly Hang Hoa\n");
	printf("\n2.MENU Quan Ly Giao Dich\n");
	printf("\n3.Thoat Chuong Trinh\n");
	printf("\n============================================\n");
	
}
//In danh sách quản lý hàng hóa
void displayListProducts () {
	
	printf("===========================================");
	printf("\n-----------MENU QUAN LY HANG HOA-----------\n");
	printf("\n1.Them Ma Hang Moi\n");
	printf("\n2.Cap Nhat Thong Tin Hang Hoa\n");
	printf("\n3.Quan Ly Trang Thai (Active/Locked)\n");
	printf("\n4.Tra Cuu Bang ID/Name\n");
	printf("\n5.Danh sach (Phan Trang)\n");
	printf("\n6.Sap Xep Danh Sach\n");
	printf("\n7.Quay Lai Menu Chinh\n");
	printf("\n===========================================\n");
	
}
//In danh sách quản lý giao dịch
void displayListTransactions () {
	
	printf("============================================");
	printf("\n-----------MENU QUAN LY GIAO DICH-----------\n");
	printf("\n1.Giao Dich Xuat/Nhap Hang Hoa\n");
	printf("\n2.Lich Su Xuat/Nhap Hang Hoa\n");
	printf("\n3.Quay Lai Menu Chinh\n");
	printf("\n============================================\n");
	
}
//Hàm kiểm tra id là duy nhất
int isProductIdUnique(const char* id) {
	int i;
    for (i=0; i<productCount; i++) {
        if (strcmp(products[i].productId, id) == 0) {
            return 0; 
        }
    }
    return 1;
}
//Hàm tìm kiếm index của Product
int findProductIndex(const char* id) {
	int i;
    for (i=0; i<productCount; i++) {
        if (strcmp(products[i].productId, id) == 0) {
            return i;
        }
    }
    return -1;
}
//Hàm in sản phẩm
void printProduct(const Product* p) {
    const char* statusStr = (p->status == 1) ? "Con su dung" : "Het han su dung";
    printf("%-10s | %-30s | %-10s | %-5d | %s\n", 
           p->productId, p->name, p->unit, p->qty, statusStr);
}
//Hàm in tiêu đề để làm màu
void printHeaderList() {
	
	printf("\n%-10s | %-30s | %-10s | %-5s | %s\n", "ID", "Ten Hang Hoa", "Don Vi", "SL", "Trang Thai");
    printf("-------------------------------------------------------------------------\n");
	
}
// Hàm kiểm tra xem chuỗi có chứa ký tự khoảng trắng (' ') hoặc \t ('	') hay không
bool containsSpace(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t) {
            return true;
        }
    }
    return false;
}
//F01_Nhập mã sản phẩm
void enterProductId () {
//Kiểm tra số phần tử trong danh sách	
	if (productCount>=MAX_PRODUCTS) {
		printf("ERROR: He thong da day. Khong the them san pham moi!!!\n");
		return;
	}
//Khai báo biến	
	printf("\n--- THEM MA HANG MOI ---\n");
	char id[10], name[NAME_LENGTH], unit[UNIT_LENGTH];
    int qty;
//Nhập thông tin
    	do {	
			printf("Nhap Ma Don Hang: ");
			fgets(id, sizeof(id), stdin);
			id[strcspn(id, "\n")] = '\0';
			bool hasSpace = containsSpace(id);
			//ID không rỗng và là duy nhất
        	if (strlen(id) == 0) {
             	printf("ERROR: ID khong duoc rong. Vui long nhap lai.\n");
        	} else if (!isProductIdUnique(id)) {
            	printf("ERROR: Ma hang (ID: %s) da ton tai. Vui long nhap ID khac!!\n", id);
        	} else if (hasSpace) {
				printf("ERROR: ID khong duoc rong. Vui long nhap lai.\n");
			}
    	} while (strlen(id) == 0 || !isProductIdUnique(id) || containsSpace(id));
		do {
			printf("Nhap Ten Hang Hoa: ");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';
			//Tên không rỗng
			if (strlen(name) == 0) {
             	printf("ERROR: Ten hang hoa khong duoc rong. Nhap lai!!\n");
        	}
		} while (strlen(name) == 0);
		do {
			printf("Nhap Don Vi Hang Hoa: ");
			fgets(unit, sizeof(unit), stdin);
			unit[strcspn(unit, "\n")] = '\0';
			//Đơn vị không rỗng
			if (strlen(unit) == 0) {
             	printf("ERROR: Don vi hang hoa khong duoc rong. Nhap lai!!\n");
        	} else if (containsSpace(unit)) {
				printf("ERROR: Don vi hang hoa khong duoc rong. Nhap lai!!\n");
			}
		} while (strlen(unit) == 0 || containsSpace(unit));
		//Số lượng phải là số nguyên >0
		qty = getNumber("Nhap So Luong: ", 1, 9999);

    	//Lưu giá trị vừa nhập vào biến newProduct
    	Product newProduct;
    	strcpy(newProduct.productId, id);
   	 	strcpy(newProduct.name, name);
    	strcpy(newProduct.unit, unit);
    	newProduct.qty = qty;
    	newProduct.status = 1; // Luôn mở
		//Tăng độ dài mảng lên ++	
    	products[productCount++] = newProduct;
    	printf("\n--- SUCCESS: Them ma hang %s thanh cong! ---\n", id);
    	
}
//F02_Cập nhặt thông tin của sản phẩm theo ID
void updateInformationProduct () {
//Kiểm tra số phần tử trong danh sách
	if (productCount==0) {
		printf("DANH SACH RONG!!!");
		return;
	}
//Khai báo biến 
	char id[10], newName[NAME_LENGTH] = "", newUnit[UNIT_LENGTH] = "";
    int newQty, index;
    int inputResult;
    
    printf("\n--- CAP NHAT THONG TIN HANG HOA ---\n");
	printf("Nhap MSP Muon Cap Nhat: ");
	fgets(id, sizeof(id), stdin);
	id[strcspn(id, "\n")] = '\0';

//Tìm kiếm ID theo hàm kiếm ID	
	index = findProductIndex(id);
    if (index == -1) {
        printf("ERROR: Khong tim thay ma hang co ID: %s.\n", id);
        return;
    }
//Bắt đầu cập nhật sau khi tìm thấy ID 
		printf("Nhap Ten hang hoa moi (Enter de giu nguyen): ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';
	//Sao chép vào mảng cấu trúc
    if (strlen(newName) > 0) {
        strcpy(products[index].name, newName);
    }

    do {
		printf("Nhap Don vi moi (Enter de giu nguyen): ");
   	 	fgets(newUnit, sizeof(newUnit), stdin);
    	newUnit[strcspn(newUnit, "\n")] = '\0';
		if (strlen(newUnit) > 0) {
			if (containsSpace(newUnit)) {
				printf("ERROR: Don vi hang hoa khong duoc rong. Nhap lai!!\n");
			}
		}
	} while (strlen(newUnit) > 0 && containsSpace(newUnit));
	//Sao chép vào mảng cấu trúc
    if (strlen(newUnit) > 0) {
        strcpy(products[index].unit, newUnit);
    }
    
    printf("Nhap So luong ton kho moi (Nhap -1 de giu nguyen): ");
    inputResult = scanf("%d", &newQty);
	getchar();
	if (inputResult == 1) {
        if (newQty >= 0) {
            products[index].qty = newQty;
        } else if (newQty != -1) {
            printf("WARNING: So luong nhap vao khong hop le (%d). So luong cu khong duoc thay doi.\n", newQty);
        }
    } else {
        printf("WARNING: Du lieu nhap vao khong phai so. So luong cu khong duoc thay doi.\n");
    }
    //Enter để giữ nguyên giữ liệu cũ
    if (strlen(products[index].name) == 0 || strlen(products[index].unit) == 0) {
         printf("\nERROR: Cap nhat that bai! Ten hang hoa hoac Don vi khong duoc rong. Du lieu cu da duoc phuc hoi.\n");
         return;
    }

    printf("\n--- SUCCESS: Cap nhat thong tin ma hang %s thanh cong! ---\n", id);
    
}
//F03_Quản lý trạng thái sản phẩm theo ID
void manageStatusById () {
	
	if (productCount==0) {
		printf("DANH SACH RONG!!!");
		return;
	}
	
	char id[10];
    int status;
    int index;

    printf("\n--- QUAN LY TRANG THAI HANG HOA ---\n");
    printf("Nhap ID hang hoa can thay doi trang thai: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';


    index = findProductIndex(id);
    if (index == -1) {
        printf("ERROR: Khong tim thay ma hang co ID: %s.\n", id);
        return;
    }
    
    printf("Trang thai hien tai cua %s: %s\n", id, 
           (products[index].status == 1) ? "1 - Con su dung" : "0 - Het han su dung");
    char statusStr[10];
    do {
        printf("Nhap trang thai moi (1: Active, 0: Locked/Soft Delete): ");
        if (fgets(statusStr, sizeof(statusStr), stdin) == NULL) {
            return;
        }
        statusStr[strcspn(statusStr, "\n")] = '\0';
        if (strlen(statusStr) != 1) {
            printf("ERROR: Vui long nhap dung 1 ky tu (1 hoac 0), khong de trong.\n");
            continue;
        }
        if (statusStr[0] == '0' || statusStr[0] == '1') {
            status = statusStr[0] - '0';
            break;
        } else {
            printf("ERROR: Chi chap nhan 1 hoac 0. Nhap lai: \n");
        }
        
    } while (1); 

    products[index].status = status;
    if (status == 0) {
        printf("\n--- SUCCESS: Khoa (Soft Delete) ma hang %s. ---\n", id);
    } else {
        printf("\n--- SUCCESS: Kich hoat lai (Active) ma hang %s. ---\n", id);
    }
	
}
//F04_Tìm kiếm sản phẩm bằng ID hoặc tên 
void findProductByIdOrName () {
	
	if (productCount==0) {
		printf("DANH SACH RONG!!!");
		return;
	}
	char keyword[NAME_LENGTH];
    int foundCount = 0;
    
    printf("\n--- TRA CUU HANG HOA ---\n");
    printf("Nhap ID (tim chinh xac) hoac Ten (tim gan dung): ");
	fgets(keyword, sizeof(keyword), stdin);
	keyword[strcspn(keyword, "\n")] = '\0';

	printHeaderList();
	int i;
    for (i=0; i<productCount; i++) {
        if (strcmp(products[i].productId, keyword) == 0 || strstr(products[i].name, keyword) != NULL) {
        	printProduct(&products[i]);
        	foundCount++;
        }
    }	
    if (foundCount==0) {
        printf("Khong tim thay hang hoa nao voi tu khoa: %s\n", keyword);
    }
	
}
//F05_Phân trang danh sách
void listPagination () {
//Kiểm tra số lượng phần tử	
	if (productCount==0) {
		printf("DANH SACH RONG!!!");
		return;
	}
//Khai báo biến
	int currentPage = 1, totalPages;
	int start, end;
	char inputPage[10];
	int targetPage;
//Phân trang
	totalPages = (productCount+ITEMS_PER_PAGE-1)/ITEMS_PER_PAGE;
	do {
        printf("\n--- DANH SACH HANG HOA (Trang %d/%d) ---\n", currentPage, totalPages);
        start = (currentPage - 1) * ITEMS_PER_PAGE;
        end = start + ITEMS_PER_PAGE;
        if (end > productCount) end = productCount;
        
        printHeaderList();                  
        int i;
        for (i=start; i<end; i++) {
            printProduct(&products[i]);
        }
//Logic để truy cập trang kế tiếp hoặc quay lại hoặc thoát danh sách
        printf("\n[Trang: %d/%d] Nhap 'c' de tiep theo, 'b' de truoc, 'f' de tim trang, 'e' de thoat: ", currentPage, totalPages);
        fgets(inputPage, sizeof(inputPage), stdin);
		inputPage[strcspn(inputPage, "\n")] = '\0';

        if (strcmp(inputPage, "c") == 0) {
            if (currentPage < totalPages) {
				currentPage++;
			} else {
				printf("!!! KHONG CON TRANG SAU. Ban dang o trang cuoi (%d/%d).\n", currentPage, totalPages);
			}
        } else if (strcmp(inputPage, "b") == 0) {
            if (currentPage > 1) {
				currentPage--;
			} else {
				printf("!!! KHONG CO TRANG TRUOC. Ban dang o trang dau (1/%d).\n", totalPages);
			}
        } else if (strcmp(inputPage, "f") == 0) {
            targetPage = getNumber("Nhap trang muon tim: ", 1, 9999);
			if (targetPage >= 1 && targetPage <= totalPages) {
                    currentPage = targetPage;
                } else {
                    printf("ERROR: So trang khong hop le. Vui long nhap so trong khoang 1 den %d.\n", totalPages);
                }
        } else if (strcmp(inputPage, "e") == 0) {
            break;
        } else {
			printf("Lenh khong hop le.\n");
		}
    } while (1);
	
}
//So sánh bằng ký tự tên (F06) tăng dần
int compareByName(const void* a, const void* b) {
    const Product* pa = (const Product*)a;
    const Product* pb = (const Product*)b;
    return strcmp(pa->name, pb->name);
}
//So sánh bằng số lượng sản phẩm (F06) tăng dần
int compareByQty(const void* a, const void* b) {
    const Product* pa = (const Product*)a;
    const Product* pb = (const Product*)b;
    return pa->qty - pb->qty;
}
//F06_Sắp xếp theo tên hoặc số lượng sản phẩm
void sortListProduct () {
//Kiểm tra phần tử danh sách	
	if (productCount==0) {
		printf("DANH SACH RONG!!!");
		return;
	}
//Lựa chọn cách sắp xếp
	int sortOption;
	char inputStr[10];
	printf("\n--- F06: SAP XEP DANH SACH ---\n");
    printf("Chon tieu chi sap xep:\n");
    printf("1. Theo Ten (A-Z)\n");
    printf("2. Theo So luong (Tang dan)\n");
    printf("3. Khong sap xep\n");
    printf("Lua chon: ");
    do {
        printf("Lua chon (1 hoac 2 hoac 3): ");
        if (fgets(inputStr, sizeof(inputStr), stdin) == NULL) {
            return;
        }
        inputStr[strcspn(inputStr, "\n")] = '\0';
        if (strlen(inputStr) == 1 && (inputStr[0] == '1' || inputStr[0] == '2' || inputStr[0] == '3')) {
            sortOption = inputStr[0] - '0'; 
            break; 
        } else {
            printf("ERROR: Lua chon khong hop le. Vui long chi nhap so 1 hoac 2 (khong space, khong de trong).\n");
        }
    } while (1);

    if (sortOption == 1) {
        qsort(products, productCount, sizeof(Product), compareByName);
        printf("\n**Danh sach da duoc sap xep theo Ten (A-Z)**\n");
    } else if (sortOption == 2) {
        qsort(products, productCount, sizeof(Product), compareByQty);
        printf("\n**Danh sach da duoc sap xep theo So Luong (Tang dan)**\n");
    }
	
}
// Hàm kiểm tra năm nhuận
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// Hàm kiểm tra tính hợp lệ của chuỗi ngày theo định dạng YYYY-MM-DD
bool isValidDate(const char *date) {
    //Kiểm tra độ dài và định dạng
    if (strlen(date)!=10 || date[4]!='-' || date[7]!='-') {
        return false;
    }
    //Kiểm tra ký tự (chỉ số và dấu gạch ngang)
	int i;
    for (i=0; i<10; i++) {
        if (i==4 || i==7) {
            if (date[i]!='-') return false;
        } else {
            if (date[i]<'0' || date[i]>'9') return false;
        }
    }

    // Tách các thành phần
    char year_str[5], month_str[3], day_str[3];
    strncpy(year_str, date, 4);
    year_str[4] = '\0';
    strncpy(month_str, date + 5, 2);
    month_str[2] = '\0';
    strncpy(day_str, date + 8, 2);
    day_str[2] = '\0';

    int year = atoi(year_str);
    int month = atoi(month_str);
    int day = atoi(day_str);

    //Kiểm tra logic ngày tháng
    if (year < 1900 || year > 2100) return false; // Giới hạn năm hợp lý
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    // Số ngày tối đa trong tháng
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Xử lý năm nhuận cho tháng 2
    if (month == 2 && isLeap(year)) {
        if (day > 29) return false;
    } else {
        if (day > daysInMonth[month]) return false;
    }

    return true;
}
//F07_Giao dịch xuất nhập hàng hóa
void executeTransaction () {
//Kiểm tra phần tử danh sách
	if (productCount==0) {
		printf("DANH SACH RONG!!!\n");
		return;
	}
	char id[10], type[5], date[20];
    int amount, index;
//Nhập id cần tìm    
    printf("\n--- GIAO DICH XUAT/NHAP HANG HOA ---\n");
    printf("Nhap ID hang hoa: ");
    fgets(id, sizeof(id), stdin);
	id[strcspn(id, "\n")] = '\0';
//Tìm kiếm theo id
    index = findProductIndex(id);
    if (index == -1) {
        printf("ERROR: Khong tim thay ma hang co ID: %s.\n", id);
        return;
    }
//Kiểm tra status
    if (products[index].status == 0) {
        printf("ERROR: Ma hang %s da bi khoa. Khong the thuc hien giao dich.\n", id);
        return;
    }
	printf("\n--- THONG TIN HANG HOA '%s' TRUOC GIAO DICH ---\n", id);
	printHeaderList();
	printProduct(&products[index]);
	printf("----------------------------------------------------\n");
//Nhập loại giao dịch
    do {
        printf("Nhap loai giao dich ('I' - Nhap, 'O' - Xuat): ");
        fgets(type, sizeof(type), stdin);
		type[strcspn(type , "\n")] = '\0';
        if (strcmp(type, "I") != 0 && strcmp(type, "O") != 0) {
            printf("ERROR: Loai giao dich khong hop le. Nhap lai: \n");
        }
    } while (strcmp(type, "I") != 0 && strcmp(type, "O") != 0);
//Nhập số lượng + ngày giao dịch
	amount = getNumber("Nhap so luong hang can giao dich: ",1,9999);
	do {
        printf("Ngay giao dich (VD: YYYY-MM-DD): ");
        if (fgets(date, sizeof(date), stdin) == NULL) {
            // Xử lý lỗi đọc input
            return;
        }
        date[strcspn(date, "\n")] = '\0';
        // Bổ sung kiểm tra hợp lệ
        if (!isValidDate(date)) {
            printf("ERROR: Ngay giao dich khong hop le hoac sai dinh dang (phai la YYYY-MM-DD, khong space).\n");
        }
    } while (!isValidDate(date));
//Kiểm tra logic Nhap - Xuat
	if (strcmp(type, "I") == 0) {
        products[index].qty += amount;
        printf("\n--- SUCCESS: Nhap %d %s cho %s. Ton kho moi: %d. ---\n", 
               amount, products[index].unit, id, products[index].qty);
    } else { 
        if (amount > products[index].qty) {
            printf("ERROR: So luong xuat (%d) lon hon so luong ton kho (%d). Giao dich bi huy.\n", 
                   amount, products[index].qty);
            return;
        }
        products[index].qty -= amount;
        printf("\n--- SUCCESS: Xuat %d %s cho %s. Ton kho moi: %d. ---\n", 
               amount, products[index].unit, id, products[index].qty);
    }
//Lưu giao dịch
	if (transactionCount < MAX_TRANSACTIONS) {
        Transaction newTrans;
        sprintf(newTrans.transactionId, "T%04d", transactionCount + 1);
        strcpy(newTrans.productId, id);
        newTrans.amount = amount;
        strcpy(newTrans.type, type);
        strcpy(newTrans.date, date);
        transactions[transactionCount++] = newTrans;
    } else {
        printf("WARNING: Khong the luu giao dich. Mang Transaction da day.\n");
    }

}
//F08_Lịch sử xuất nhập hàng hóa
void historyOfTransaction () {
//Kiểm tra số phần tử trong danh sách
	if (transactionCount==0) {
		printf("LICH SU GIAO DICH RONG!!!\n");
		return;
	}
	char id[10];
	int found = 0;
	printf("--- LICH SU XUAT/NHAP HANG HOA ---\n");
	printf("Nhap vao id can tim: ");
//Nhập id cần tìm
	fgets(id, sizeof(id), stdin);
	id[strcspn(id, "\n")] = '\0';
//In lịch sử giao dịch
	printf("\n--- LICH SU GIAO DICH CUA MA HANG %s ---\n", id);
	printf("%-10s | %-10s | %-5s | %-8s | %s\n", "ID trans", "ID product", "Type", "So Luong", "Ngay");
	printf("-------------------------------------------------\n");
	int i;
	for (i=0; i<transactionCount; i++) {
		if (strcmp(transactions[i].productId, id)==0) {
			printf("%-10s | %-10s | %-5s | %-8d | %s\n",
				transactions[i].transactionId,
				transactions[i].productId,
				transactions[i].type,
				transactions[i].amount,
				transactions[i].date);
			found = 1;
		}
	}
	if (!found) {
		printf("Khong co giao dich nao duoc tim thay cho ma hang %s\n", id);
	}
}
//Hàm chính
int main () {
	//Lựa chọn MENU chính
	char suggest[] = "Moi ban nhap vao 1 lua chon: ";
	int choice;
	do {
		displayMenuMain ();
		choice = getNumber(suggest, 1, 3);
		switch (choice) {
			case 1:
			//Lựa chọn quản lý danh sách
				int choice1;
				do {
					displayListProducts ();
					choice1 = getNumber(suggest, 1, 7);
					switch (choice1) {
						case 1:
							enterProductId ();
							printf("\n");
							break;
						case 2:
							updateInformationProduct ();
							printf("\n");
							break;
						case 3:
							manageStatusById ();
							printf("\n");
							break;
						case 4:
							findProductByIdOrName ();
							printf("\n");
							break;
						case 5:
							listPagination ();
							printf("\n");
							break;
						case 6:
							sortListProduct ();	
							printf("\n");
							break;
						case 7:
						//Quay lại MENU chính
							printf("Ban da quay lai MENU chinh!!!");
							printf("\n");
							break;
						default:
							printf("Vui long nhap lua chon theo MENU (1-7)");
							printf("\n");
							break;
					}
			} while (choice1!=7);
				break;
			case 2:
			//Lựa chọn quản lý giao dịch
				int choice2;
				do {
					displayListTransactions ();
					choice2 = getNumber(suggest, 1, 3);
					switch (choice2) {
						case 1:
							executeTransaction ();
							break;
						case 2:
							historyOfTransaction ();
							break;
						case 3:
						//Quay lại MENU chính
							printf("Ban da quay lai MENU chinh!!!");
							printf("\n");
							break;
						default:
							printf("Vui long nhap lua chon theo MENU (1-3)");
							printf("\n");
							break;
					}
				} while (choice2!=3);
				printf("\n");
				break;
			case 3:
			//Thoát chương trình
				printf("Cam on vi da su dung chuong trinh cua chung toi!!!");
				printf("\n");
				break;
			default:
			//LỖI
				printf("Vui long nhap lua chon theo MENU (1-3)");
				printf("\n");
				break;
		}
	} while (choice!=3);
	
	return 0;
}

