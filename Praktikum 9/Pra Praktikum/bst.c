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

/* Mencari node dengan key = value dalam BST */
Address searchNode(BinTree p, int value){
    if (p == NIL) return NIL; //Jika kosong, return nil
    if (value < ROOT(p).key) { //Jika lebih kecil, ke kiri
        return searchNode(LEFT(p), value);
    } else if (value > ROOT(p).key) { //Jika lebih besar, ke kanan
        return searchNode(RIGHT(p), value);
    } else { //Jika sama, return node
        return p;
    }
}
/* I.S. p mungkin kosong, value terdefinisi
   F.S. Mengembalikan address node dengan key = value jika ditemukan,
        mengembalikan NIL jika tidak ditemukan */

/* Mencari node dengan nilai minimum dalam BST */
Address findMinimum(BinTree p){
    if (p == NIL) return NIL; //Jika kosong, return nil
    while (LEFT(p) != NIL) { //Selama masih ada anak kiri
        p = LEFT(p); //Terus ke kiri
    }
    return p; //Node paling kiri = minimum
}
/* I.S. p mungkin kosong
   F.S. Mengembalikan address node dengan nilai key minimum dalam BST,
        mengembalikan NIL jika pohon kosong */