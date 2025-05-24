#include "bst.h"

/* ********* KONSTRUKTOR DAN DEALOKASI ********* */
/* Mengalokasikan sebuah simpul baru dengan info x */
Address newTreeNode(ElType x){
    Address p = (Address) malloc(sizeof(TreeNode)); // Alokasi memori untuk node baru
    if (p != NIL){  // Jika alokasi berhasil
        p->info = x;  // Isi info dengan nilai x
        p->left = NIL; // Anak kiri di-set NIL
        p->right = NIL; // Anak kanan di-set NIL
    }
    return p; // Kembalikan alamat node baru (atau NIL jika gagal)

}
/* I.S. Sembarang
   F.S. Menghasilkan address simpul baru dengan info = x serta anak kiri dan
   kanan = NIL Return NIL jika alokasi gagal */

/* Mengembalikan address p ke sistem */
void deallocTreeNode(Address p){
    free(p); // Dealokasi memori node
}
/* I.S. p terdefinisi
   F.S. p didealokasi (free) */

/* ********* PREDIKAT PENTING ********* */
/* Mengirimkan true jika p adalah pohon kosong */
boolean isTreeEmpty(BinTree p){
    return p == NIL; // Mengembalikan true jika pohon kosong
}

/* Mengirimkan true jika p hanya terdiri dari satu simpul
   anak kiri dan kanan bernilai NIL */
boolean isOneElmt(BinTree p){
    return (p != NIL) && (LEFT(p) == NIL) && (RIGHT(p) == NIL); // True jika hanya 1 elemen (daun)
}

/* Mengirimkan true jika p hanya memiliki anak kiri */
boolean isUnerLeft(BinTree p){
    return (p != NIL) && (LEFT(p) != NIL) && (RIGHT(p) == NIL); // True jika hanya punya anak kiri
}

/* Mengirimkan true jika p hanya memiliki anak kanan */
boolean isUnerRight(BinTree p){
    return (p != NIL) && (LEFT(p) == NIL) && (RIGHT(p) != NIL); // True jika hanya punya anak kanan
}

/* Mengirimkan true jika p memiliki dua anak */
boolean isBiner(BinTree p){
    return (p != NIL) && (LEFT(p) != NIL) && (RIGHT(p) != NIL); // True jika punya dua anak
}

/* ********* PEMBENTUK TREE ********* */
/* Membentuk pohon seimbang dari n simpul dengan input x per simpul */
BinTree buildBalancedTree(int n){
    if (n == 0){ // Jika tidak ada node
        return NIL;
    }

    int nL = n / 2; //Jumlah node anak kiri
    int nR = n - nL - 1; //Jumlah node anak kanan
    ElType x;

    scanf("%d", &x.key); //Input nilai key
    x.count = 1; //Set count awal ke 1

    Address node = newTreeNode(x); // Buat node baru
    if (node != NIL){ //Jika berhasil alokasi
        node->left = buildBalancedTree(nL); // Rekursif bangun anak kiri
        node->right = buildBalancedTree(nR); //Rekursif bangun anak kanan
    }
    return node; // Return root
}
/* I.S. n ≥ 0
   F.S. Menghasilkan pohon biner seimbang dengan n simpul,
        setiap simpul diisi dengan input nilai key dan count = 1
   Proses:
      - Jika n = 0, return NIL
      - Setiap simpul diisi dengan input x.key dan count = 1
      - Jumlah simpul anak kiri (nL) = n div 2
      - Jumlah simpul anak kanan(nR) = n - nL - 1
      - Simpul kiri akan direkursif dengan n = nL
      - Simpul kanan akan direkursif dengan n = nR
      - Return nilai root paling atas */


/* ********* OPERASI BST ********* */
/* Menyisipkan x ke dalam BST p */
void insSearchTree(ElType x, BinTree *p){
    if (*p == NIL){ //Jika pohon kosong
        Address node = newTreeNode(x); // Buat node baru
        if (node != NIL){ //Jika berhasil alokasi
            *p = node; //Tempatin di root
        }
    } else {
        if (x.key < ROOT(*p).key){ //Jika x lebih kecil, masuk subtree kiri
            insSearchTree(x, &LEFT(*p));
        } else if (x.key > ROOT(*p).key){ //Jika x lebih besar, masuk subtree kanan
            insSearchTree(x, &RIGHT(*p));
        } else { //Jika x sama, tambahkan count
            ROOT(*p).count++;
        }
    }   
}
/* I.S. p mungkin kosong, x terdefinisi
   F.S. Jika x.key sudah ada di p, maka count bertambah
        Jika belum ada, simpul baru ditambahkan di tempat sesuai properti BST
        - Jika pohon kosong, buat node baru
        - Semua simpul pada subpohon kiri < akar p
        - Semua simpul pada subpohon kanan >= akar p */

/* Prosedur pembantu untuk menghapus node maksimum dari subtree kiri */
void delNode(BinTree *p){
    if (RIGHT(*p) != NIL){ //Selama masih ada anak kanan
        delNode(&RIGHT(*p)); //Lanjut ke kanan
    } else {
        Address temp = *p; //Nyimpen node maksimum
        *p = LEFT(*p); //naikin anak kiri
        deallocTreeNode(temp); //dealokasi node maksimum
    }
}
/* I.S. *p menunjuk ke subtree kiri dari simpul yang ingin digantikan (p tidak
 * kosong) */
/* F.S. Node paling kanan dari subtree kiri (nilai maksimum) dihapus dari pohon,
         dan anak kirinya (jika ada) dinaikkan menggantikannya */
/* Proses:
   - Jika RIGHT(*p) ≠ NIL, lanjut ke kanan (rekursif)
   - Jika RIGHT(*p) = NIL, berarti node saat ini adalah node maksimum
     → *p digantikan dengan anak kirinya (bisa NIL)
     → node tersebut didealokasi */

/* Menghapus simpul dengan key = x.key dari Binary Search Tree */
void delBTree(BinTree *p, ElType x){
    if (x.key < ROOT(*p).key) { //Cari ke subtree kiri
        delBTree(&LEFT(*p), x);
    } else if (x.key > ROOT(*p).key) { // Cari ke subtree kanan
        delBTree(&RIGHT(*p), x);
    } else {
        if (isOneElmt(*p)) { //Kasus 1 : daun
            deallocTreeNode(*p);
            *p = NIL;
        } else if (isUnerLeft(*p)) { // Kasus 2a : hanya anak kiri
            Address temp = *p;
            *p = LEFT(*p);
            deallocTreeNode(temp);
        } else if (isUnerRight(*p)) { //Kasus 2a : hanya anak kanan
            Address temp = *p;
            *p = RIGHT(*p);
            deallocTreeNode(temp);
        } else { //Kasus 3 : dua anak
            Address maxNode = LEFT(*p); // Cari node maksimum di subtree kiri
            while (RIGHT(maxNode) != NIL) {
                maxNode = RIGHT(maxNode);
            }
            ROOT(*p) = ROOT(maxNode); //Copy info node maksimum ke node saat ini
            delNode(&LEFT(*p)); //Hapus node maks
        }
    }
}
/* I.S. *p menunjuk ke root dari subtree yang sedang diperiksa,
        x.key pasti ada dalam BST */
/* F.S. Simpul dengan nilai key = x.key dihapus dari BST,
        struktur dan sifat BST tetap dipertahankan */
/* Proses:
   - Jika x.key < key node saat ini → rekursif ke kiri
   - Jika x.key > key node saat ini → rekursif ke kanan
   - Jika x.key = key node saat ini:
       - Jika node adalah daun (leaf) → langsung hapus
       - Jika hanya memiliki satu anak → naikkan anak ke atas
       - Jika memiliki dua anak:
           - Cari nilai maksimum di subtree kiri (RIGHT-most dari LEFT(*p))
           - Salin info dari node maksimum ke node saat ini
           - Hapus node maksimum tersebut (dengan delNode) */

/* Mengembalikan jumlah daun (leaf node) dalam pohon biner */
int nbLeaf(BinTree p){
    if (isTreeEmpty(p)) {
        return 0;
    }
    return nbLeaf1(p);
}
/* I.S. p terdefinisi (boleh kosong)
   F.S. Menghasilkan banyaknya daun pada pohon
   Proses:
     - Basis: p == NIL → jumlah daun = 0
     - Proses perhitungan menggunakan nbLeaf1*/

/* Mengembalikan jumlah daun (leaf node) dalam pohon biner menggunakan pendekatan basis 1 */
int nbLeaf1(BinTree p){
    if (isOneElmt(p)) {
        return 1;
    } else if (isUnerLeft(p)) {
        return nbLeaf1(LEFT(p));
    } else if (isUnerRight(p)) {
        return nbLeaf1(RIGHT(p));
    } else if (isBiner(p)) {
        return nbLeaf1(LEFT(p)) + nbLeaf1(RIGHT(p));
    }
    return 0;
}
/* I.S. Pohon tidak kosong
   F.S. Menghasilkan banyaknya daun pada pohon
   Proses:
     - Basis: Pohon hanya memiliki satu simpul (daun) → return 1
     - Rekurens:
         - Hanya punya anak kiri       → nbLeaf1(LEFT(p))
         - Hanya punya anak kanan      → nbLeaf1(RIGHT(p))
         - Punya dua anak              → nbLeaf1(LEFT(p)) + nbLeaf1(RIGHT(p)) */

/* Mengembalikan kedalaman (depth) maksimum dari pohon biner */
int depth(BinTree p){
    if (isTreeEmpty(p)) {
        return 0;
    }

    int left = depth(LEFT(p));
    int right = depth(RIGHT(p));

    if (left > right) {
        return 1 + left;
    } else {
        return 1 + right;
    }
}
/* I.S. p terdefinisi
   F.S. Menghasilkan kedalaman maksimum dari pohon biner
   Proses:
     - Basis: p == NIL → kedalaman = 0
     - Rekurens: depth(p) = 1 + maksimum(depth kiri, depth kanan) */

/* Menambahkan simpul baru bernilai x sebagai daun terkiri dari pohon p */
void addLeft(BinTree *p, ElType x){
    if (isTreeEmpty(*p)) {  
        *p = newTreeNode(x); 
        return;
    }
    
    Address curr = *p;
    while (LEFT(curr) != NIL) {
        curr = LEFT(curr);
    }
    LEFT(curr) = newTreeNode(x); 
}
/* I.S. *p boleh kosong
   F.S. Sebuah simpul baru bernilai x ditambahkan sebagai daun terkiri dari pohon
   Proses:
     - Jika pohon kosong → alokasikan simpul baru sebagai akar
     - Jika tidak kosong → rekursif ke anak kiri hingga ditemukan posisi kosong */

/* Menghapus daun terkiri dari pohon p dan menyimpan nilainya di *x */
void delLeft(BinTree *p, ElType *x){
    if (LEFT(*p) == NIL) { 
        *x = ROOT(*p);
        Address temp = *p;
        *p = RIGHT(*p);
        deallocTreeNode(temp);
    } else {
        delLeft(&LEFT(*p), x);
    }
}
/* I.S. *p tidak kosong
   F.S. Daun terkiri dari pohon dihapus dan menyimpan nilainya di *x */