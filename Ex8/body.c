#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void question_1(int *m, int *n, int ***matrix) {
    FILE *rf = fopen("input_Ex8.txt", "r");
    fscanf(rf, "%d %d", m, n);
    *matrix = (int**)malloc((*m) * sizeof(int*));
    for (int i = 0; i < (*m); i++) {
        (*matrix)[i] = (int*)malloc((*n) * sizeof(int));
        for (int j = 0; j < (*n); j++) fscanf(rf, "%d", &(*matrix)[i][j]);
    }
    fclose(rf);
}

void question_2(int m, int n, int **matrix) {
    int Q = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] & 1) Q *= matrix[i][j];
        }
    }
    printf("Tich cac phan tu le: %d\n", Q);
}

void question_3(int m, int n, int **matrix) {
    int pi = -1, pj = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 == 0) {
                if (pi == -1 && pj == -1) pi = i, pj = j;
                else if (matrix[i][j] > matrix[pi][pj]) pi = i, pj = j;
            }
        }
    }
    printf("Phan tu chan lon nhat cua ma tran co vi tri: (%d,%d)\n", pi + 1, pj + 1);
}

void question_4(int m, int n, int **matrix) {
    int S = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 7 == 0) S += matrix[i][j];
        }
    }
    printf("Tong cac phan tu chia het cho 7: %d\n", S);
}
