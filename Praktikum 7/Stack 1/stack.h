#ifndef STACK_H
#define STACK_H
#include "Boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef int ElType;

typedef struct
{
    ElType buffer[CAPACITY];
    int idxTop;
} Stack;

#define IDX_TOP(s) (s).idxTop
#define TOP(s) (s).buffer[(s).idxTop]

/*** Konstruktor/Kreator ***/
void CreateStack(Stack *s);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Stack s yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0..CAPACITY-1 */

/* Ciri stack kosong: idxTop bernilai IDX_UNDEF */
/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean isEmpty(Stack s);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean isFull(Stack s);
/* Mengirim true jika Stack penuh */

int length(Stack s);
/* Mengirim ukuran Stack s saat ini */

/*********** Menambahkan sebuah elemen ke Stack **********/
void push(Stack *s, ElType val);
/* Menambahkan val sebagai elemen Stack s.
I.S. s mungkin kosong, tidak penuh
F.S. val menjadi TOP yang baru, TOP bertambah 1 */

/*********** Menghapus sebuah elemen Stack **********/
void pop(Stack *s, ElType *val);
/* Menghapus X dari Stack S.
I.S. S tidak mungkin kosong
F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void SortirStack(Stack *S1, Stack *S2);
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
#endif