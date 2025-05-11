#include <stdio.h>
#include <stdlib.h>
#include "bai7F.h"
#include "source_bai7F.c"

void main_7F() {
    int soNhanVien;
    struct NhanVien *ds = NULL;

    docDuLieu7F(&soNhanVien, &ds);

    inDanhSach7F(soNhanVien, ds);
    inLuongCaoNhat7F(soNhanVien, ds);
    demNhanVienMoiPhong7F(soNhanVien, ds);
    ghiFileKetQua7F(soNhanVien, ds);

    free(ds);
}

