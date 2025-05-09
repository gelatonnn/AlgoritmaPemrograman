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

void SortirStack(Stack *S1, Stack *S2){
    ElType temp;
    while(!isEmpty(*S1)){
        pop(S1, &temp); //ambil 1 elemen dari S1
        
        while (!isEmpty(*S2) && TOP(*S2) > temp){
        //Mindahin elemen dari S2 ke S1 selama elemen di TOP S2 lebih besar dari elemen yang diambil dari temp
            ElType pindah;
            pop(S2, &pindah);
            push(S1, pindah);
        }
        
        push(S2, temp);
    }
}
/* Menyortir S1 menggunakan bantuan S2 */
/* I.S. S1 tidak terurut dan S2 kosong */
/* F.S. S1 kosong dan S2 terurut (elemen terbesar berada di paling atas) */
/* Contoh: */
/* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
/* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */
/* CATATAN:
   Penyortiran HARUS dilakukan secara bertahap saat pemindahan elemen dari S1 ke S2.
   Tidak diperbolehkan memindahkan seluruh isi S1 ke S2 terlebih dahulu, lalu menyortir
   menggunakan algoritma seperti bubble sort, insertion sort, dan sejenisnya.
   Gunakan hanya operasi dasar stack (push, pop, isEmpty, TOP) dalam proses sortir ini.
*/