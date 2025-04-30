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
// Key
// Value
} infotype;

typedef struct
{
// List of key-value pairs with maximum size MaxEl
// Jumlah elemen dalam HashMap
} HashMap;

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
// TODO: 1. CreateEmpty

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
// TODO: 2. Value

// TODO: 3. Insert

// TODO: 4. printHashMap

#endif
