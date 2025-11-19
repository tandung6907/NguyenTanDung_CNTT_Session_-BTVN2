#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SANPHAM 100
#define MAX_STR 100

typedef struct {
    char MaSP[10];
    char TenSP[MAX_STR];
    float GiaNhap;
    float GiaBan;
    int SoLuong;
} SanPham;

SanPham danhSachSP[MAX_SANPHAM];
int soLuongHienTai = 0;
float DoanhThu = 0.0;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int timViTriTheoMa(const char *ma) {
    for (int i = 0; i < soLuongHienTai; i++) {
        if (strcmp(danhSachSP[i].MaSP, ma) == 0) {
            return i;
        }
    }
    return -1;
}

void nhapThongTinCoBan(SanPham *sp) {
    printf("  - Nhap Ten san pham: ");
    fgets(sp->TenSP, MAX_STR, stdin);
    sp->TenSP[strcspn(sp->TenSP, "\n")] = 0;

    printf("  - Nhap Gia nhap: ");
    while (scanf("%f", &sp->GiaNhap) != 1 || sp->GiaNhap <= 0) {
        printf("Gia nhap khong hop le. Nhap lai: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("  - Nhap Gia ban: ");
    while (scanf("%f", &sp->GiaBan) != 1 || sp->GiaBan <= sp->GiaNhap) {
        printf("Gia ban phai > Gia nhap. Nhap lai: ");
        clear_input_buffer();
    }
    clear_input_buffer();
}

void hienThiTieuDe() {
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("| %-8s | %-25s | %-10s | %-10s | %-8s |\n", 
           "MA SP", "TEN SAN PHAM", "GIA NHAP", "GIA BAN", "SO LUONG");
    printf("---------------------------------------------------------------------------------------\n");
}

void hienThiSanPham(const SanPham *sp) {
    printf("| %-8s | %-25s | %-10.0f | %-10.0f | %-8d |\n", 
           sp->MaSP, sp->TenSP, sp->GiaNhap, sp->GiaBan, sp->SoLuong);
}

void nhapDanhSachSPMoi() {
    int n;
    printf("\n--- CHUC NANG 1: NHAP SAN PHAM MOI ---\n");
    if (soLuongHienTai >= MAX_SANPHAM) {
        printf("-> Danh sach da day (%d san pham).\n", MAX_SANPHAM);
        return;
    }

    printf("Nhap so luong san pham moi can them (toi da %d): ", MAX_SANPHAM - soLuongHienTai);
    while (scanf("%d", &n) != 1 || n <= 0 || soLuongHienTai + n > MAX_SANPHAM) {
        printf("So luong khong hop le. Nhap lai: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    for (int i = 0; i < n; ++i) {
        printf("\n** Nhap thong tin san pham thu %d **\n", soLuongHienTai + 1);
        
        SanPham spMoi;
        int viTri;
        
        printf("  - Nhap Ma san pham: ");
        fgets(spMoi.MaSP, 10, stdin);
        spMoi.MaSP[strcspn(spMoi.MaSP, "\n")] = 0;

        viTri = timViTriTheoMa(spMoi.MaSP);
        if (viTri != -1) {
            printf("-> Ma san pham %s da ton tai. Chi nen su dung chuc nang 'Nhap san pham' de them so luong.\n", spMoi.MaSP);
            i--;
            continue;
        }

        nhapThongTinCoBan(&spMoi);
        
        printf("  - Nhap So luong nhap kho lan dau: ");
        while (scanf("%d", &spMoi.SoLuong) != 1 || spMoi.SoLuong <= 0) {
            printf("So luong khong hop le. Nhap lai: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        DoanhThu -= spMoi.SoLuong * spMoi.GiaNhap;

        danhSachSP[soLuongHienTai] = spMoi;
        soLuongHienTai++;
    }
    printf("\n-> Da them thanh cong %d san pham moi.\n", n);
}

void hienThiDanhSachSP() {
    printf("\n--- CHUC NANG 2: HIEN THI DANH SACH SAN PHAM ---\n");
    if (soLuongHienTai == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }
    hienThiTieuDe();
    for (int i = 0; i < soLuongHienTai; ++i) {
        hienThiSanPham(&danhSachSP[i]);
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("Tong so loai san pham: %d\n", soLuongHienTai);
}

void nhapThemSoLuong() {
    printf("\n--- CHUC NANG 3: NHAP THEM SO LUONG SAN PHAM ---\n");
    char maCanNhap[10];
    int soLuongThem;
    
    printf("Nhap Ma san pham can nhap them: ");
    fgets(maCanNhap, 10, stdin);
    maCanNhap[strcspn(maCanNhap, "\n")] = 0;

    int viTri = timViTriTheoMa(maCanNhap);

    if (viTri != -1) {
        printf("-> San pham: %s | So luong hien tai: %d\n", danhSachSP[viTri].TenSP, danhSachSP[viTri].SoLuong);
        printf("Nhap so luong can them: ");
        while (scanf("%d", &soLuongThem) != 1 || soLuongThem <= 0) {
            printf("So luong khong hop le. Nhap lai: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        danhSachSP[viTri].SoLuong += soLuongThem;
        
        DoanhThu -= soLuongThem * danhSachSP[viTri].GiaNhap;
        
        printf("-> Da nhap them %d san pham. So luong moi: %d.\n", soLuongThem, danhSachSP[viTri].SoLuong);
    } else {
        printf("-> Khong tim thay san pham co Ma: %s. Hay su dung chuc nang 'Nhap so luong va thong tin san pham' de them moi.\n", maCanNhap);
    }
}

void capNhatThongTin() {
    printf("\n--- CHUC NANG 4: CAP NHAT THONG TIN SAN PHAM ---\n");
    char maCanCapNhat[10];
    
    printf("Nhap Ma san pham can cap nhat: ");
    fgets(maCanCapNhat, 10, stdin);
    maCanCapNhat[strcspn(maCanCapNhat, "\n")] = 0;

    int viTri = timViTriTheoMa(maCanCapNhat);

    if (viTri != -1) {
        printf("\n** Tim thay san pham. Nhap thong tin moi: **\n");
        
        char maTam[10];
        strcpy(maTam, danhSachSP[viTri].MaSP);

        int slTam = danhSachSP[viTri].SoLuong;
        
        nhapThongTinCoBan(&danhSachSP[viTri]);

        strcpy(danhSachSP[viTri].MaSP, maTam);
        danhSachSP[viTri].SoLuong = slTam;

        printf("\n-> Cap nhat thong tin san pham co Ma: %s thanh cong.\n", maCanCapNhat);
    } else {
        printf("-> Khong tim thay san pham co Ma: %s\n", maCanCapNhat);
    }
}

int compareSPAsc(const void *a, const void *b) {
    SanPham *s1 = (SanPham *)a;
    SanPham *s2 = (SanPham *)b;
    if (s1->GiaBan < s2->GiaBan) return -1;
    if (s1->GiaBan > s2->GiaBan) return 1;
    return 0;
}

int compareSPDesc(const void *a, const void *b) {
    SanPham *s1 = (SanPham *)a;
    SanPham *s2 = (SanPham *)b;
    if (s1->GiaBan > s2->GiaBan) return -1;
    if (s1->GiaBan < s2->GiaBan) return 1;
    return 0;
}

void sapXepTheoGia() {
    printf("\n--- CHUC NANG 5: SAP XEP SAN PHAM THEO GIA ---\n");
    if (soLuongHienTai == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }

    int luaChon;
    printf("Chon kieu sap xep (1. Tang dan | 2. Giam dan theo Gia Ban): ");
    while (scanf("%d", &luaChon) != 1 || (luaChon != 1 && luaChon != 2)) {
        printf("Lua chon khong hop le. Nhap lai (1 hoac 2): ");
        clear_input_buffer();
    }
    clear_input_buffer();

    if (luaChon == 1) {
        qsort(danhSachSP, soLuongHienTai, sizeof(SanPham), compareSPAsc);
        printf("-> Da sap xep san pham theo Gia ban tang dan.\n");
    } else {
        qsort(danhSachSP, soLuongHienTai, sizeof(SanPham), compareSPDesc);
        printf("-> Da sap xep san pham theo Gia ban giam dan.\n");
    }
    hienThiDanhSachSP();
}

void timKiemSanPham() {
    printf("\n--- CHUC NANG 6: TIM KIEM SAN PHAM ---\n");
    if (soLuongHienTai == 0) {
        printf("-> Danh sach rong.\n");
        return;
    }

    char tenCanTim[MAX_STR];
    printf("Nhap Ten san pham (hoac mot phan ten) can tim: ");
    fgets(tenCanTim, MAX_STR, stdin);
    tenCanTim[strcspn(tenCanTim, "\n")] = 0;
    
    for (int i = 0; tenCanTim[i]; i++) {
        tenCanTim[i] = tolower(tenCanTim[i]);
    }

    printf("\n-> Ket qua tim kiem cho Ten san pham chua '%s':\n", tenCanTim);
    
    int timThay = 0;
    hienThiTieuDe();
    for (int i = 0; i < soLuongHienTai; ++i) {
        char tenSPLower[MAX_STR];
        strcpy(tenSPLower, danhSachSP[i].TenSP);
        
        for (int j = 0; tenSPLower[j]; j++) {
            tenSPLower[j] = tolower(tenSPLower[j]);
        }

        if (strstr(tenSPLower, tenCanTim) != NULL) {
            hienThiSanPham(&danhSachSP[i]);
            timThay = 1;
        }
    }
    printf("---------------------------------------------------------------------------------------\n");

    if (!timThay) {
        printf("-> Khong tim thay san pham nao chua: '%s'\n", tenCanTim);
    }
}

void banSanPham() {
    printf("\n--- CHUC NANG 7: BAN SAN PHAM ---\n");
    char maCanBan[10];
    int soLuongBan;
    
    printf("Nhap Ma san pham can ban: ");
    fgets(maCanBan, 10, stdin);
    maCanBan[strcspn(maCanBan, "\n")] = 0;

    int viTri = timViTriTheoMa(maCanBan);

    if (viTri != -1) {
        SanPham *sp = &danhSachSP[viTri];
        
        if (sp->SoLuong == 0) {
            printf("-> SAN PHAM HET HANG! Khong the ban.\n");
            return;
        }
        
        printf("-> San pham: %s | So luong ton kho: %d\n", sp->TenSP, sp->SoLuong);
        printf("Nhap so luong can ban: ");
        while (scanf("%d", &soLuongBan) != 1 || soLuongBan <= 0) {
            printf("So luong ban khong hop le. Nhap lai: ");
            clear_input_buffer();
        }
        clear_input_buffer();
        
        if (soLuongBan > sp->SoLuong) {
            printf("-> KHONG CON DU HANG! Chi con %d san pham.\n", sp->SoLuong);
            return;
        }

        sp->SoLuong -= soLuongBan;
        
        DoanhThu += (sp->GiaBan - sp->GiaNhap) * soLuongBan;
        
        printf("-> Ban thanh cong %d san pham %s.\n", soLuongBan, sp->TenSP);
        printf("-> So luong ton kho con lai: %d.\n", sp->SoLuong);

    } else {
        printf("-> Khong tim thay san pham co Ma: %s\n", maCanBan);
    }
}

void hienThiDoanhThu() {
    printf("\n--- CHUC NANG 8: DOANH THU HIEN TAI ---\n");
    printf("-> Doanh thu (Loi nhuan gop) hien tai la: %.0f VND.\n", DoanhThu);
    printf("   (Doanh thu = Tong Gia Ban - Tong Gia Nhap cho cac giao dich da thuc hien)\n");
}

int main() {
    int luaChon;

    do {
        printf("\n================= MENU QUAN LY SAN PHAM (C) ================\n");
        printf("1. Nhap so luong va thong tin san pham (Them moi loai SP).\n");
        printf("2. Hien thi danh sach san pham.\n");
        printf("3. Nhap san pham (Tang so luong ton kho).\n");
        printf("4. Cap nhat thong tin san pham.\n");
        printf("5. Sap xep san pham theo gia (tang/giam).\n");
        printf("6. Tim kiem san pham.\n");
        printf("7. Ban san pham.\n");
        printf("8. Doanh thu hien tai.\n");
        printf("9. Thoat\n");
        printf("----------------------------------------------------------\n");
        printf("=> Lua chon cua ban: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le. Vui long nhap so (1-9).\n");
            clear_input_buffer();
            luaChon = 0;
            continue;
        }
        clear_input_buffer();

        switch (luaChon) {
            case 1:
                nhapDanhSachSPMoi();
                break;
            case 2:
                hienThiDanhSachSP();
                break;
            case 3:
                nhapThemSoLuong();
                break;
            case 4:
                capNhatThongTin();
                break;
            case 5:
                sapXepTheoGia();
                break;
            case 6:
                timKiemSanPham();
                break;
            case 7:
                banSanPham();
                break;
            case 8:
                hienThiDoanhThu();
                break;
            case 9:
                printf("\n----------------------------------------------------------\n");
                printf("-> Chuong trinh ket thuc. Tam biet!\n");
                printf("----------------------------------------------------------\n");
                break;
            default:
                printf("-> Lua chon khong hop le. Vui long chon tu 1 den 9.\n");
                break;
        }
    } while (luaChon != 9);

    return 0;
}
