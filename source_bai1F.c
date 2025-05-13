#include<stdio.h>
#include "bai1F.h"
#include<stdlib.h>

void ghiFile(const char *name)
{
	FILE *f = fopen(name, "a");
	if(!f) return;
	
	char data[50];
	printf("Du lieu muon ghi vao file la: ");
	fgets(data, sizeof(data), stdin);
	
	fprintf(f, "%s", data); //ghi thông tin data vào file test.txt	
	fclose(f);
}

void docFile(const char *name)
{
	FILE *f = fopen(name, "r");
	if(!f) return;
	
	
	char data[100];
	printf("%s", name);
	while(fgets(data, sizeof(data), f))
	{
		printf("%s", data);	
	}
		
	fclose(f);
}

void menu()
{
	while(1)
	{
		printf("\nChon 0 De Thoat!");
		printf("\nChon 1 De Ghi File");
		printf("\nChon 2 De Doc File");
		printf("\nCHOOSE LA: ");
		int lc; scanf("%d", &lc);
		if(lc == 0) return;
		if(lc == 1)
		{
			//ghi file
			printf("Nhap ten file ban muon ghi: ");
			char name[50];
			scanf("%s", &name);
			getchar();
			ghiFile(name);//ghi file
		}
		else
		{
			//doc file
			printf("Nhap ten file ban muon doc: ");
			char name[50];
			scanf("%s", &name);
			getchar();
			docFile(name);
		}
	}
}
