#include <stdio.h>
#include <string.h>
#include <math.h>
#include "MegaNimons.h"

void createLabTrack(LabTrack *L) {
    (*L).nEff = 0;
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
    (*L).contents[i] = val;
}

void setLength(LabTrack *L, int N) {
    (*L).nEff = N;
}

boolean isIdxValid(IdxType i) {
    return (i >= 0 && i < CAPACITY);
}

boolean isIdxEff(LabTrack L, IdxType i) {
    return (i >= 0 && i < L.nEff);
}

boolean isEmpty(LabTrack L) {
    return L.nEff == 0;
}

boolean isFull(LabTrack L) {
    return L.nEff == CAPACITY;
}

void insertAt(LabTrack *L, MegaNimons m, IdxType idx) {
    for (int i = (*L).nEff; i > idx; i--) {
        (*L).contents[i] = (*L).contents[i - 1];
    }
    (*L).contents[idx] = m;
    (*L).nEff++;
}

void insertFirst(LabTrack *L, MegaNimons m) {
    insertAt(L, m, 0);
}

void insertLast(LabTrack *L, MegaNimons m) {
    insertAt(L, m, (*L).nEff);
}

void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m) {
    *m = (*L).contents[idx];
    for (int i = idx; i < (*L).nEff - 1; i++) {
        (*L).contents[i] = (*L).contents[i + 1];
    }
    (*L).nEff--;
}

void deleteFirst(LabTrack *L, MegaNimons *m) {
    deleteAt(L, 0, m);
}

void deleteLast(LabTrack *L, MegaNimons *m) {
    deleteAt(L, (*L).nEff - 1, m);
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
        printf("%d: ID=%d NAME=%s POWER=%.1f MUT=%s STABLE=%s\n",
               i,
               L.contents[i].id,
               L.contents[i].name,
               L.contents[i].powerLevel,
               L.contents[i].mutationType,
               L.contents[i].isStable ? "Yes" : "No");
    }
}

boolean isPowerEqual(MegaNimons m1, MegaNimons m2) {
    return fabs(m1.powerLevel - m2.powerLevel) < 1e-6;
}

boolean isMoreStable(MegaNimons m1, MegaNimons m2) {
    return (m1.isStable && !m2.isStable);
}

MegaNimons resolveDuel(MegaNimons m1, MegaNimons m2) {
    MegaNimons win;
    if(isPowerEqual(m1,m2)){
        if(m1.isStable == m2.isStable){
            win = (m1.id < m2.id) ? m1 : m2;
        }
        else{
            win = (isMoreStable(m1,m2)) ? m1 : m2;
        }
    }
    else{
        win = (m1.powerLevel > m2.powerLevel) ? m1 : m2;
    }
    return win;
}

void duelOnce(MegaNimons m1, MegaNimons m2) {
    MegaNimons win = resolveDuel(m1,m2);
    printf("Duel: %s (%1.f) vs %s (%1.f)\nWinner: %s\n", m1.name, m1.powerLevel, m2.name, m2.powerLevel, win.name);
}
