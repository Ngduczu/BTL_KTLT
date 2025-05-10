#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    int m, n, **matrix = NULL;
    
    question_1(&m, &n, &matrix);

    question_2(m, n, matrix);

    question_3(m, n, matrix);

    question_4(m, n, matrix);

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}