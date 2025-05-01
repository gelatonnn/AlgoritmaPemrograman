#include "AsistenNimons.h"

void MakeEmpty(ListNilaiNimons *L) {
    (*L).Neff = 0;
}

int NbElmt(ListNilaiNimons L) {
    return L.Neff;
}

int MaxNbEl(ListNilaiNimons L) {
    return MAX_CAPACITY;
}

IdxType GetFirstIdx(ListNilaiNimons L) {
    return 0;
}

IdxType GetLastIdx(ListNilaiNimons L) {
    return L.Neff - 1;
}

ElType GetElmt(ListNilaiNimons L, IdxType i) {
    return L.daftar[i];
}

void SetTab(ListNilaiNimons Lin, ListNilaiNimons *Lout) {
    (*Lout).Neff = Lin.Neff;
    for (int i = 0; i < Lin.Neff; i++) {
        (*Lout).daftar[i] = Lin.daftar[i];
    }
}

void SetEl(ListNilaiNimons *L, IdxType i, ElType v) {
    (*L).daftar[i] = v;
    if ((*L).Neff < i + 1) {
        (*L).Neff = i + 1;
    }
}

void SetNeff(ListNilaiNimons *L, IdxType N) {
    (*L).Neff = N;
}

boolean IsIdxValid(ListNilaiNimons L, IdxType i) {
    return i >= GetFirstIdx(L) && i < MAX_CAPACITY;
}

boolean IsIdxEff(ListNilaiNimons L, IdxType i) {
    return i >= GetFirstIdx(L) && i <= GetLastIdx(L);
}

boolean IsEmpty(ListNilaiNimons L) {
    return L.Neff == 0;
}

boolean IsFull(ListNilaiNimons L) {
    return L.Neff == MAX_CAPACITY;
}

void PrintIsi(ListNilaiNimons L) {
    if (IsEmpty(L)) {
        printf("List kosong\n");
    } else {
        for (int i = 0; i < L.Neff; i++) {
            printf("%s - %d - %d\n", L.daftar[i].nama, L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }
}

ElType MakeNilai(char *nama, int prakke, int nilai) {
    ElType e;
    strncpy(e.nama, nama, sizeof(e.nama) - 1);
    e.nama[sizeof(e.nama) - 1] = '\0'; 
    e.praktikum = prakke;
    e.nilai = nilai;
    return e;
}

float AvgNilaiNama(ListNilaiNimons L, char *nama) {
    int total = 0;
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        if (strcmp(L.daftar[i].nama, nama) == 0) {
            total += L.daftar[i].nilai;
            count++;
        }
    }
    if (count == 0) return 0.0;
    return (float)total / count;
}

int MaxNilaiNama(ListNilaiNimons L, char *nama) {
    int max = -1;
    for (int i = 0; i < L.Neff; i++) {
        if (strcmp(L.daftar[i].nama, nama) == 0) {
            if (L.daftar[i].nilai > max) {
                max = L.daftar[i].nilai;
            }
        }
    }
    return max;
}

int MinNilaiNama(ListNilaiNimons L, char *nama) {
    int min = 101;
    boolean found = FALSE;
    for (int i = 0; i < L.Neff; i++) {
        if (strcmp(L.daftar[i].nama, nama) == 0) {
            if (L.daftar[i].nilai < min) {
                min = L.daftar[i].nilai;
            }
            found = TRUE;
        }
    }
    return found ? min : 101;
}

float AvgNilai(ListNilaiNimons L) {
    if (IsEmpty(L)) return 0.0;
    int total = 0;
    for (int i = 0; i < L.Neff; i++) {
        total += L.daftar[i].nilai;
    }
    return (float)total / L.Neff;
}

int MaxNilai(ListNilaiNimons L) {
    if (IsEmpty(L)) return -1;
    int max = L.daftar[0].nilai;
    for (int i = 1; i < L.Neff; i++) {
        if (L.daftar[i].nilai > max) {
            max = L.daftar[i].nilai;
        }
    }
    return max;
}

int MinNilai(ListNilaiNimons L) {
    if (IsEmpty(L)) return 101;
    int min = L.daftar[0].nilai;
    for (int i = 1; i < L.Neff; i++) {
        if (L.daftar[i].nilai < min) {
            min = L.daftar[i].nilai;
        }
    }
    return min;
}

int CountTotalPraktikum(ListNilaiNimons L) {
    int list_temp[MAX_CAPACITY] = {0};
    int count = 0;
    for (int i = 0; i < L.Neff; i++) {
        int prak = L.daftar[i].praktikum;
        if (list_temp[prak] == 0) {
            list_temp[prak] = 1;
            count++;
        }
    }
    return count;
}

void DisplayStatistic(ListNilaiNimons L) {
    printf("- Total praktikum: %d\n", CountTotalPraktikum(L));
    printf("- Rata-rata: %.2f\n", AvgNilai(L));
    printf("- Nilai maksimum: %d\n", MaxNilai(L));
    printf("- Nilai minimum: %d\n", MinNilai(L));
}

void DisplayStatisticNimons(ListNilaiNimons L, char *nama) {
    printf("Nama: %s\n", nama);
    for (int i = 0; i < L.Neff; i++) {
        if (strcmp(L.daftar[i].nama, nama) == 0) {
            printf("Praktikum %d: %d\n", L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }
    float avg = AvgNilaiNama(L, nama);
    int max = MaxNilaiNama(L, nama);
    int min = MinNilaiNama(L, nama);
    printf("\nRata-rata: %.2f\n", avg);
    printf("Nilai maksimum: %d\n", max);
    printf("Nilai minimum: %d\n", min);
    printf("Nilai akhir: %c\n", KonversiNilai((int)avg));
}

char KonversiNilai(int nilai) {
    if (nilai >= 80) return 'A';
    else if (nilai >= 65) return 'B';
    else if (nilai >= 50) return 'C';
    else if (nilai >= 35) return 'D';
    else if (nilai >= 0) return 'E';
    else return 'I';
}
