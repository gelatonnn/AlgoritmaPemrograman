#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P = (address) malloc (sizeof (ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X){
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P){
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (List *L, infotype X){
    address P = First(*L), Prec = Nil;
    while (P != Nil && Info(P) != X) {
        Prec = P;
        P = Next(P);
    }
    if (P != Nil) {
        if (Prec == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Dealokasi(&P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, address *P){
    address Prec = Nil, Last = First(*L);
    while (Next(Last) != Nil) {
        Prec = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(Prec) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    printf("[");
    address P = First(L);
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */

int NbElmt (List L){
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    infotype max = Info(First(L));
    address P = Next(First(L));
    while (P != Nil) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */

address AdrMax (List L){
    address maxP = First(L);
    address P = Next(First(L));
    while (P != Nil) {
        if (Info(P) > Info(maxP)) {
            maxP = P;
        }
        P = Next(P);
    }
    return maxP;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

infotype Min (List L){
    infotype min = Info(First(L));
    address P = Next(First(L));
    while (P != Nil) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */

address AdrMin (List L){
    address minP = First(L);
    address P = Next(First(L));
    while (P != Nil) {
        if (Info(P) < Info(minP)) {
            minP = P;
        }
        P = Next(P);
    }
    return minP;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */

float Average (List L){
    int total = 0;
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        total += Info(P);
        count++;
        P = Next(P);
    }
    return (float)total / count;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address prev = Nil;
    address curr = First(*L);
    address next;
    while (curr != Nil) {
        next = Next(curr);
        Next(curr) = prev;
        prev = curr;
        curr = next;
    }
    First(*L) = prev;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    if (IsEmpty(*L1)) {
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        address last = First(*L1);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void SortListAsc(List *L){
    if (IsEmpty(*L) || Next(First(*L)) == Nil) return;

    address last = Nil; 
    while (last != First(*L)) {
        address P = First(*L);
        while (Next(P) != last && Next(P) != Nil) {
            address Q = Next(P);
            if (Info(P) > Info(Q)) {
                //swap p & q
                infotype temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;
            }
            P = Next(P);
        }
        last = P;
    }
}
/* I.S. Sembarang (list mungkin kosong atau tidak terurut) */
/* F.S. Elemen-elemen list terurut secara menaik berdasarkan info(P) */
/* Hint: Silakan gunakan salah satu algoritma sorting yang ada pada 
			   slide dan lakukan penyesuaian dengan linkedlist (misal: Bubble Sort Efficient Algorithm) */
