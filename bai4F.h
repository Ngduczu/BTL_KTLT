#ifndef BAI4F_H
#define BAI4F_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ThiSinh {
    char Hoten[50];
    float Toan;
    float Ly;
    float Hoa;
    struct ThiSinh* Next;
} ThiSinh;

ThiSinh* taoThiSinh(char hoten[], float toan, float ly, float hoa);
void boSungDau(ThiSinh** head, char hoten[], float toan, float ly, float hoa);
void boSungCuoi(ThiSinh** head, char hoten[], float toan, float ly, float hoa);
void nhapDanhSach(ThiSinh** head, int n);
void inDanhSach(ThiSinh* head);
void xuatFileNhiPhan(ThiSinh* head, const char* filename);
void xuatFileVanBan(ThiSinh* head, const char* filename);
void nhapTuFileNhiPhan(ThiSinh** head, const char* filename);
void nhapTuFileVanBan(ThiSinh** head, const char* filename);
void timToanCaoNhat(ThiSinh* head);
void xoaLyThapNhat(ThiSinh** head);
void giaiPhongDanhSach(ThiSinh** head);

#endif
