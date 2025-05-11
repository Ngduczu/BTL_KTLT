#include "bai4F.h"
#include "source_bai4F.c"

void hienThiMenu() {
    printf("\n===== MENU QUAN LY THI SINH 4F =====\n");
    printf("1. Nhap danh sach thi sinh tu ban phim\n");
    printf("2. In danh sach thi sinh\n");
    printf("3. Xuat danh sach ra file nhi phan\n");
    printf("4. Xuat danh sach ra file van ban\n");
    printf("5. Nhap danh sach tu file nhi phan\n");
    printf("6. Nhap danh sach tu file van ban\n");
    printf("7. Tim thi sinh co diem Toan cao nhat\n");
    printf("8. Xoa thi sinh co diem Ly thap nhat\n");
    printf("0. Thoat\n");
    printf("=================================\n");
    printf("Lua chon cua ban: ");
}

void main_4F() {
    ThiSinh* danhSach = NULL;
    int luaChon, n;
    char filename[100];
    
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                printf("Nhap so luong thi sinh: ");
                scanf("%d", &n);
                nhapDanhSach(&danhSach, n);
                break;
            case 2:
                inDanhSach(danhSach);
                break;
            case 3:
                printf("Nhap ten file nhi phan: ");
                scanf("%s", filename);
                xuatFileNhiPhan(danhSach, filename);
                break;
            case 4:
                printf("Nhap ten file van ban: ");
                scanf("%s", filename);
                xuatFileVanBan(danhSach, filename);
                break;
            case 5:
                printf("Nhap ten file nhi phan: ");
                scanf("%s", filename);
                giaiPhongDanhSach(&danhSach);
                nhapTuFileNhiPhan(&danhSach, filename);
                break;
            case 6:
                printf("Nhap ten file van ban: ");
                scanf("%s", filename);
                giaiPhongDanhSach(&danhSach);
                nhapTuFileVanBan(&danhSach, filename);
                break;
            case 7:
                timToanCaoNhat(danhSach);
                break;
            case 8:
                xoaLyThapNhat(&danhSach);
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);
    
    giaiPhongDanhSach(&danhSach);
}
