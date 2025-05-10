#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nv {
    int mnv;
    char hoten[30], phong;
    int luong;
};
void read_data(int *n, struct nv **ds) {
    FILE *rf = fopen("input_Ex7.txt","r");
    fscanf(rf,"%d ",n);
    *ds = (struct nv*)malloc((*n)*(sizeof(struct nv)));
    for (int i = 0; i < (*n); i++) {
        fscanf(rf,"%d ",&(*ds)[i].mnv);
        fgets((*ds)[i].hoten,sizeof((*ds)[i].hoten),rf);
        (*ds)[i].hoten[strcspn((*ds)[i].hoten,"\n")] = 0;
        fscanf(rf,"%c ",&(*ds)[i].phong);
        fscanf(rf,"%d ",&(*ds)[i].luong);
    }
    fclose(rf);
}
void output_ds(int n, struct nv *ds) {
    printf("Danh sach thong tin cua nhan vien:\n");
    for (int i = 0; i < n; i++) {
        printf("MNV: %d\n",ds[i].mnv);
        printf("Ho ten: %s Phong: %c\n",ds[i].hoten,ds[i].phong);
        printf("Luong: %d\n",ds[i].luong);
    }
    printf("\n");
}
void max_salary(int n, struct nv *ds) {
    int luongmax = 0;
    for (int i = 0; i < n; i++) luongmax = (luongmax > ds[i].luong) ? luongmax : ds[i].luong;
    printf("Danh sach nhan vien co luong cao nhat:\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].luong == luongmax) {
            printf("MNV: %d\n",ds[i].mnv);
            printf("Ho ten: %s Phong: %c\n",ds[i].hoten,ds[i].phong);
            printf("Luong: %d\n",ds[i].luong);
        }
    }
    printf("\n");
}
void cnt_staff(int n, struct nv *ds) {
    int *sl = (int*)calloc(4,sizeof(int));
    for (int i = 0; i < n; i++) sl[ds[i].phong-'A']++;
    for (int i = 0; i < 4; i++) {
        printf("So luong nhan vien o phong %c: %d\n",'A'+i,sl[i]);
    }
    free(sl);
}
void woutput_ds(FILE *wf, int n, struct nv *ds) {
    fprintf(wf,"Danh sach thong tin cua nhan vien:\n");
    for (int i = 0; i < n; i++) {
        fprintf(wf,"MNV: %d\n",ds[i].mnv);
        fprintf(wf,"Ho ten: %s Phong: %c\n",ds[i].hoten,ds[i].phong);
        fprintf(wf,"Luong: %d\n",ds[i].luong);
    }
    fprintf(wf,"\n");
}
void wmax_salary(FILE *wf, int n, struct nv *ds) {
    int luongmax = 0;
    for (int i = 0; i < n; i++) luongmax = (luongmax > ds[i].luong) ? luongmax : ds[i].luong;
    fprintf(wf,"Danh sach nhan vien co luong cao nhat:\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].luong == luongmax) {
            fprintf(wf,"MNV: %d\n",ds[i].mnv);
            fprintf(wf,"Ho ten: %s Phong: %c\n",ds[i].hoten,ds[i].phong);
            fprintf(wf,"Luong: %d\n",ds[i].luong);
        }
    }
    fprintf(wf,"\n");
}
void wcnt_staff(FILE *wf,int n, struct nv *ds) {
    int *sl = (int*)calloc(4,sizeof(int));
    for (int i = 0; i < n; i++) sl[ds[i].phong-'A']++;
    for (int i = 0; i < 4; i++) {
        fprintf(wf,"So luong nhan vien o phong %c: %d\n",'A'+i,sl[i]);
    }

    free(sl);
}
void write_ans(int n, struct nv *ds) {
    FILE *wf = fopen("output_Ex7.txt","w");
    woutput_ds(wf,n,ds);
    wmax_salary(wf,n,ds);
    wcnt_staff(wf,n,ds);
    fclose(wf);
}
int main() {
    int n;
    struct nv *ds = NULL;
    read_data(&n,&ds);
    // 1)
    output_ds(n,ds);
    // 2)
    max_salary(n,ds);
    // 3)
    cnt_staff(n,ds);
    // 4)
    write_ans(n,ds);
    
    free(ds);
}