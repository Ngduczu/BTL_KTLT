#ifndef BAI3F_H
#define BAI3F_H

#include <stdio.h>

void nhapMaTranTuBanPhim(float ***matrix, int *n, int *m);
void nhapMaTranTuFileText(float ***matrix, int *n, int *m, FILE *finp);
void inMaTranRaManHinh(float **matrix, int n, int m);
void xuatMaTranRaFileText(float **matrix, int n, int m, FILE *fout);
void ghiMaTranVaoFileNhiPhan(float **matrix, int n, int m, FILE *fout);
void nhapMaTranTuFileNhiPhan(float ***matrix, int *n, int *m, FILE *finp);

#endif

