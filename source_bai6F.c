#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bai6F.h"

void docDuLieu6F(int *bacA, int *bacB, double **heSoA, double **heSoB) {
    int i;
    FILE *file = fopen("input_6.txt", "r");
    if (!file) {
        printf("Khong the mo file input.\n");
        exit(1);
    }

    fscanf(file, "%d", bacA);
    fscanf(file, "%d", bacB);

    *heSoA = (double*)malloc((*bacA) * sizeof(double));
    *heSoB = (double*)malloc((*bacB) * sizeof(double));

    for (i = 0; i < *bacA; i++) fscanf(file, "%lf", &(*heSoA)[i]);
    for (i = 0; i < *bacB; i++) fscanf(file, "%lf", &(*heSoB)[i]);

    fclose(file);
}

void tinhGiaTriTai6F(int bacA, int bacB, double *heSoA, double *heSoB) {
    int i;
    printf("Nhap hai so k va r: ");
    double k, r;
    scanf("%lf %lf", &k, &r);

    double giaTriA = 0, giaTriB = 0;

    for (i = 0; i < bacA; i++) giaTriA += heSoA[i] * pow(k, i);
    for (i = 0; i < bacB; i++) giaTriB += heSoB[i] * pow(r, i);

    printf("A(k) = %.2lf\nQ(r) = %.2lf\n", giaTriA, giaTriB);
}

void tinhHeSoTong6F(int bacA, int bacB, double *heSoA, double *heSoB) {
    int i;
    printf("He so cua tong da thuc A(x) + B(x):\n");

    for (i = 0; i < ((bacB > bacA) ? bacB : bacA); i++) {
        double tong = 0;

        if (i < bacA) tong += heSoA[i];
        if (i < bacB) tong += heSoB[i];

        printf("%.2lf ", tong);
    }
    printf("\n");
}

