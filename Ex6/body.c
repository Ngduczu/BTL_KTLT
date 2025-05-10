#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void read_data(int *n, int *m, double **a, double **b) {
    FILE *rf = fopen("input_Ex6.txt", "r");
    if (!rf) {
        printf("Khong the mo file input.\n");
        exit(1);
    }

    fscanf(rf, "%d", n);
    fscanf(rf, "%d", m);

    *a = (double*)malloc((*n) * sizeof(double));
    *b = (double*)malloc((*m) * sizeof(double));

    for (int i = 0; i < *n; i++) fscanf(rf, "%lf", &(*a)[i]);
    for (int i = 0; i < *m; i++) fscanf(rf, "%lf", &(*b)[i]);

    fclose(rf);
}

void cal_S(int n, int m, double *a, double *b) {
    printf("Nhap hai so k va r: ");
    double k, r; 
    scanf("%lf %lf", &k, &r);

    double Ak = 0, Qr = 0;

    for (int i = 0; i < n; i++) Ak += a[i] * pow(k, i);

    for (int i = 0; i < m; i++) Qr += b[i] * pow(r, i);

    printf("A(k) = %.2lf\nQ(r) = %.2lf\n", Ak, Qr);
}

void coef_S(int n, int m, double *a, double *b) {
    printf("He so cua S(x):\n");

    for (int i = 0; i < ((m > n) ? m : n); i++) {
        double tmp = 0;

        if (i < n) tmp += a[i];
        if (i < m) tmp += b[i];

        printf("%.2lf ", tmp);
    }
    printf("\n");
}
