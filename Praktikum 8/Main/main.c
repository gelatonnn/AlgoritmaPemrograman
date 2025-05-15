#include "listlinier.h"
#include <stdio.h>

void readNumber(List *L, int n) {
    char digit;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &digit);
        InsVFirst(L, digit - '0');
    }
}

void printNumber(List L) {
    address P = First(L);
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
    }
    printf("\n");
}

/*
 * ALGORITMA:
1. Inisialisasi:
   - Buat linked list kosong untuk menyimpan hasil penjumlahan.
   - Siapkan pointer untuk mengakses elemen pertama dari kedua linked list input
(`L1` dan `L2`).
   - Inisialisasi variabel `carry` untuk menyimpan nilai sisa pembagian (jika
ada) dari penjumlahan digit.

2. Iterasi Penjumlahan:
   - Lakukan iterasi selama salah satu pointer (`P1` atau `P2`) tidak `Nil` atau
nilai `carry` lebih besar dari nol.
   - Pada setiap iterasi:
     - Tambahkan nilai digit dari `L1` (jika ada) ke variabel `sum`.
     - Tambahkan nilai digit dari `L2` (jika ada) ke variabel `sum`.
     - Tambahkan nilai `carry` ke variabel `sum`.
     - Hitung nilai baru untuk `carry` sebagai hasil pembagian `sum` dengan 10.
     - Hitung nilai digit hasil (`sum`) sebagai sisa pembagian `sum` dengan 10.
     - Masukkan nilai digit hasil ke linked list hasil (`result`).
 * */

 List addNumbers(List L1, List L2) {
    List result;
    CreateEmpty(&result);

    address p1 = First(L1);
    address p2 = First(L2);
    int carry = 0;

    while (p1 != Nil || p2 != Nil || carry != 0) {
        int tambah = carry;

        if (p1 != Nil) {
            tambah += Info(p1);
            p1 = Next(p1);
        }

        if (p2 != Nil) {
            tambah += Info(p2);
            p2 = Next(p2);
        }

        carry = tambah / 10;
        int digit = tambah % 10;

        InsVFirst(&result, digit);
    }

    return result;
}

int main() {
    int m, n;
    List num1, num2, result;

    CreateEmpty(&num1);
    CreateEmpty(&num2);
    CreateEmpty(&result);

    scanf("%d %d", &m, &n);

    readNumber(&num1, m);
    readNumber(&num2, n);

    result = addNumbers(num1, num2);

    printNumber(result);

    return 0;
}