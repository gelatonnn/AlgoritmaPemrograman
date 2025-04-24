// NIM    : 18224072
// Nama   : Francis Galton
// Tanggal: 23 April 2025
//Soal ini udah dibenerin yaa guys, jd udah 100 hehe
//Kalo yg di pdf soal itu kmrn masih salah jd nilainy cuma 20

#include "MegaNimons.h"

void createLabTrack(LabTrack *L) {
    L->nEff = 0;
}

int length(LabTrack L) {
    return L.nEff;
}

int maxCapacity() {
    return CAPACITY;
}

IdxType firstIdx(LabTrack L) {
    return 0;
}

IdxType lastIdx(LabTrack L) {
    return L.nEff - 1;
}

MegaNimons getElmt(LabTrack L, IdxType i) {
    return L.contents[i];
}

void setElmt(LabTrack *L, IdxType i, MegaNimons val) {
    L->contents[i] = val;
}

void setLength(LabTrack *L, int N) {
    L->nEff = N;
}

boolean isIdxValid(IdxType i) {
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(LabTrack L, IdxType i) {
    return (i >= 0 && i < L.nEff);
}

boolean isEmpty(LabTrack L) {
    return (L.nEff == 0);
}

boolean isFull(LabTrack L) {
    return (L.nEff == CAPACITY);
}

void insertAt(LabTrack *L, MegaNimons m, IdxType idx) {
    for (int i = L->nEff; i > idx; i--) {
        L->contents[i] = L->contents[i - 1];
    }
    L->contents[idx] = m;
    L->nEff++;
}

void insertFirst(LabTrack *L, MegaNimons m) {
    insertAt(L, m, 0);
}

void insertLast(LabTrack *L, MegaNimons m) {
    insertAt(L, m, L->nEff);
}

void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m) {
    *m = L->contents[idx];
    for (int i = idx; i < lastIdx(*L); i++) {
        L->contents[i] = L->contents[i + 1];
    }
    L->nEff--;
}

void deleteFirst(LabTrack *L, MegaNimons *m) {
    deleteAt(L, 0, m);
}

void deleteLast(LabTrack *L, MegaNimons *m) {
    deleteAt(L, lastIdx(*L), m);
}

IdxType indexOf(LabTrack L, int id) {
    for (int i = 0; i < L.nEff; i++) {
        if (L.contents[i].id == id) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void printLabTrack(LabTrack L) {
    for (int i = 0; i < L.nEff; i++) {
        printf("%d: ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", i,
               L.contents[i].id,
               L.contents[i].name,
               L.contents[i].powerLevel,
               L.contents[i].mutationType,
               L.contents[i].isStable ? "Yes" : "No");
    }
}

void ejectUnstable(LabTrack *L) {
    int i = 0;
    while (i < L->nEff) {
        if (L->contents[i].isStable == FALSE) {
            MegaNimons temp;
            deleteAt(L, i, &temp);
            printf("EJECTED: %s\n", temp.name);
        } else {
            i++;
        }
    }
}

void filterByPower(LabTrack L, float minPower) {
    for (int i = 0; i < L.nEff; i++) {
        if (L.contents[i].powerLevel >= minPower) {
            printf("%d: ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n", i,
                   L.contents[i].id,
                   L.contents[i].name,
                   L.contents[i].powerLevel,
                   L.contents[i].mutationType,
                   L.contents[i].isStable ? "Yes" : "No");
        }
    }
}
