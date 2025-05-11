#include <stdio.h>
#include <stdlib.h>
#include "bai3F.h"

void nhapMaTranTuBanPhim(float ***matrix, int *n, int *m) {
    int i, j;
    printf("Nhap so hang n: ");
    scanf("%d", n);
    printf("Nhap so cot m: ");
    scanf("%d", m);

    *matrix = (float **)malloc(*n * sizeof(float *));
    for (i = 0; i < *n; i++) {
        (*matrix)[i] = (float *)malloc(*m * sizeof(float));
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            scanf("%f", &(*matrix)[i][j]);
        }
    }
}

void nhapMaTranTuFileText(float ***matrix, int *n, int *m, FILE *finp) {
    int i, j;
    fscanf(finp, "%d %d", n, m);

    *matrix = (float **)malloc(*n * sizeof(float *));
    for (i = 0; i < *n; i++) {
        (*matrix)[i] = (float *)malloc(*m * sizeof(float));
    }

    for (i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            fscanf(finp, "%f", &(*matrix)[i][j]);
        }
    }
}

void inMaTranRaManHinh(float **matrix, int n, int m) {
    int i, j;
    if (matrix == NULL) {
        printf("Ma tran chua duoc nhap.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%5.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void xuatMaTranRaFileText(float **matrix, int n, int m, FILE *fout) {
    int i, j;
    fprintf(fout, "%d %d\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fprintf(fout, "%.2f ", matrix[i][j]);
        }
        fprintf(fout, "\n");
    }
}

void ghiMaTranVaoFileNhiPhan(float **matrix, int n, int m, FILE *fout) {
    int i;
    fwrite(&n, sizeof(int), 1, fout);
    fwrite(&m, sizeof(int), 1, fout);
    for (i = 0; i < n; i++) {
        fwrite(matrix[i], sizeof(float), m, fout);
    }
}

void nhapMaTranTuFileNhiPhan(float ***matrix, int *n, int *m, FILE *finp) {
    int i;
    fread(n, sizeof(int), 1, finp);
    fread(m, sizeof(int), 1, finp);

    *matrix = (float **)malloc(*n * sizeof(float *));
    for (i = 0; i < *n; i++) {
        (*matrix)[i] = (float *)malloc(*m * sizeof(float));
        fread((*matrix)[i], sizeof(float), *m, finp);
    }
}

