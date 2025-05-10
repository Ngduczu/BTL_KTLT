#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    int n, m;
    double *a = NULL, *b = NULL;
    read_data(&n, &m, &a, &b);

    cal_S(n, m, a, b);

    coef_S(n, m, a, b);

    free(a);
    free(b);

}
