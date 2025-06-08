#include "graph_adjlist.h"
#include <stdio.h>

/**
 * @brief Mencetak representasi graf dalam bentuk adjacency list.
 * 
 * Fungsi ini akan mencetak setiap vertex dan daftar vertex yang terhubung dengannya.
 * Format output: "vertex: connected_vertex1 -> connected_vertex2 -> ..."
 * Jika vertex tidak memiliki edge, akan mencetak "vertex: Kosong"
 * Jika graph adalah NULL, akan mencetak "Graph is NULL"
 * 
 * @param graph Pointer ke graf yang akan dicetak.
 */
void printGraph(Graph *graph);

/**
 * @brief Menghapus edge antara dua vertex dalam graf.
 * 
 * Fungsi ini akan menghapus edge antara vertex v1 dan v2 dari adjacency list.
 * Karena graf bersifat undirected, edge akan dihapus dari kedua vertex.
 * Jika vertex tidak valid (di luar range 0 sampai numVertices-1) atau
 * edge tidak ditemukan, akan mencetak "Penghapusan edge gagal.\n"
 * 
 * @param graph Pointer ke graf.
 * @param v1 Vertex pertama.
 * @param v2 Vertex kedua.
 */
void deleteEdge(Graph *graph, int v1, int v2);