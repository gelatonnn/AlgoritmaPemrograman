#include <stdio.h>
#include "graph.h"

/**
 * Inisialisasi graph kosong dengan jumlah simpul tertentu.
 * Semua nilai dalam adjacency matrix akan di-set ke 0 (tidak ada edge).
 *
 * @param g Pointer ke graph yang akan diinisialisasi
 * @param nVertices Jumlah simpul dalam graph
 */
void initGraph(Graph *g, int nVertices) {
    g->nVertices = nVertices; // Menyimpan jumlah simpul pada field struct
    for (int i = 0; i < nVertices; i++) {  // Loop baris pada matriks adjacency
        for (int j = 0; j < nVertices; j++) { // Loop kolom pada matriks adjacency
            g->adjMatrix[i][j] = 0; // Setel semua nilai ke 0 (tidak ada edge)
        }
    }
}

/**
 * Mengecek apakah simpul (vertex) valid, yaitu berada dalam rentang 0 hingga nVertices-1.
 *
 * @param G Graph yang diperiksa
 * @param v Simpul yang ingin divalidasi
 * @return 1 jika valid, 0 jika tidak
 */
int IsValidVertex(Graph G, int v) {
    return (v >= 0 && v < G.nVertices); // Mengembalikan true jika indeks simpul berada dalam rentang valid
}

/**
 * Menambahkan edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 */
void addEdge(Graph *g, int src, int dest) {
    if (IsValidVertex(*g, src) && IsValidVertex(*g, dest)) { // Cek apakah src dan dest adalah simpul yang valid
        g->adjMatrix[src][dest] = 1; // Tambahkan sisi dari src ke dest
        g->adjMatrix[dest][src] = 1; // Tambahkan sisi dari dest ke src (karena graf tak berarah)
    }
}

/**
 * Menghapus edge (sisi) antara dua simpul dalam graf tak berarah.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 */
void removeEdge(Graph *g, int src, int dest) {
    if (IsValidVertex(*g, src) && IsValidVertex(*g, dest)) { // Cek apakah src dan dest valid
        g->adjMatrix[src][dest] = 0; // Hapus sisi dari src ke dest
        g->adjMatrix[dest][src] = 0; // Hapus sisi dari dest ke src (graf tak berarah)
    }
}

/**
 * Mengecek apakah dua simpul saling terhubung (bersebelahan).
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @return 1 jika terdapat edge dari src ke dest, 0 jika tidak
 */
int isAdjacent(Graph *g, int src, int dest) {
    if (IsValidVertex(*g, src) && IsValidVertex(*g, dest)) {  // Cek apakah simpul src dan dest valid
        return g->adjMatrix[src][dest]; // Kembalikan 1 jika ada edge, 0 jika tidak
    }
    return 0;  // Jika simpul tidak valid, kembalikan 0
}