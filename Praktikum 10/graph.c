#include "graph.h"

/**
 * Inisialisasi graph kosong dengan jumlah simpul tertentu.
 * Semua nilai dalam adjacency matrix akan di-set ke -1 (tidak ada edge).
 *
 * @param g Pointer ke graph yang akan diinisialisasi
 * @param nVertices Jumlah simpul dalam graph
 */
void initGraph(Graph *g, int nVertices){
    g->nVertices = nVertices;
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            g->adjMatrix[i][j] = -1;
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
int IsValidVertex(Graph G, int v){
    return (v >= 0 && v < G.nVertices); // Mengembalikan true jika indeks simpul berada dalam rentang valid
}

/**
 * Menambahkan edge (sisi) antara dua simpul dalam graf berarah dengan bobot weight.
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @param weight Bobot simpul
 */
void addEdge(Graph *g, int src, int dest, int weight){
    if (IsValidVertex(*g, src) && IsValidVertex(*g, dest)) { // Cek apakah src dan dest adalah simpul yang valid
        g->adjMatrix[src][dest] = weight; // Tambahkan sisi dari src ke dest dengan bobot
    }
}

/**
 * Menghapus edge (sisi) antara dua simpul dalam graf berarah.
 * Note: Mengganti nilai bobot menjadi -1
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @param weight Bobot edge yang dihapus
 */
void removeEdge(Graph *g, int src, int dest, int *weight){
    if (IsValidVertex(*g, src) && IsValidVertex(*g, dest)) {
        *weight = g->adjMatrix[src][dest];
        g->adjMatrix[src][dest] = -1;
    } else {
        *weight = -1; 
    }
}

/**
 * Mengecek apakah dua simpul saling terhubung (bersebelahan).
 *
 * @param g Pointer ke graph
 * @param src Indeks simpul asal
 * @param dest Indeks simpul tujuan
 * @return bobot edge jika terdapat edge dari src ke dest, 0 jika tidak
 */
int isAdjacent(Graph *g, int src, int dest){
    if (IsValidVertex(*g, src) && IsValidVertex(*g, dest)) {
        if (g->adjMatrix[src][dest] != -1) {
            return g->adjMatrix[src][dest];
        } else {
            return 0;
        }
    }
    return 0;
}
