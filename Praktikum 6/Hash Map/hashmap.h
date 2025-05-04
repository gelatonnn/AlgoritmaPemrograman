#ifndef hashHashMap_H
#define hashHashMap_H
#include "Boolean.h"
#include <stdio.h>

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
 */

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 16
#define Undefined -9999

// typedef int bool;
typedef int keytype;   // Tipe data untuk key
typedef int valuetype; // Tipe data untuk value
typedef int address;   // Tipe data untuk alamat penyimpanan

typedef struct
{
    keytype Key;
    valuetype Value;
} infotype;

typedef struct {
    infotype Elements[MaxEl];
    int Count;
} HashMap;

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M);

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k);

void Insert(HashMap *M, keytype k, valuetype v);

void printHashMap(HashMap M);

void Delete(HashMap *M, keytype k);
/* Menghapus elemen dengan key k dari HashMap M */
/* I.S. M tidak kosong */
/* F.S. Elemen dengan key k dihapus dari M */
/* Jika k tidak ada, tidak ada perubahan pada M */

#endif