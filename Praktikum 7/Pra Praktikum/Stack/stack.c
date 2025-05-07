#include <stdio.h>
#include "stack.h"

/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack s yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0..CAPACITY-1 */
void CreateStack(Stack *s) {
    IDX_TOP(*s) = IDX_UNDEF;
}

/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */
/********** Predikat Untuk test keadaan KOLEKSI **********/
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean isEmpty(Stack s) {
    return IDX_TOP(s) == IDX_UNDEF;
}

/* Mengirim true jika Stack penuh */
boolean isFull(Stack s) {
    return IDX_TOP(s) == CAPACITY - 1;
}

/* Mengirim ukuran Stack s saat ini */
int length(Stack s) {
    return isEmpty(s) ? 0 : IDX_TOP(s) + 1;
}

/* Menambahkan val sebagai elemen Stack s.
I.S. s mungkin kosong, tidak penuh
F.S. val menjadi TOP yang baru, TOP bertambah 1 */
void push(Stack *s, ElType val) {
    if (isEmpty(*s)) {
        IDX_TOP(*s) = 0;
    } else {
        IDX_TOP(*s)++;
    }
    TOP(*s) = val;
}

/* Menghapus X dari Stack S.
I.S. S tidak mungkin kosong
F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void pop(Stack *s, ElType *val) {
    *val = TOP(*s);
    if (IDX_TOP(*s) == 0) {
        IDX_TOP(*s) = IDX_UNDEF;
    } else {
        IDX_TOP(*s)--;
    }
}
