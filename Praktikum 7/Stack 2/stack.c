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

/*********** Operasi Tambahan **********/
void copyStack(Stack *sres, Stack s){
    CreateStack(sres);
    Stack temp;
    CreateStack(&temp);

    // Nyalin isi dari S ke Temp (Isinya terbalik)
    while(!isEmpty(s)){
        ElType val;
        pop(&s, &val);
        push(&temp, val);
    }

    // Nyalin isi dari Temp ke Sres dan balikin S ke semula
    while(!isEmpty(temp)){
        ElType val;
        pop(&temp, &val);
        push(sres, val);
        push(&s, val);
    }
}
/* Menyalin isi Stack s ke dalam Stack sres
I.S. sres mungkin kosong
F.S. sres berisi salinan dari s
Contoh:
Jika s = [1,2,3] maka setelah dipanggil sres = [1,2,3]
Jika s = [] maka setelah dipanggil sres = []
Jika s = [1] maka setelah dipanggil sres = [1]

Hint: 
- gunakan Stack sementara dan command push & pop
- Jangan lupa konstruk ulang sres

Notes: [ 1, 2, 3 ]
               ⬆️
              Top
*/

void reverseStack(Stack *s){
    Stack temp;
    CreateStack(&temp);

    while(!isEmpty(*s)){
        ElType val;
        pop(s, &val);
        push(&temp, val);
    }

    copyStack(s, temp);
}
/* Membalikkan isi Stack s
I.S. S mungkin kosong
F.S. Isi Stack s dibalik
Contoh:
jika s = [1,2,3] maka setelah dipanggil s = [3,2,1]
Jika s = [1,2,3,4] maka setelah dipanggil s = [4,3,2,1]
Jika s = [] maka setelah dipanggil s = []
Jika s = [1] maka setelah dipanggil s = [1]

Hint: 
- gunakan Stack sementara, lalu copy isi Stack sementara ke dalam Stack s

Notes: [ 1, 2, 3 ]
               ⬆️
              Top
*/

void mergeStack(Stack *sres, Stack *s1, Stack *s2){
    Stack temp1, temp2;

    //ngecopy s1 & s2 ke stack sementara
    copyStack(&temp1, *s1);
    copyStack(&temp2, *s2);

    CreateStack(sres); //ngosongin sres

    //masukin temp 1 ke sres
    Stack rev1;
    CreateStack(&rev1);
    while (!isEmpty(temp1)){
        ElType val;
        pop(&temp1, &val);
        push(&rev1, val);
    }

    while (!isEmpty(rev1)){
        ElType val;
        pop(&rev1, &val);
        push(sres, val);
    }
    
    //masukin temp 2 ke sres
    Stack rev2;
    CreateStack(&rev2);
    while (!isEmpty(temp2)){
        ElType val;
        pop(&temp2, &val);
        push(&rev2, val);
    }

    while (!isEmpty(rev2)){
        ElType val;
        pop(&rev2, &val);
        push(sres, val);
    } 
}
/* Menggabungkan Stack s1 dan s2 ke dalam Stack sres
I.S. sres, s1, dan s2 mungkin kosong
F.S. sres berisi gabungan dari s1 dan s2 (dengan s1 di bawah s2)
Contoh:
Jika s1 = [1,2,3] dan s2 = [4,5,6] maka setelah dipanggil sres = [1,2,3,4,5,6]
Jika s1 = [] dan s2 = [] maka setelah dipanggil sres = []
Jika s1 = [1,2,3] dan s2 = [] maka setelah dipanggil sres = [1,2,3]
Jika s1 = [] dan s2 = [4,5,6] maka setelah dipanggil sres = [4,5,6]

Hint:
- gunakan konsep yang sama seperti copyStack

Notes: [ 1 , 2, 3 ]
         ⬆️     ⬆️
       bottom  Top
*/

void printStack(Stack s){
    if (isEmpty(s)) {
        printf("Stack: EMPTY\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= s.idxTop; i++) {
            printf("%d", s.buffer[i]);
            if (i < s.idxTop) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
