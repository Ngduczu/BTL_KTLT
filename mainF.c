#include "main_1F.c"
#include "main_2F.c"
#include "main_3F.c"
#include "main_4F.c"
#include "main_5F.c"
#include "main_6F.c"
#include "main_7F.c"
#include "main_8F.c"

int main(){
	int cmd;
	do{
		printf("=======   CHON BAI TAP PHAN F   =========\n");
	int i;
	for (i = 1; i <= 8; i++)
	{
		printf("%d. Bai tap %dF\n", i, i);
	}
	printf("0. Thoat\n");
	printf("Nhap lua chon cua ban: "); scanf("%d", &cmd);
	
	switch(cmd){
		case 1:
			system("cls");
			main_1F();
			break;
		case 2:
			system("cls");
			main_2F();
			break;
		case 3:
			system("cls");
			main_3F();
			break;
		case 4:
			system("cls");
			main_4F();
			break;
		case 5:
			system("cls");
			main_5F();
			break;
		case 6:
			system("cls");
			main_6F();
			break;
		case 7:
			system("cls");
			main_7F();
			break;
		case 8:
			system("cls");
			main_8F();
			break;
		case 0:
			printf("Tam biet!!!\n");
			break;
		default:
			printf("Khong hop le.\nVui long nhap lai!\n");
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")	;
	}
	while(cmd != 0);
	return 0;
}
