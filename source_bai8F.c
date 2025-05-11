#include <stdio.h>
#include <stdlib.h>
#include "bai8F.h"

void docMaTran(int *soDong, int *soCot, int ***maTran) {
    FILE *tep;
    int i, j;

    tep = fopen("input_8.txt", "r");
    if (tep == NULL) {
        printf("Khong the mo file.\n");
        exit(1);
    }

    fscanf(tep, "%d %d", soDong, soCot);

    *maTran = (int**)malloc((*soDong) * sizeof(int*));
    for (i = 0; i < *soDong; i++) {
        (*maTran)[i] = (int*)malloc((*soCot) * sizeof(int));
        for (j = 0; j < *soCot; j++) {
            fscanf(tep, "%d", &(*maTran)[i][j]);
        }
    }

    fclose(tep);
}

void tinhTichPhanTuLe(int soDong, int soCot, int **maTran) {
    int i, j;
    int tich = 1;

    for (i = 0; i < soDong; i++) {
        for (j = 0; j < soCot; j++) {
            if (maTran[i][j] % 2 != 0) {
                tich *= maTran[i][j];
            }
        }
    }

    printf("Tich cac phan tu le: %d\n", tich);
}

void timPhanTuChanLonNhat(int soDong, int soCot, int **maTran) {
    int i, j;
    int dongMax = -1, cotMax = -1;

    for (i = 0; i < soDong; i++) {
        for (j = 0; j < soCot; j++) {
            if (maTran[i][j] % 2 == 0) {
                if (dongMax == -1) {
                    dongMax = i;
                    cotMax = j;
                } else if (maTran[i][j] > maTran[dongMax][cotMax]) {
                    dongMax = i;
                    cotMax = j;
                }
            }
        }
    }

    if (dongMax != -1) {
        printf("Phan tu chan lon nhat co vi tri: (%d, %d)\n", dongMax + 1, cotMax + 1);
    } else {
        printf("Khong co phan tu chan nao trong ma tran.\n");
    }
}

void tinhTongChiaHetCho7(int soDong, int soCot, int **maTran) {
    int i, j;
    int tong = 0;

    for (i = 0; i < soDong; i++) {
        for (j = 0; j < soCot; j++) {
            if (maTran[i][j] % 7 == 0) {
                tong += maTran[i][j];
            }
        }
    }

    printf("Tong cac phan tu chia het cho 7: %d\n", tong);
}

