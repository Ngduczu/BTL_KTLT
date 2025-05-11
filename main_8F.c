#include <stdio.h>
#include <stdlib.h>
#include "bai8F.h"
#include "source_bai8F.c"
void main_8F() {
    int soDong, soCot;
    int **maTran;
    int i;

    maTran = NULL;

    docMaTran(&soDong, &soCot, &maTran);
    tinhTichPhanTuLe(soDong, soCot, maTran);
    timPhanTuChanLonNhat(soDong, soCot, maTran);
    tinhTongChiaHetCho7(soDong, soCot, maTran);

    for (i = 0; i < soDong; i++) {
        free(maTran[i]);
    }
    free(maTran);

}

