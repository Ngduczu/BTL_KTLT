#ifndef BAI5F_H
#define BAI5F_H

typedef struct {
    float x, y, z;
} point3D;

void nhapTuBanPhim5F(int *n, point3D **list);
void docFileText5F(char filename[], int *n, point3D **list);
void ghiFileText5F(char filename[], int n, point3D *list);
void docFileNhiPhan5F(char filename[], int *n, point3D **list);
void ghiFileNhiPhan5F(char filename[], int n, point3D *list);
void inDanhSach5F(int n, point3D *list);
#endif

