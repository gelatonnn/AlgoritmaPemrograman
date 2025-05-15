// NIM     : 18224072
// NAMA    : Francis Galton
// Tanggal : 15 Mei 2025
#include "listfilm.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L) {
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L) {
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P) {
    free(*P);
    *P = Nil;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}

void DelVFirst(List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast(List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
void InsertFirst(List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP(List *L, infotype X) {
    address P = First(*L), Prev = Nil;
    while (P != Nil && Info(P) != X) {
        Prev = P;
        P = Next(P);
    }
    if (P != Nil) {
        if (Prev == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prev) = Next(P);
        }
        Dealokasi(&P);
    }
}

void DelLast(List *L, address *P) {
    address Last = First(*L), Prev = Nil;
    while (Next(Last) != Nil) {
        Prev = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prev == Nil) {
        First(*L) = Nil;
    } else {
        Next(Prev) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
    printf("[");
    address P = First(L);
    while (P != Nil) {
        printf("%d", Info(P));
        if (Next(P) != Nil) {
            printf(",");
        }
        P = Next(P);
    }
    printf("]\n");
}

int NbElmt(List L) {
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

/****************** PENGHAPUSAN FILM ******************/
void RemoveGenre(List *L, infotype X) {
    address P = First(*L);
    address Prev = Nil;
    int count = 0;

    while (P != Nil) {
        if (Info(P) == X) {
            address temp = P;
            if (Prev == Nil) {
                // Elemen pertama
                First(*L) = Next(P);
                P = First(*L);
            } else {
                Next(Prev) = Next(P);
                P = Next(P);
            }
            Dealokasi(&temp);
            count++;
        } else {
            Prev = P;
            P = Next(P);
        }
    }

    if (count > 0) {
        printf("Berhasil menghapus %d film\n", count);
    } else {
        printf("Tidak ada film yang memiliki genre dengan ID: %d\n", X);
    }
}