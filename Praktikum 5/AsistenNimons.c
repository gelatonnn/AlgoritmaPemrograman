//Kodenya masi 90 ges, lg aing coba benerin biar 100

#include "AsistenNimons.h"

void MakeEmpty(ListNilaiNimons *L){
    (*L).Neff = 0;
}

int NbElmt(ListNilaiNimons L){
    return L.Neff;
}

int MaxNbEl(ListNilaiNimons L){
    return MAX_CAPACITY;
}

IdxType GetFirstIdx(ListNilaiNimons L){
    return 0;
}

IdxType GetLastIdx(ListNilaiNimons L){
    return L.Neff-1;
}

ElType GetElmt(ListNilaiNimons L, IdxType i){
    return L.daftar[i];
}

void SetTab(ListNilaiNimons Lin, ListNilaiNimons *Lout){
    (*Lout).Neff = Lin.Neff;
    for(int i = 0; i < Lin.Neff; i++){
    (*Lout).daftar[i] = Lin.daftar[i];
    }
}

void SetEl(ListNilaiNimons *L, IdxType i, ElType v){
    (*L).daftar[i] = v;
    if ((*L).Neff < i+1){
    (*L).Neff = i+1;
    }
}

void SetNeff(ListNilaiNimons *L, IdxType N){
    (*L).Neff = N;
}

boolean IsIdxValid(ListNilaiNimons L, IdxType i){
    return i >= GetFirstIdx(L) && i < MAX_CAPACITY;
}

boolean IsIdxEff(ListNilaiNimons L, IdxType i){
    return i >= GetFirstIdx(L) && i <= GetLastIdx(L);
}

boolean IsEmpty(ListNilaiNimons L){
    return L.Neff == 0;
}

boolean IsFull(ListNilaiNimons L){
    return L.Neff == MAX_CAPACITY;
}

void PrintIsi(ListNilaiNimons L){
    if(!IsEmpty(L)){
        for(int i = 0; i<L.Neff; i++){
            printf("%s - %d - %d\n", L.daftar[i].nama, L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }else{
        printf("List Kosong\n");
    }
}

ElType MakeNilai(char *nama, int prakke, int nilai){
    ElType data;
    strcpy(data.nama, nama);
    data.praktikum = prakke;
    data.nilai = nilai;
    return data;
}

float AvgNilaiNama(ListNilaiNimons L, char *nama){
    float count = 0;
    float total = 0;
    for(int i = 0; i<L.Neff; i++){
        if(strcmp(L.daftar[i].nama,nama) == 0){
            total += L.daftar[i].nilai;
            count++;
        }
    }
    if(count>0){
        float average = total/count;
        return average;
    }else{
        return 0;
    }
}

int MaxNilaiNama(ListNilaiNimons L, char *nama){
    int max = -1;

    for(int i = 0; i<L.Neff; i++){
        if(strcmp(L.daftar[i].nama, nama) == 0){
            if(L.daftar[i].nilai > max){
                max = L.daftar[i].nilai;
            }
        }
    }
    return max;
}

int MinNilaiNama(ListNilaiNimons L, char *nama){
    int min = 101;

    for(int i = 0; i<L.Neff; i++){
        if(strcmp(L.daftar[i].nama, nama) == 0){
            if(L.daftar[i].nilai < min){
                min = L.daftar[i].nilai;
            }
        }
    }
    return min;
}

float AvgNilai(ListNilaiNimons L){
    if(L.Neff == 0){
        return 0;
    }
    float count = 0;
    float total = 0;
    for(int i = 0; i<L.Neff; i++){
        total += L.daftar[i].nilai;
        count++;
    }

    if(count>0){
        float average = total/count;
        return average;
    }else{
        return 0;
    }
    
}

int MaxNilai(ListNilaiNimons L){
    int max = -1;

    for(int i = 0; i<L.Neff; i++){
        
        if(L.daftar[i].nilai > max){
            max = L.daftar[i].nilai;
        }
        
    }
    return max;
}

int MinNilai(ListNilaiNimons L){
    int min = 101;

    for(int i = 0; i<L.Neff; i++){
        if(L.daftar[i].nilai < min){
                min = L.daftar[i].nilai;
            }
    }
    return min;
}

int CountTotalPraktikum(ListNilaiNimons L){
    int list_temp[MAX_CAPACITY] = {0};
    int unique = 0;
    for(int i = 0; i<L.Neff; i++){
        list_temp[L.daftar[i].praktikum]++;
    }

    for(int i = 0; i<MAX_CAPACITY; i++){
        if(list_temp[i]!=0){
            unique++;
        }
    }
    return unique;
}

void DisplayStatistic(ListNilaiNimons L){
    printf("- Total praktikum: %d\n- Rata-rata: %.2f\n- Nilai maksimum: %d\n- Nilai minimum: %d\n", CountTotalPraktikum(L), AvgNilai(L), MaxNilai(L), MinNilai(L));
}

void DisplayStatisticNimons(ListNilaiNimons L, char *nama){
    printf("Nama: %s\n", nama);
    for(int i = 0; i<L.Neff; i++){
        if(strcmp(nama, L.daftar[i].nama) == 0){
            printf("Praktikum %d: %d\n",L.daftar[i].praktikum , L.daftar[i].nilai);
        }
    }

    printf("Rata-rata: %.2f\n", AvgNilaiNama(L, nama));
    printf("Nilai maksimum: %d\n",MaxNilaiNama(L,nama));
    printf("Nilai minimum: %d\n",MinNilaiNama(L,nama));
    printf("Nilai akhir: %c", KonversiNilai(AvgNilaiNama(L,nama)));

}

char KonversiNilai(int nilai){
    if(nilai >= 80){
        return 'A';
    }else if(nilai>=65){
        return 'B';
    }else if(nilai>=50){
        return 'C';
    }else if(nilai>=35){
        return 'D';
    }else if(nilai>=0){
        return 'E';
    }else{
        return 'I';
    }
}
