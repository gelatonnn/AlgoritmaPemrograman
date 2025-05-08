// NIM     : 18224072
// NAMA    : Francis Galton
// Tanggal : 7 Mei 2025
// Diupdate pake cara yg sama kek Kak Jendra jelasin tadi (Gapake modulo di Is Full sm Enqueue Dequeue)

#include <stdio.h>
#include <string.h>
#include "circular_queue.h"

/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsEmpty(Queue Q) {
    return (IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
boolean IsFull(Queue Q) {
    return ((IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX) ||
            (IDX_HEAD(Q) >  (IDX_TAIL(Q))) && (IDX_HEAD(Q) == (IDX_TAIL(Q) + 1)));
}

/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int Length(Queue Q) {
    if (IsEmpty(Q)) {
        return 0;
    } else if (IDX_HEAD(Q) <= IDX_TAIL(Q)) {
        return IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
    } else {
        return (IDX_MAX - IDX_HEAD(Q) + 1) + (IDX_TAIL(Q) + 1);
    }
}

/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */
void CreateQueue(Queue *Q) {
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
void enqueue(Queue *Q, ElType X) {
    if (IsEmpty(*Q)) {
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
    } else {
        if (IDX_TAIL(*Q) == IDX_MAX){
            IDX_TAIL(*Q) = 0;
        } else {
            IDX_TAIL(*Q) ++;
        }
    }
    TAIL(*Q) = X;
}

/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType dequeue(Queue *Q) {
    ElType val = HEAD(*Q);
    if (IDX_HEAD(*Q) == IDX_TAIL(*Q)) {
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    } else {
        if (IDX_HEAD(*Q) == IDX_MAX) {
            IDX_HEAD(*Q) = 0;
        } else {
            IDX_HEAD(*Q)++;
        }
    }
    return val;
}

/* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
/* I.S. Q tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */
ElType peek(Queue Q) {
    return HEAD(Q);
}

/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1, e2, ..., en] */
/* Contoh : jika ada tiga elemen bernilai "Tim_1", "Tim_2", dan "Tim_3" akan dicetak: [Tim_1, Tim_2, Tim_3] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */
void displayQueue(Queue q) {
    printf("[");
    if (!IsEmpty(q)) {
        int i = IDX_HEAD(q);
        while (i != IDX_TAIL(q)) {
            printf("%s, ", q.Tab[i].namaTim);
            if (i == IDX_MAX){
                i = 0;
            } else {
                i++;
            }
        }
        printf("%s", q.Tab[i].namaTim);
    }
    printf("]\n");
}
