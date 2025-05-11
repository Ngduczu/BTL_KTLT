#include <stdio.h>
#include <stdlib.h>
#include "bai3F.h"
#include "source_bai3F.c"

void main_3F() {
    float **matrix = NULL;
    int n = 0, m = 0, choice;
    FILE *finp, *fout;

    do {
        printf("\n===== MENU BAI 3F =====\n");
        printf("1. Nhap ma tran tu ban phim\n");
        printf("2. Nhap ma tran tu file van ban\n");
        printf("3. Xuat ma tran ra file van ban\n");
        printf("4. Ghi ma tran vao file nhi phan\n");
        printf("5. Doc ma tran tu file nhi phan\n");
        printf("6. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMaTranTuBanPhim(&matrix, &n, &m);
                break;

            case 2:
                finp = fopen("input.txt", "r");
                if (finp == NULL) {
                    printf("Khong mo duoc file input.txt\n");
                    break;
                }
                nhapMaTranTuFileText(&matrix, &n, &m, finp);
                fclose(finp);
                printf("Da doc ma tran tu file van ban.\n");
                break;

            case 3:
                if (matrix == NULL) {
                    printf("Chua co ma tran de xuat.\n");
                    break;
                }
                fout = fopen("output.txt", "w");
                if (fout == NULL) {
                    printf("Khong mo duoc file output.txt\n");
                    break;
                }
                xuatMaTranRaFileText(matrix, n, m, fout);
                fclose(fout);
                printf("Da xuat ma tran ra file output.txt\n");
                break;

            case 4:
                if (matrix == NULL) {
                    printf("Chua co ma tran de ghi file nhi phan.\n");
                    break;
                }
                fout = fopen("matrix.dat", "wb");
                if (fout == NULL) {
                    printf("Khong mo duoc file matrix.dat\n");
                    break;
                }
                ghiMaTranVaoFileNhiPhan(matrix, n, m, fout);
                fclose(fout);
                printf("Da ghi ma tran vao file nhi phan.\n");
                break;

            case 5:
                finp = fopen("matrix.dat", "rb");
                if (finp == NULL) {
                    printf("Khong mo duoc file matrix.dat\n");
                    break;
                }
                nhapMaTranTuFileNhiPhan(&matrix, &n, &m, finp);
                fclose(finp);
                printf("Da doc ma tran tu file nhi phan:\n");
                inMaTranRaManHinh(matrix, n, m);
                break;

            case 6:
                printf("Ket thuc chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);

    if (matrix != NULL) {
        int i;
        for (i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

