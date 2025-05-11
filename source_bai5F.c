#include <stdio.h>
#include <stdlib.h>
#include "bai5F.h"

void nhapTuBanPhim5F(int *n, point3D **list)
{
    int i;
    printf("Nhap so diem: ");
    scanf("%d", n);

    *list = (point3D *)malloc(*n * sizeof(point3D));
    if (*list == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }

    for (i = 0; i < *n; i++)
    {
        printf("Nhap toa do diem thu %d (x y z): ", i + 1);
        scanf("%f %f %f", &((*list)[i].x), &((*list)[i].y), &((*list)[i].z));
    }
}

void ghiFileText5F(char *filename, int n, point3D *list)
{
    FILE *f;
    int i;

    f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Khong mo duoc file.\n");
        return;
    }
    fprintf(f, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(f, "%.2f %.2f %.2f\n", list[i].x, list[i].y, list[i].z);
    }
    fclose(f);
}

void docFileText5F(char *filename, int *n, point3D **list)
{
    FILE *f;
    int i;

    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Khong mo duoc file.\n");
        return;
    }
    fscanf(f, "%d", n);
    *list = (point3D *)malloc(*n * sizeof(point3D));
    if (*list == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    for (i = 0; i < *n; i++)
    {
        fscanf(f, "%f %f %f", &(*list)[i].x, &(*list)[i].y, &(*list)[i].z);
    }
    fclose(f);
}

void ghiFileNhiPhan5F(char *filename, int n, point3D *list)
{
    FILE *f;

    f = fopen(filename, "wb");
    if (f == NULL)
    {
        printf("Khong mo duoc file nhi phan.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, f);
    fwrite(list, sizeof(point3D), n, f);
    fclose(f);
}

void docFileNhiPhan5F(char *filename, int *n, point3D **list)
{
    FILE *f;

    f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("Khong mo duoc file nhi phan.\n");
        return;
    }
    fread(n, sizeof(int), 1, f);
    *list = (point3D *)malloc(*n * sizeof(point3D));
    if (*list == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    fread(*list, sizeof(point3D), *n, f);
    fclose(f);
}

void inDanhSach5F(int n, point3D *list)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Diem %d: (%.2f, %.2f, %.2f)\n", i + 1, list[i].x, list[i].y, list[i].z);
    }
}

