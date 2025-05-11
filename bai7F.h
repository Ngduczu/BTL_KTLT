#ifndef BAI7F_H
#define BAI7F_H

struct NhanVien {
    int maNV;
    char hoTen[30];
    char phong;
    int luong;
};

void docDuLieu7F(int *n, struct NhanVien **ds);
void inDanhSach7F(int n, struct NhanVien *ds);
void inLuongCaoNhat7F(int n, struct NhanVien *ds);
void demNhanVienMoiPhong7F(int n, struct NhanVien *ds);
void ghiFileKetQua7F(int n, struct NhanVien *ds);

#endif

