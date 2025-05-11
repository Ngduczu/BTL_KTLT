#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bai7F.h"

void docDuLieu7F(int *n, struct NhanVien **ds) {
    FILE *f = fopen("input_7.txt", "r");
    int i;
    fscanf(f, "%d ", n);
    *ds = (struct NhanVien*)malloc((*n) * sizeof(struct NhanVien));
    for (i = 0; i < *n; i++) {
        fscanf(f, "%d ", &(*ds)[i].maNV);
        fgets((*ds)[i].hoTen, sizeof((*ds)[i].hoTen), f);
        (*ds)[i].hoTen[strcspn((*ds)[i].hoTen, "\n")] = 0;
        fscanf(f, "%c ", &(*ds)[i].phong);
        fscanf(f, "%d ", &(*ds)[i].luong);
    }
    fclose(f);
}

void inDanhSach7F(int n, struct NhanVien *ds) {
    int i;
    printf("Danh sach thong tin cua nhan vien:\n");
    for (i = 0; i < n; i++) {
        printf("MNV: %d\n", ds[i].maNV);
        printf("Ho ten: %s Phong: %c\n", ds[i].hoTen, ds[i].phong);
        printf("Luong: %d\n", ds[i].luong);
    }
    printf("\n");
}

void inLuongCaoNhat7F(int n, struct NhanVien *ds) {
    int max = 0, i;
    for (i = 0; i < n; i++) if (ds[i].luong > max) max = ds[i].luong;
    printf("Danh sach nhan vien co luong cao nhat:\n");
    for (i = 0; i < n; i++) {
        if (ds[i].luong == max) {
            printf("MNV: %d\n", ds[i].maNV);
            printf("Ho ten: %s Phong: %c\n", ds[i].hoTen, ds[i].phong);
            printf("Luong: %d\n", ds[i].luong);
        }
    }
    printf("\n");
}

void demNhanVienMoiPhong7F(int n, struct NhanVien *ds) {
    int *dem = (int*)calloc(4, sizeof(int));
    int i;
    for (i = 0; i < n; i++) dem[ds[i].phong - 'A']++;
    for (i = 0; i < 4; i++) {
        printf("So luong nhan vien o phong %c: %d\n", 'A' + i, dem[i]);
    }
    free(dem);
}

void ghiDanhSach7F(FILE *f, int n, struct NhanVien *ds) {
    fprintf(f, "Danh sach thong tin cua nhan vien:\n");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(f, "MNV: %d\n", ds[i].maNV);
        fprintf(f, "Ho ten: %s Phong: %c\n", ds[i].hoTen, ds[i].phong);
        fprintf(f, "Luong: %d\n", ds[i].luong);
    }
    fprintf(f, "\n");
}

void ghiLuongCaoNhat7F(FILE *f, int n, struct NhanVien *ds) {
    int max = 0;
    int i;
    for (i = 0; i < n; i++) if (ds[i].luong > max) max = ds[i].luong;
    fprintf(f, "Danh sach nhan vien co luong cao nhat:\n");
    for (i = 0; i < n; i++) {
        if (ds[i].luong == max) {
            fprintf(f, "MNV: %d\n", ds[i].maNV);
            fprintf(f, "Ho ten: %s Phong: %c\n", ds[i].hoTen, ds[i].phong);
            fprintf(f, "Luong: %d\n", ds[i].luong);
        }
    }
    fprintf(f, "\n");
}

void ghiSoLuongPhong7F(FILE *f, int n, struct NhanVien *ds) {
    int i;
    int *dem = (int*)calloc(4, sizeof(int));
    for (i = 0; i < n; i++) dem[ds[i].phong - 'A']++;
    for (i = 0; i < 4; i++) {
        fprintf(f, "So luong nhan vien o phong %c: %d\n", 'A' + i, dem[i]);
    }
    free(dem);
}

void ghiFileKetQua7F(int n, struct NhanVien *ds) {
    FILE *f = fopen("output_7.txt", "w");
    ghiDanhSach7F(f, n, ds);
    ghiLuongCaoNhat7F(f, n, ds);
    ghiSoLuongPhong7F(f, n, ds);
    fclose(f);
}

