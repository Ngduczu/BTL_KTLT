#ifndef HEADER_H
#define HEADER_H

struct nv {
    int mnv;
    char hoten[30];
    char phong;
    int luong;
};

void read_data(int *n, struct nv **ds);
void output_ds(int n, struct nv *ds);
void max_salary(int n, struct nv *ds);
void cnt_staff(int n, struct nv *ds);
void write_ans(int n, struct nv *ds);

#endif
