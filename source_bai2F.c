#include<stdlib.h>
#include<stdio.h>
#include"bai2F.h"
#include<string.h>
void nhap_hang_hoa(danhsach hang[], int n)
{
	int i;
	for(i=0; i<n; ++i)
	{
		printf("\nHang %d:\n", i+1);
		printf("Nhap Ten Hang: "); fgets(hang[i].ten_hang, 50, stdin);hang[i].ten_hang[strcspn(hang[i].ten_hang, "\n")] = '\0';
		printf("Nhap Loai Hang: "); scanf("%c", &hang[i].loaiHang); 
		printf("Nhap So Luong: "); scanf("%d", &hang[i].soLuong); getchar();
	}
}

void xuat_hang_hoa(danhsach hang[], int n)
{
	printf("\nDANH SACH\n");
	int i;
	for(i=0; i<n; ++i)
	{
		printf("\nHang %d: ", i+1);
		printf("Ten Hang: %s", hang[i].ten_hang);
		printf("              Loai Hang: %c", hang[i].loaiHang); 
		printf("              So Luong: %d", hang[i].soLuong); 
	}
}
//cấp phát bộ nhớ
danhsach *fnew(int *n)
{
	printf("\nNhap So Hang: ");
	scanf("%d", n); 
	getchar();
	danhsach *p = (danhsach*)malloc((*n) * sizeof(danhsach));
	if(!p) return NULL;
	return p;
}
//ghi danh sách ra file
void ghiFlie(const char *name, danhsach hang[], int n)
{
	FILE *f = fopen(name, "ab");
	if(!f)
	{
		printf("\nMo Flie That Bai!");
		return;
	}
	//
	fwrite(hang, sizeof(hang[0]), n, f);
	printf("Da Ghi File!");
	fclose(f);
}
//ham tinh tong all so luong hang hoa 
void sum_soLuong(danhsach hang[], int n)
{
	int sum = 0;
	int i;
	for(i=0; i<n; ++i) sum += hang[i].soLuong;
	printf("\nTong So Luong ALL Hang Hoa La: %d", sum);
}
//ham tìm kiếm theo name hàng hóa
void find(danhsach hang[], int n, char name[50])
{
	int i;
	printf("Tim Kiem %s: ",name);
	for(i=0; i<n; ++i)
	{
		if(!strcmp(name, hang[i].ten_hang)) 
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

//sắp xếp theo name hàng 
void sort(danhsach hang[], int n)
{
	int i;
	for(i=0; i<n-1; ++i)
	{
		int j;
		for(j= i+1; j<n; ++j)
		{
			if(strcmp(hang[j].ten_hang, hang[j].ten_hang) > 0)
			{
				danhsach temp = hang[j];
				hang[j] = hang[i];
				hang[i] = temp;
			}
		}
	}
}

//xuất ra file nhị phân
void outp_nhiphan(const char *name, danhsach hang[], int n)
{
	//trước tiên ghi đè danh sách mới sắp xếp vào file nhi phân
	FILE *f = fopen(name, "wb");
	if(!f)
	{
		printf("\nMo Flie That Bai!");
		return;
	}
	fwrite(hang, sizeof(danhsach), n, f);
	printf("Da ghi vao file nhi phan %s\n", name);
	fclose(f);
}










