// NIM     : 18224072 ; 18224026
// NAMA    : Francis Galton; M.B. Adyanti Narandita
// Tanggal : <Tulis tanggal praktikum>

/* MODUL PRIORITY QUEUE BERBASIS LINEAR BUFFER */
/* Digunakan untuk mengatur antrean penonton Festival Musik Gro */
/* Penonton akan diatur berdasarkan prioritas queueNumber (QN), dan dicegah agar tidak duplikat berdasarkan seatNumber (SN) */

#include "tiket_konser.h"
#include <stdio.h>
#include <string.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */

boolean IsFull (Queue Q){
    return (Q.idxTail == IDX_MAX);
}

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX */
int Length (Queue Q){
    if (IsEmpty(Q)){
        return 0;
    } else {
        return Q.idxTail - Q.idxHead + 1;
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue *Q){
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue *Q, ElType P){
    if (isDuplicateSN(*Q, P.seatNumber) || IsFull(*Q)) {
        return;
    }

    if (IsEmpty(*Q)) {
        Q->idxHead = 0;
        Q->idxTail = 0;
        Q->Tab[0] = P;
        return;
    }
    
    int pos = Q->idxTail;
    while (pos >= Q->idxHead && Q->Tab[pos].queueNumber > P.queueNumber) {
        Q->Tab[pos+1] = Q->Tab[pos];
        pos--;
    }

    Q->Tab[pos+1] = P;
    Q->idxTail++;
}
/* Proses: Menambahkan P ke dalam antrean jika dan hanya jika: */
/* - SN dari P belum pernah ada di antrean (tidak duplikat) */
/* - QN dari P menentukan posisi berdasarkan prioritas */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Apabila P memenuhi semua syarat, P masuk ke posisi yang sesuai berdasarkan queueNumber
        Semakin kecil, semakin berada di depan antrean
        IDX_TAIL akan "mundur" ke belakang */

ElType dequeue (Queue *Q){
    ElType val = Q->Tab[Q->idxHead];

    if (Q->idxHead == Q->idxTail) {
        CreateQueue(Q);
    } else {
        for (int i = Q->idxHead + 1; i <= Q->idxTail; i++) {
            Q->Tab[i-1] = Q->Tab[i];
        }
        Q->idxTail--;
    }
    
    return val;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        jika Q belum kosong idxHead "tetap" di indeks 0 dan elemen akan digeser satu per satu
        Q mungkin kosong dan idxHead akan menjadi IDX_UNDEF */

/* *** Operasi Tambahan *** */
ElType peek (Queue Q){
    return Q.Tab[Q.idxHead];
}
/* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
/* I.S. Q tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */

boolean isDuplicateSN(Queue Q, int sn){
    if (IsEmpty(Q)){
        return false;
    }
    for (int i = Q.idxHead; i <= Q.idxTail; i++) {
        if (Q.Tab[i].seatNumber == sn) {
            return true;
        }
    }
    return false;
}
/* Mengirim true jika terdapat Penonton dalam antrean dengan SN yang sama */

/* *** Display Queue *** */
void displayQueue(Queue q){
    if (IsEmpty(q)) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    for (int i = q.idxHead; i <= q.idxTail; i++) {
        printf("(%s-%d-%d)", q.Tab[i].nama, q.Tab[i].seatNumber, q.Tab[i].queueNumber);
        if (i < q.idxTail) {
            printf(", ");
        }
    }
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [p1, p2, ..., pn] */
/* Contoh : jika ada tiga elemen bernilai "Kebin" dgn SN: 3 QN: 1, "Pop" dgn SN: 1 QN: 2, dan "Toto" dgn SN: 2 QN: 3 akan dicetak: [(Kebin-3-1), (Pop-1-2), (Toto-2-3)] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */
