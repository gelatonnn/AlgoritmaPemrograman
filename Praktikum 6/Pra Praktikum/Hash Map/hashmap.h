#ifndef hashHashMap_H
#define hashHashMap_H
#include "Boolean.h"
#include <stdio.h>

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
 */

#define Nil 0
#define MaxEl 16
#define Undefined -9999

typedef int keytype;   // Tipe data untuk key
typedef int valuetype; // Tipe data untuk value
typedef int address;   // Tipe data untuk alamat penyimpanan

typedef struct {
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
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        jika hash dari k penuh, cari index available setelahnya */

void printHashMap(HashMap M);
/* I.S. M mungkin kosong */
/* F.S. Menampilkan semua elemen M dengan format: "Key: k, Value: v" 
   untuk setiap elemen dalam M */

#endif
