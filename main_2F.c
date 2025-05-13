#include<stdio.h>
#include<stdlib.h>
#include"bai2F.h"
#include"source_bai2F.c"


void main_2F()
{
	int n; 
	danhsach *hang = fnew(&n);
	if(!hang) return;
	//nhap danh sach
	printf("\n---------------------------------------");
	nhap_hang_hoa(hang, n);
	//Xuat Danh Sach
	printf("\n---------------------------------------");
	xuat_hang_hoa(hang, n);
	//ghi danh sach ra file
	printf("\n---------------------------------------");
	char name_file[30];
	printf("\nNhap Ten File Muon Ghi: "); scanf("%s", name_file);
	ghiFlie(name_file, hang, n);
	//ham tinh tong all so luong hang hoa 
	printf("\n---------------------------------------");
	sum_soLuong(hang, n);
	//ham tìm kiếm theo name hàng hóa
	printf("\n---------------------------------------");
	getchar();
	printf("\nNhap Ten Muon Tim La: ");
	char name_find[50]; fgets(name_find, 50, stdin); name_find[strcspn(name_find, "\n")] = '\0';
	find(hang, n, name_find);
	//sắp xếp theo name hàng và in ra file nhị phân(file này sẽ là file ở trên)
	printf("\n---------------------------------------\n");
	sort(hang, n);//sắp xếp 
	outp_nhiphan(name_file, hang, n);//đọc xuất file
}
