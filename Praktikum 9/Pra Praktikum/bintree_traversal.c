// NIM     : 18224072
// NAMA    : Francis Galton
// Tanggal : 21 Mei 2025

#include "bintree_traversal.h"

/****************** FUNGSI TRAVERSAL TREE (PRINT) ******************/
/* Menampilkan elemen preorder: akar, kiri, kanan */
void printPreOrder(BinTree p){
   if (p != NIL) { // Jika pohon tidak kosong
      printf("%d ", ROOT(p).key); // Cetak key dari root saat ini
      printPreOrder(LEFT(p));  // Rekursif ke anak kiri
      printPreOrder(RIGHT(p)); // Rekursif ke anak kanan
   }
}
/* I.S. p terdefinisi
   F.S. Elemen ditampilkan sesuai urutan preorder, dipisah spasi, TANPA ENDLINE */

void printInOrder(BinTree p){
   if (p != NIL) {  // Jika pohon tidak kosong
      printInOrder(LEFT(p));  // Rekursif ke anak kiri
      printf("%d ", ROOT(p).key); // Cetak key dari root saat ini
      printInOrder(RIGHT(p)); // Rekursif ke anak kanan
   }
}
/* Menampilkan elemen inorder: kiri, akar, kanan, TANPA ENDLINE */

void printPostOrder(BinTree p){
   if (p != NIL) {  // Jika pohon tidak kosong
      printPostOrder(LEFT(p)); // Rekursif ke anak kiri
      printPostOrder(RIGHT(p));   // Rekursif ke anak kanan
      printf("%d ", ROOT(p).key); // Cetak key dari root saat ini
   }
}
/* Menampilkan elemen postorder: kiri, kanan, akar, TANPA ENDLINE */

/****************** FUNGSI PEMBENTUKAN LIST TRAVERSAL ******************/
/* Membuat node list baru dengan info = val dan next = NIL */
NodeList* newNodeListElement(ElType val){
   NodeList* newNode = (NodeList*) malloc(sizeof(NodeList)); // Alokasi node list
    if (newNode != NULL) {
        Info(newNode) = val; // Set info (key & count) dari node baru
        Next(newNode) = NULL; // Set pointer next ke NULL (akhir list)
    }
    return newNode; // Kembalikan node list baru (atau NULL jika gagal)
}
/* Mengalokasikan simpul baru untuk NodeList dengan nilai val
   Return NIL jika alokasi gagal */

NodeList* concat(NodeList* l1, NodeList* l2){
   if (l1 == NULL) return l2; // Jika list pertama kosong, langsung return list kedua
    NodeList* temp = l1;  // Mulai dari kepala list pertama
    while (Next(temp) != NULL) { // Cari hingga elemen terakhir list pertama
        temp = Next(temp);
    }
    Next(temp) = l2; // Sambungkan akhir list pertama ke awal list kedua
    return l1; // Kembalikan list gabungan
}
/* I.S. l1 dan l2 adalah NodeList yang bisa kosong atau tidak
   F.S. l1 diikuti l2, mengembalikan list hasil konkatenasi */

/* Menghasilkan list preorder traversal dari pohon */
NodeList* makeListPreOrder(BinTree p){
   if (p == NIL) return NULL; // Basis: pohon kosong -> return NULL

   NodeList* rootNode = newNodeListElement(ROOT(p)); // Buat node list dari root
   if (rootNode == NULL) return NULL; // Jika gagal alokasi, return NULL

   NodeList* leftList = makeListPreOrder(LEFT(p)); // Rekursif buat list anak kiri
   NodeList* rightList = makeListPreOrder(RIGHT(p)); // Rekursif buat list anak kanan

   NodeList* result = concat(rootNode, concat(leftList, rightList)); // Gabung: root -> kiri -> kanan
   return result; // Return hasil preorder traversal sebagai NodeList
}
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList preorder traversal dari p (jika semua alokasi berhasil),
        atau NIL jika ada alokasi gagal */

/* Menghasilkan list inorder traversal dari pohon */
NodeList* makeListInOrder(BinTree p){
   if (p == NIL) return NULL; // Basis: pohon kosong

   NodeList* leftList = makeListInOrder(LEFT(p)); // Rekursif ke anak kiri
   NodeList* rootNode = newNodeListElement(ROOT(p)); // Buat node dari root
   if (rootNode == NULL) return NULL;  // Jika gagal alokasi, return NULL
   NodeList* rightList = makeListInOrder(RIGHT(p)); // Rekursif ke anak kanan

   return concat(concat(leftList, rootNode), rightList); // Gabung: kiri -> root -> kanan
}
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList inorder traversal dari p */

/* Menghasilkan list postorder traversal dari pohon */
NodeList* makeListPostOrder(BinTree p){
   if (p == NIL) return NULL; // Basis: pohon kosong

   NodeList* leftList = makeListPostOrder(LEFT(p));   // Rekursif ke anak kiri
   NodeList* rightList = makeListPostOrder(RIGHT(p)); // Rekursif ke anak kanan
   NodeList* rootNode = newNodeListElement(ROOT(p));  // Buat node dari root
   if (rootNode == NULL) return NULL; // Jika gagal alokasi, return NULL

   return concat(concat(leftList, rightList), rootNode); // Gabung: kiri -> kanan -> root
}
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList postorder traversal dari p */

/* Menampilkan isi NodeList ke layar */
void printNodeList(NodeList* l){
   while (l != NULL) { // Selama masih ada node di list
      printf("[%d] -> ", Info(l).key); // Tampilkan key dalam format [x] ->
      l = Next(l); // Lanjut ke node berikutnya
  }
  printf("FINISH\n");  // Tampilkan penutup list
}
/* I.S. l mungkin kosong atau tidak
   F.S. Seluruh elemen list ditampilkan dalam format linked list eksplisit
        Misalnya ada 3 elemen: 10, 20, dan 50 maka output:
        [10] -> [20] -> [50] -> FINISH
        Akhiri output dengan endline */
