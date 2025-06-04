#include "graphMultiList.h"

/* ********* KONSTRUKTOR ********* */
/**
 * @brief Membuat graph dengan satu simpul awal
 * @param x ID simpul pertama
 * @param g Graph yang akan dibentuk
 * I.S. : Sembarang
 * F.S. : Terbentuk graph dengan satu simpul ber-ID x
 * Proses: Alokasi simpul baru dan diset sebagai simpul pertama
 */
void CreateGraph(int x, Graph *g) {
    AdrNode p = newGraphNode(x); // Membuat simpul baru dengan ID x
    if (p != NIL) { // Jika alokasi berhasil
        FIRST(*g) = p; // Set simpul pertama di graph ke p
    } else {
        FIRST(*g) = NIL; // Jika gagal, graph tetap kosong
    }
}

/* ********* MANAJEMEN MEMORI NODE (LEADER) ********* */
/**
 * @brief Mengalokasikan simpul utama (Node) baru
 * @param x ID simpul yang ingin dibuat
 * @return Alamat simpul jika berhasil, NIL jika gagal
 * I.S. : x terdefinisi
 * F.S. : Dialokasikan simpul baru dengan nilai id = x
 * Proses: Alokasi memori dan inisialisasi atribut node
 */
AdrNode newGraphNode(int x) {
    AdrNode p = (AdrNode)malloc(sizeof(Node));  // Alokasi memori untuk simpul baru
    if (p != NIL) { // Jika alokasi berhasil
        ID(p) = x; // Set ID simpul
        NPRED(p) = 0; // Inisialisasi jumlah predecessor ke 0
        TRAIL(p) = NIL;  // Belum ada edge keluar
        NEXTNODE(p) = NIL;  // Belum terhubung ke node lain
    }
    return p; // Return simpul baru (atau NIL jika gagal)
}
/**
 * @brief Dealokasi simpul utama (Node)
 * @param p Pointer ke simpul yang akan didealokasi
 * I.S. : p menunjuk ke simpul yang valid
 * F.S. : Memori simpul dikembalikan ke sistem
 */
void deallocGraphNode(AdrNode p) {
    free(p); // Bebaskan memori simpul utama
}

/* ********* MANAJEMEN MEMORI TRAIL (SUCCESSOR) ********* */
/**
 * @brief Mengalokasikan simpul successor baru
 * @param pn Pointer ke simpul tujuan
 * @return Alamat SuccNode jika berhasil, NIL jika gagal
 * I.S. : pn valid
 * F.S. : Dialokasikan SuccNode dengan succ menunjuk ke pn
 */
AdrSuccNode newSuccNode(AdrNode pn) {
    AdrSuccNode p = (AdrSuccNode)malloc(sizeof(SuccNode));  // Alokasi memori SuccNode
    if (p != NIL) { // Jika berhasil
        SUCC(p) = pn; // Set pointer ke simpul tujuan
        NEXTSUCC(p) = NIL; // Belum punya successor selanjutnya
    }
    return p;  // Kembalikan alamat SuccNode
}
/**
 * @brief Dealokasi simpul successor (SuccNode)
 * @param p Pointer ke successor yang akan didealokasi
 * I.S. : p valid
 * F.S. : Memori SuccNode dikembalikan ke sistem
 */
void deallocSuccNode(AdrSuccNode p) {
    free(p); // Dealokasi SuccNode
}

/* ********* OPERASI DASAR GRAF ********* */
/**
 * @brief Mencari simpul dalam graph
 * @param g Graph yang dicari
 * @param x ID simpul yang dicari
 * @return Alamat simpul jika ditemukan, NIL jika tidak ada
 * I.S. : g dan x terdefinisi
 * F.S. : Tidak mengubah g
 * Proses: Telusuri list simpul sampai ditemukan id = x
 */
AdrNode searchNode(Graph g, int x) {
    AdrNode p = FIRST(g); // Mulai dari simpul pertama
    while (p != NIL) { // Selama belum mencapai akhir
        if (ID(p) == x) return p;    // Jika ditemukan ID cocok, return node
        p = NEXTNODE(p); // Lanjut ke simpul berikutnya
    }
    return NIL; // Tidak ditemukan, return NIL
}

/**
 * @brief Mencari edge dari prec ke succ
 * @param g Graph yang diperiksa
 * @param prec ID simpul asal
 * @param succ ID simpul tujuan
 * @return Alamat SuccNode jika edge ada, NIL jika tidak ada
 * I.S. : g, prec, succ terdefinisi
 * F.S. : Tidak mengubah g
 */
AdrSuccNode searchEdge(Graph g, int prec, int succ) {
    AdrNode p = searchNode(g, prec); // Cari simpul asal
    AdrNode q = searchNode(g, succ); // Cari simpul tujuan
    if (p == NIL || q == NIL) return NIL; // Jika salah satu tidak ada, return NIL

    AdrSuccNode e = TRAIL(p); // Ambil trail dari simpul asal
    while (e != NIL) { // Telusuri successor
        if (SUCC(e) == q) return e; // Jika menemukan edge ke succ, return edge
        e = NEXTSUCC(e); // Lanjut ke edge berikutnya
    }
    return NIL; // Tidak ditemukan edge
}

/**
 * @brief Menambahkan simpul baru ke graph
 * @param g Graph yang akan diubah
 * @param x ID simpul yang akan ditambahkan
 * @param pn Alamat simpul hasil alokasi (output)
 * I.S. : g dan x terdefinisi, x belum ada dalam g
 * F.S. : Jika alokasi berhasil, x menjadi simpul terakhir
 *        dan pn menunjuk ke simpul tersebut
 *        Jika gagal, g tetap, pn = NIL
 */
void insertNode(Graph *g, int x, AdrNode *pn) {
    *pn = searchNode(*g, x); // Cek apakah node x sudah ada
    if (*pn != NIL) return; // Jika sudah ada, keluar

    AdrNode newNode = newGraphNode(x); // Alokasikan node baru
    if (newNode != NIL) { // Jika berhasil
        if (FIRST(*g) == NIL) { // Jika graph kosong
            FIRST(*g) = newNode; // Set sebagai simpul pertama
        } else {
            AdrNode last = FIRST(*g); // Cari simpul terakhir
            while (NEXTNODE(last) != NIL) {
                last = NEXTNODE(last);
            }
            NEXTNODE(last) = newNode; // Tambahkan di akhir
        }
        *pn = newNode; // Kembalikan simpul baru melalui parameter
    } else {
        *pn = NIL; // Jika gagal alokasi
    }
}

/**
 * @brief Menambahkan edge dari prec ke succ ke dalam graph
 * @param g Graph yang akan diubah
 * @param prec ID simpul asal
 * @param succ ID simpul tujuan
 * I.S. : g, prec, succ terdefinisi
 * F.S. : 
 *   - Jika edge belum ada: tambahkan edge <prec, succ>
 *   - Jika node belum ada: node ditambahkan dulu
 *   - Jika edge sudah ada: tidak melakukan apa-apa
 */
void insertEdge(Graph *g, int prec, int succ) {
    if (prec == succ) return;                // Tidak boleh ada edge ke diri sendiri

    AdrNode p, q;
    p = searchNode(*g, prec); // Cari simpul asal
    q = searchNode(*g, succ); // Cari simpul tujuan

    if (p == NIL) insertNode(g, prec, &p);  // Jika tidak ada, tambahkan
    if (q == NIL) insertNode(g, succ, &q);

    if (searchEdge(*g, prec, succ) != NIL) return;  // Cek apakah edge sudah ada

    AdrSuccNode edge = newSuccNode(q); // Buat SuccNode baru
    if (edge != NIL) {
        if (TRAIL(p) == NIL) { // Jika belum punya trail
            TRAIL(p) = edge; // Langsung set trail
        } else {
            AdrSuccNode last = TRAIL(p); // Cari akhir trail
            while (NEXTSUCC(last) != NIL) {
                last = NEXTSUCC(last);
            }
            NEXTSUCC(last) = edge; // Tambahkan di akhir trail
        }
        NPRED(q)++; // Tambah in-degree simpul tujuan
    }
}

/**
 * @brief Menghapus simpul dari graph beserta seluruh edge terkait
 * @param g Graph yang akan diubah
 * @param x ID simpul yang ingin dihapus
 * I.S. : g terdefinisi, x boleh ada atau tidak di g
 * F.S. : Simpul x dan semua edge ke/dari x dihapus dari g.
 *        Jika simpul yang dihapus adalah satu-satunya simpul di graph,
 *        maka graph menjadi kosong (FIRST(*g) == NIL).
 * Proses:
 * - Menghapus semua edge yang menunjuk ke x.
 * - Menghapus semua edge keluar dari x.
 * - Menghapus simpul x dari list simpul.
 */
void deleteNode(Graph *g, int x) {
    AdrNode pDel = searchNode(*g, x); // Cari node yang akan dihapus
    if (pDel == NIL) return; // Jika tidak ada, keluar

    AdrNode p = FIRST(*g); // Traversal semua simpul
    while (p != NIL) {
        if (p != pDel) { // Jangan cek dirinya sendiri
            AdrSuccNode prev = NIL;
            AdrSuccNode curr = TRAIL(p);
            while (curr != NIL) {  // Cek apakah ada edge ke pDel
                if (SUCC(curr) == pDel) {
                    if (prev == NIL) {
                        TRAIL(p) = NEXTSUCC(curr);  // Hapus dari head
                    } else {
                        NEXTSUCC(prev) = NEXTSUCC(curr);  // Hapus di tengah
                    }
                    AdrSuccNode toDel = curr;
                    curr = NEXTSUCC(curr); // Pindah ke berikutnya
                    deallocSuccNode(toDel); // Dealokasi edge
                    NPRED(pDel)--; // Kurangi in-degree
                } else {
                    prev = curr;
                    curr = NEXTSUCC(curr);
                }
            }
        }
        p = NEXTNODE(p); // Lanjut ke simpul berikutnya
    }

    AdrSuccNode currSucc = TRAIL(pDel); // Hapus semua edge keluar dari pDel
    while (currSucc != NIL) {
        AdrSuccNode nextSucc = NEXTSUCC(currSucc);
        NPRED(SUCC(currSucc))--; // Kurangi in-degree successor
        deallocSuccNode(currSucc); // Dealokasi SuccNode
        currSucc = nextSucc;
    }

    if (FIRST(*g) == pDel) { // Hapus dari head
        FIRST(*g) = NEXTNODE(pDel);
    } else { // Hapus dari tengah/akhir
        AdrNode prev = FIRST(*g);
        while (NEXTNODE(prev) != pDel) {
            prev = NEXTNODE(prev);
        }
        NEXTNODE(prev) = NEXTNODE(pDel);
    }

    deallocGraphNode(pDel); // Bebaskan memori simpul utama
}

/**
 * @brief Menampilkan isi graph berupa daftar successor dari setiap simpul.
 *
 * I.S. : Graph g sudah terdefinisi (boleh kosong).
 * F.S. : Jika graph kosong, cetak "Graph kosong".
 *        Semua simpul dicetak ke layar bersama daftar successor-nya dalam format:
 *        <id_simpul> -> <id_succ_1> -> <id_succ_2> ... 
 *        Jika simpul tidak memiliki successor, hanya ditampilkan id-nya saja
 *        Selalu akhiri setiap output dengan endline (\n).
 *
 * Proses:
 * - Jika graph kosong, cetak "Graph kosong" dan keluar.
 * - Melakukan traversal dari simpul pertama (g.first) ke simpul berikutnya
 * - Untuk setiap simpul, mencetak id-nya, lalu menelusuri dan mencetak semua trail (succNode) yang keluar darinya
 * 
 *
 * Contoh Graph:
 * Misalkan ada graph dengan edge:
 *   1 → 2
 *   1 → 3
 *   4 → 5
 *   2 → 5
 *   3 → 5
 *
 * Maka output dari printGraph(g) adalah:
 * 1 -> 2 -> 3
 * 2 -> 5
 * 3 -> 5
 * 4 -> 5
 * 5
 * 
 */
void printGraph(Graph g) {
    if (FIRST(g) == NIL) {
        printf("Graph kosong\n"); // Jika graph kosong
        return;
    }
    AdrNode p = FIRST(g); // Mulai dari simpul pertama
    while (p != NIL) {
        printf("%d", ID(p)); // Cetak ID simpul
        AdrSuccNode e = TRAIL(p); // Ambil trail dari simpul
        while (e != NIL) {
            printf(" -> %d", ID(SUCC(e))); // Cetak edge
            e = NEXTSUCC(e);  // Lanjut ke edge berikutnya
        }
        printf("\n"); // Akhiri baris
        p = NEXTNODE(p); // Lanjut ke simpul berikutnya
    }
}
