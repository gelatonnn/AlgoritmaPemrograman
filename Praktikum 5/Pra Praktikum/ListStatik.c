#include "ListStatik.h"
#include <stdlib.h>
#include <stdio.h>

void inisialisasiList(ListStatik *list, int capacity) {
    list->data = (int *)malloc(capacity * sizeof(int));
    list->ukuran = 0;
    list->kapasitas = capacity;
}

bool tambahElemen(ListStatik *list, int nilai) {
    if (list->ukuran >= list->kapasitas) {
        return false; 
    }
    list->data[list->ukuran] = nilai;
    list->ukuran++;
    return true;
}

bool hapusElemenAkhir(ListStatik *list) {
    if (list->ukuran == 0) {
        return false; 
    }
    list->ukuran--;
    return true;
}

void tampilkanList(ListStatik list) {
    if (list.ukuran == 0) {
        printf("List kosong\n");
        return;
    }
    
    for (int i = 0; i < list.ukuran; i++) {
        printf("%d", list.data[i]);
    }
    printf("\n");
}

int cariElemen(ListStatik list, int nilai) {
    for (int i = 0; i < list.ukuran; i++) {
        if (list.data[i] == nilai) {
            return i;
        }
    }
    return -1; 
}

bool ubahElemen(ListStatik *list, int indeks, int nilaiBaru) {
    if (indeks < 0 || indeks >= list->ukuran) {
        return false; 
    }
    list->data[indeks] = nilaiBaru;
    return true;
}
