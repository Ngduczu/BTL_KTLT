#include <stdio.h>
#include <stdlib.h>
#include "bai6F.h"
#include "source_bai6F.c"

void main_6F() {
    int bacA, bacB;
    double *heSoA = NULL, *heSoB = NULL;
    docDuLieu6F(&bacA, &bacB, &heSoA, &heSoB);

    tinhGiaTriTai6F(bacA, bacB, heSoA, heSoB);
    tinhHeSoTong6F(bacA, bacB, heSoA, heSoB);

    free(heSoA);
    free(heSoB);
}

