#ifndef BAI2F_H
#define BAI2F_H
struct danhsach
{
	char ten_hang[50]; //mac dinh ten ham khong co cach vi de bai ko noi gi
	int soLuong;
	char loaiHang;//A B C
};
typedef struct danhsach danhsach;
danhsach *fnew(int *n);
void nhap_hang_hoa(danhsach hang[], int n);
void xuat_hang_hoa(danhsach hang[], int n);
void ghiFlie(const char *name, danhsach hang[], int n);
void sum_soLuong(danhsach hang[], int n);
void find(danhsach hang[], int n, char name[50]);
void sort(danhsach hang[], int n);
void outp_nhiphan(const char *name, danhsach hang[], int n);
#endif // HEADER_H
