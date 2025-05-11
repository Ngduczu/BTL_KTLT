#include "bai4F.h"

ThiSinh* taoThiSinh(char hoten[], float toan, float ly, float hoa) {
    ThiSinh* ts = (ThiSinh*)malloc(sizeof(ThiSinh));
    if (ts == NULL) {
        exit(1);
    }
    strcpy(ts->Hoten, hoten);
    ts->Toan = toan;
    ts->Ly = ly;
    ts->Hoa = hoa;
    ts->Next = NULL;
    return ts;
}

void boSungDau(ThiSinh** head, char hoten[], float toan, float ly, float hoa) {
    ThiSinh* newTS = taoThiSinh(hoten, toan, ly, hoa);
    newTS->Next = *head;
    *head = newTS;
}

void boSungCuoi(ThiSinh** head, char hoten[], float toan, float ly, float hoa) {
    ThiSinh* newTS = taoThiSinh(hoten, toan, ly, hoa);
    
    if (*head == NULL) {
        *head = newTS;
        return;
    }
    
    ThiSinh* last = *head;
    while (last->Next != NULL) {
        last = last->Next;
    }
    last->Next = newTS;
}

void nhapDanhSach(ThiSinh** head, int n) {
    char hoten[50];
    float toan, ly, hoa;
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin thi sinh thu %d:\n", i+1);
        printf("Ho ten: "); 
        fflush(stdin);
        fgets(hoten, 50, stdin);
        hoten[strcspn(hoten, "\n")] = 0;
        
        printf("Diem Toan: "); scanf("%f", &toan);
        printf("Diem Ly: "); scanf("%f", &ly);
        printf("Diem Hoa: "); scanf("%f", &hoa);
        
        boSungCuoi(head, hoten, toan, ly, hoa);
    }
}

void inDanhSach(ThiSinh* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    printf("\n%-30s %-10s %-10s %-10s\n", "Ho ten", "Toan", "Ly", "Hoa");
    printf("------------------------------------------------------------\n");
    
    ThiSinh* current = head;
    while (current != NULL) {
        printf("%-30s %-10.2f %-10.2f %-10.2f\n", 
               current->Hoten, current->Toan, current->Ly, current->Hoa);
        current = current->Next;
    }
}

void xuatFileNhiPhan(ThiSinh* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }
    
    ThiSinh* current = head;
    while (current != NULL) {
        fwrite(current, sizeof(ThiSinh), 1, file);
        current = current->Next;
    }
    
    fclose(file);
}

void xuatFileVanBan(ThiSinh* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }
    
    fprintf(file, "%-30s %-10s %-10s %-10s\n", "Ho ten", "Toan", "Ly", "Hoa");
    fprintf(file, "------------------------------------------------------------\n");
   
    ThiSinh* current = head;
    while (current != NULL) {
        fprintf(file, "%-30s %-10.2f %-10.2f %-10.2f\n", 
                current->Hoten, current->Toan, current->Ly, current->Hoa);
        current = current->Next;
    }  
    fclose(file);
}

void nhapTuFileNhiPhan(ThiSinh** head, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return;
    }
    int n, i;
    ThiSinh ts;
    fread(&n, sizeof(int), 1, file);
    for (i = 0; i < n; ++i) {
        fread(&ts, sizeof(ThiSinh), 1, file);
        boSungCuoi(head, ts.Hoten, ts.Toan, ts.Ly, ts.Hoa);
    }
    fclose(file);
}

void nhapTuFileVanBan(ThiSinh** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }
    int n;
    fscanf(file, "%d", &n);
	fgetc(file);
    char hoten[50];
    float toan, ly, hoa;
	int i;
    for (i = 0; i < n; ++i) {
    	fgets(hoten, 50, file);
    	hoten[strcspn(hoten, "\n")] = '\0';
        fscanf(file, "%f %f %f", &toan, &ly, &hoa);
        fgetc(file);
        boSungCuoi(head, hoten, toan, ly, hoa);
    }
    fclose(file);
}



void timToanCaoNhat(ThiSinh* head) {
    if (head == NULL) {
        return;
    }
    
    float maxToan = head->Toan;
    ThiSinh* current = head->Next;
    
    while (current != NULL) {
        if (current->Toan > maxToan) {
            maxToan = current->Toan;
        }
        current = current->Next;
    }
    
    printf("\nCac thi sinh co diem Toan cao nhat (%.2f):\n", maxToan);
    printf("%-30s %-10s %-10s %-10s\n", "Ho ten", "Toan", "Ly", "Hoa");
    printf("------------------------------------------------------------\n");
    
    current = head;
    while (current != NULL) {
        if (current->Toan == maxToan) {
            printf("%-30s %-10.2f %-10.2f %-10.2f\n", 
                   current->Hoten, current->Toan, current->Ly, current->Hoa);
        }
        current = current->Next;
    }
}

void xoaLyThapNhat(ThiSinh** head) {
    if (*head == NULL) {
        return;
    }
    
    float minLy = (*head)->Ly;
    ThiSinh* current = (*head)->Next;
    
    while (current != NULL) {
        if (current->Ly < minLy) {
            minLy = current->Ly;
        }
        current = current->Next;
    }
    
    ThiSinh* prev = NULL;
    current = *head;
    
    while (current != NULL) {
        if (current->Ly == minLy) {
            if (prev == NULL) {
                *head = current->Next;
                free(current);
                current = *head;
            } else {
                prev->Next = current->Next;
                free(current);
                current = prev->Next;
            }
        } else {
            prev = current;
            current = current->Next;
        }
    }
}

void giaiPhongDanhSach(ThiSinh** head) {
    ThiSinh* current = *head;
    while (current != NULL) {
        ThiSinh* temp = current;
        current = current->Next;
        free(temp);
    }
    *head = NULL;
}
