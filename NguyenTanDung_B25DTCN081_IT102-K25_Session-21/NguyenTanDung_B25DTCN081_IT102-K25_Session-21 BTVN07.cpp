#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SACH 100
#define MAX_STR 100


typedef struct {
    char MaSach[10];
    char TenSach[MAX_STR];
    char TacGia[MAX_STR];
    float GiaTien;
    char TheLoai[MAX_STR];
} Sach;

Sach danhSachSach[MAX_SACH];
int soLuongSach = 0;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void nhapThongTinSach(Sach *s) {

    printf("  - Nhap Ma sach: ");
    scanf("%s", s->MaSach);
    clear_input_buffer(); 

    printf("  - Nhap Ten sach: ");
    fgets(s->TenSach, MAX_STR, stdin);
    s->TenSach[strcspn(s->TenSach, "\n")] = 0; 

    printf("  - Nhap Ten tac gia: ");
    fgets(s->TacGia, MAX_STR, stdin);
    s->TacGia[strcspn(s->TacGia, "\n")] = 0;

    printf("  - Nhap Gia tien: ");
    while (scanf("%f", &s->GiaTien) != 1 || s->GiaTien < 0) {
        printf("Gia tien khong hop le. Nhap lai: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("  - Nhap The loai: ");
    fgets(s->TheLoai, MAX_STR, stdin);
    s->TheLoai[strcspn(s->TheLoai, "\n")] = 0;
}

void hienThiTieuDe() {
    printf("\n------------------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-25s | %-18s | %-12s | %-15s |\n", 
           "MA SACH", "TEN SACH", "TAC GIA", "GIA TIEN", "THE LOAI");
    printf("------------------------------------------------------------------------------------------------\n");
}

void hienThiSach(const Sach *s) {
    printf("| %-8s | %-25s | %-18s | %-12.0f | %-15s |\n", 
           s->MaSach, s->TenSach, s->TacGia, s->GiaTien, s->TheLoai);
}

void nhapDanhSachSach() {
    int n;
    printf("\n--- CHUC NANG 1: NHAP SACH ---\n");
    if (soLuongSach >= MAX_SACH) {
        printf("-> Danh sach da day (%d cuon).\n", MAX_SACH);
        return;
    }

    printf("Nhap so luong sach can them (toi da %d): ", MAX_SACH - soLuongSach);
    while (scanf("%d", &n) != 1 || n <= 0 || soLuongSach + n > MAX_SACH) {
        printf("So luong khong hop le. Nhap lai: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    for (int i = 0; i < n; ++i) {
        printf("\n** Nhap thong tin sach thu %d **\n", soLuongSach + 1);
        nhapThongTinSach(&danhSachSach[soLuongSach]);
        soLuongSach++;
    }
    printf("\n-> Da nhap thanh cong %d cuon sach.\n", n);
}

void hienThiDanhSachSach() {
    printf("\n--- CHUC NANG 2: HIEN THI SACH ---\n");
    if (soLuongSach == 0) {
        printf("-> Danh sach rong. Hay nhap sach truoc.\n");
        return;
    }
    hienThiTieuDe();
    for (int i = 0; i < soLuongSach; ++i) {
        hienThiSach(&danhSachSach[i]);
    }
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Tong so sach: %d\n", soLuongSach);
}

void themSachVaoViTri() {
    printf("\n--- CHUC NANG 3: THEM SACH VAO VI TRI ---\n");
    if (soLuongSach >= MAX_SACH) {
        printf("-> Danh sach da day, khong the them duoc nua.\n");
        return;
    }

    int viTri;
    printf("Nhap vi tri can them (1 den %d): ", soLuongSach + 1);
    while (scanf("%d", &viTri) != 1 || viTri < 1 || viTri > soLuongSach + 1) {
        printf("Vi tri khong hop le. Nhap lai: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    for (int i = soLuongSach; i >= viTri; --i) {
        danhSachSach[i] = danhSachSach[i - 1];
    }

    printf("\n** Nhap thong tin sach can them **\n");
    nhapThongTinSach(&danhSachSach[viTri - 1]);
    soLuongSach++;
    printf("\n-> Da them sach vao vi tri %d thanh cong.\n", viTri);
}

void xoaSachTheoMa() {
    printf("\n--- CHUC NANG 4: XOA SACH THEO MA ---\n");
    if (soLuongSach == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }

    char maCanXoa[10];
    printf("Nhap Ma sach can xoa: ");
    scanf("%s", maCanXoa);
    clear_input_buffer();

    int viTriCanXoa = -1;
    for (int i = 0; i < soLuongSach; ++i) {
        if (strcmp(danhSachSach[i].MaSach, maCanXoa) == 0) {
            viTriCanXoa = i;
            break;
        }
    }

    if (viTriCanXoa != -1) {

        for (int i = viTriCanXoa; i < soLuongSach - 1; ++i) {
            danhSachSach[i] = danhSachSach[i + 1];
        }
        soLuongSach--;
        printf("-> Da xoa sach co Ma sach: %s thanh cong.\n", maCanXoa);
    } else {
        printf("-> Khong tim thay sach co Ma sach: %s\n", maCanXoa);
    }
}

void capNhatSachTheoMa() {
    printf("\n--- CHUC NANG 5: CAP NHAT THONG TIN SACH ---\n");
    if (soLuongSach == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }

    char maCanCapNhat[10];
    printf("Nhap Ma sach can cap nhat: ");
    scanf("%s", maCanCapNhat);
    clear_input_buffer();

    int viTriCanCapNhat = -1;
    for (int i = 0; i < soLuongSach; ++i) {
        if (strcmp(danhSachSach[i].MaSach, maCanCapNhat) == 0) {
            viTriCanCapNhat = i;
            break;
        }
    }

    if (viTriCanCapNhat != -1) {
        printf("\n** Tim thay sach. Nhap thong tin moi: **\n");

        char maTam[10];
        strcpy(maTam, danhSachSach[viTriCanCapNhat].MaSach);

        nhapThongTinSach(&danhSachSach[viTriCanCapNhat]);

        strcpy(danhSachSach[viTriCanCapNhat].MaSach, maTam);

        printf("\n-> Cap nhat thong tin sach co Ma: %s thanh cong.\n", maCanCapNhat);
    } else {
        printf("-> Khong tim thay sach co Ma sach: %s\n", maCanCapNhat);
    }
}

int compareSachAsc(const void *a, const void *b) {
    Sach *s1 = (Sach *)a;
    Sach *s2 = (Sach *)b;
    if (s1->GiaTien < s2->GiaTien) return -1;
    if (s1->GiaTien > s2->GiaTien) return 1;
    return 0;
}

int compareSachDesc(const void *a, const void *b) {
    Sach *s1 = (Sach *)a;
    Sach *s2 = (Sach *)b;
    if (s1->GiaTien > s2->GiaTien) return -1;
    if (s1->GiaTien < s2->GiaTien) return 1;
    return 0;
}

void sapXepTheoGia() {
    printf("\n--- CHUC NANG 6: SAP XEP SACH THEO GIA ---\n");
    if (soLuongSach == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }

    int luaChon;
    printf("Chon kieu sap xep (1. Tang dan | 2. Giam dan): ");
    while (scanf("%d", &luaChon) != 1 || (luaChon != 1 && luaChon != 2)) {
        printf("Lua chon khong hop le. Nhap lai (1 hoac 2): ");
        clear_input_buffer();
    }
    clear_input_buffer();

    if (luaChon == 1) {
        qsort(danhSachSach, soLuongSach, sizeof(Sach), compareSachAsc);
        printf("-> Da sap xep sach theo Gia tien tang dan.\n");
    } else {
        qsort(danhSachSach, soLuongSach, sizeof(Sach), compareSachDesc);
        printf("-> Da sap xep sach theo Gia tien giam dan.\n");
    }
    hienThiDanhSachSach();
}

void timKiemTheoTen() {
    printf("\n--- CHUC NANG 7: TIM KIEM SACH THEO TEN ---\n");
    if (soLuongSach == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }

    char tenCanTim[MAX_STR];
    printf("Nhap Ten sach can tim (khong phan biet chu hoa/thuong): ");
    fgets(tenCanTim, MAX_STR, stdin);
    tenCanTim[strcspn(tenCanTim, "\n")] = 0;
    
    to_lower_case(tenCanTim);

    printf("\n-> Ket qua tim kiem cho Ten sach chua '%s':\n", tenCanTim);
    
    int timThay = 0;
    Sach ketQua[MAX_SACH];
    int soKetQua = 0;

    for (int i = 0; i < soLuongSach; ++i) {
        char tenSachLower[MAX_STR];
        strcpy(tenSachLower, danhSachSach[i].TenSach);
        to_lower_case(tenSachLower);

        if (strstr(tenSachLower, tenCanTim) != NULL) {
            ketQua[soKetQua++] = danhSachSach[i];
            timThay = 1;
        }
    }

    if (timThay) {
        hienThiTieuDe();
        for (int i = 0; i < soKetQua; i++) {
            hienThiSach(&ketQua[i]);
        }
        printf("------------------------------------------------------------------------------------------------\n");
    } else {
        printf("-> Khong tim thay sach co Ten sach chua: '%s'\n", tenCanTim);
    }
}

int main() {
    int luaChon;

    do {
        printf("\n================= MENU QUAN LY SACH (C) =================\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim kiem sach theo ten sach.\n");
        printf("8. Thoat\n");
        printf("---------------------------------------------------------\n");
        printf("=> Lua chon cua ban: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le. Vui long nhap so (1-8).\n");
            clear_input_buffer();
            luaChon = 0;
            continue;
        }
        clear_input_buffer();

        switch (luaChon) {
            case 1:
                nhapDanhSachSach();
                break;
            case 2:
                hienThiDanhSachSach();
                break;
            case 3:
                themSachVaoViTri();
                break;
            case 4:
                xoaSachTheoMa();
                break;
            case 5:
                capNhatSachTheoMa();
                break;
            case 6:
                sapXepTheoGia();
                break;
            case 7:
                timKiemTheoTen();
                break;
            case 8:
                printf("\n---------------------------------------------------------\n");
                printf("-> Chuong trinh ket thuc. Tam biet!\n");
                printf("---------------------------------------------------------\n");
                break;
            default:
                printf("-> Lua chon khong hop le. Vui long chon tu 1 den 8.\n");
                break;
        }
    } while (luaChon != 8);

    return 0;
}
