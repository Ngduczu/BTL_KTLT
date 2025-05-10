#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    int n;
    struct nv *ds = NULL;

    read_data(&n, &ds);

    output_ds(n, ds);

    max_salary(n, ds);

    cnt_staff(n, ds);

    write_ans(n, ds);

    free(ds);

    return 0;
}
