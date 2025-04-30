#include <stdio.h>
#include "keranjangpisang.h"

void CreateKeranjang(KeranjangPisang *k){
    for(int i = 0; i < CAPACITY; i++){
        k->contents[i] = MARK;
    }
}

int lengthKeranjang(KeranjangPisang k){
    int count = 0;
    int i = 0;

    while(i < CAPACITY && k.contents[i] != MARK){
        count++;
        i++;
    }
    return count;
}

IdxType getFirstIdx(KeranjangPisang k){
    return 0;
}

IdxType getLastIdx(KeranjangPisang k){
    return lengthKeranjang(k)-1;
}

boolean isIdxValid(KeranjangPisang k, IdxType i){
    return (i >= 0 && i<CAPACITY);
}

boolean isIdxEff(KeranjangPisang k, IdxType i){
    return (i>=0 && i<lengthKeranjang(k));
}

boolean isEmpty(KeranjangPisang k){
    return lengthKeranjang(k) == 0;
}

boolean isFull(KeranjangPisang k){
    return lengthKeranjang(k) == CAPACITY;
}

void readKeranjang(KeranjangPisang *k){
    int n;
    scanf("%d", &n);
    CreateKeranjang(k);
    for(int i = 0; i<n; i++){
        scanf("%d", &k->contents[i]);
        getchar();
    }
}

void printKeranjang(KeranjangPisang k){
    int neff = lengthKeranjang(k);
    printf("[");
    for(int i = 0; i<neff; i++){
        printf("%d", k.contents[i]);
        if(i<neff-1){
            printf(",");
        }
    }
    printf("]\n");
}

void insertAt(KeranjangPisang *k, ElType val, IdxType idx){
    int neff = lengthKeranjang(*k);
    for (int i = neff; i>idx; i--){
        k->contents[i] = k->contents[i-1];
    }
    k->contents[idx] = val;
}

void insertFirst(KeranjangPisang *k, ElType val){
    insertAt(k,val,0);
}

void insertLast(KeranjangPisang *k, ElType val){
    insertAt(k, val, lengthKeranjang(*k));
}

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx){
    int neff = lengthKeranjang(*k);
    *val = k->contents[idx];
    for(int i = idx; i<neff; i++){
        k->contents[i] = k->contents[i+1];
    }
}

void deleteFirst(KeranjangPisang *k, ElType *val){
    *val = k->contents[0];
    deleteAt(k, val, 0);
}

void deleteLast(KeranjangPisang *k, ElType *val){
    *val = k->contents[lengthKeranjang(*k)-1];
    k->contents[lengthKeranjang(*k)-1] = MARK;
}
