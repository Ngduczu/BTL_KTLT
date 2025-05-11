#include <stdio.h>
#include <stdlib.h>
#include "bai5F.h"
#include "source_bai5F.c"

void main_5F()
{
    int n, nText, nBin, choice;
    point3D *dsDiem = NULL;
    point3D *docText = NULL;
    point3D *docBin = NULL;

    do {
        printf("\n==== MENU BAI 5F ====\n");
        printf("1. Nhap diem va ghi ra file text\n");
        printf("2. Doc diem tu file van ban\n");
        printf("3. Ghi diem ra file nhi phan\n");
        printf("4. Doc diem tu file nhi phan\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapTuBanPhim5F(&n, &dsDiem);
                ghiFileText5F("output_5.txt", n, dsDiem);
                printf("Diem da duoc ghi vao file 'output_5.txt'.\n");
                break;

            case 2:
                nText = 0;
                docFileText5F("input_5.txt", &nText, &docText);
                printf("\nDoc tu file van ban:\n");
                inDanhSach5F(nText, docText);
                break;

            case 3:
                ghiFileNhiPhan5F("diem.dat", n, dsDiem);
                printf("Diem da duoc ghi vao file 'diem.dat'.\n");
                break;

            case 4:
                nBin = 0;
                docFileNhiPhan5F("diem.dat", &nBin, &docBin);
                printf("\nDoc tu file nhi phan:\n");
                inDanhSach5F(nBin, docBin);
                break;

            case 5:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 5);

    free(dsDiem);
    free(docText);
    free(docBin);
}


