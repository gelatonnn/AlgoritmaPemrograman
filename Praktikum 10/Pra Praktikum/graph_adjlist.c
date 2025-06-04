#include "graph_adjlist.h"
#include <stdio.h>

/**
 * @brief Membuat simpul baru untuk daftar adjacency.
 *
 * @param v Nomor vertex untuk simpul baru.
 * @return Pointer ke simpul yang baru dibuat atau NULL jika alokasi gagal;
 */
Node *createNode(int v){
    Node* new = malloc(sizeof(Node)); // Alokasi memori untuk simpul baru
    if (new == NULL) return NULL;     // Jika gagal, kembalikan NULL

    new->vertex = v;   // Set nilai vertex
    new->next = NULL;  // Next diset NULL karena belum ada sambungan
    return new;        // Kembalikan pointer ke simpul baru
}

/**
 * @brief Membuat graf dengan jumlah simpul tertentu.
 *
 * @param numVertices Jumlah simpul dalam graf. Vertex yang valid adalah 0
 * sampai numVertices-1.
 * @return Pointer ke graf yang baru dibuat atau NULL jika alokasi graph atau
 * simpul gagal.
 */
Graph *createGraph(int numVertices){
    Graph* new = malloc(sizeof(Graph)); // Alokasi memori untuk struct Graph
    if (new == NULL) return NULL; // Jika gagal, kembalikan NULL

    new->numVertices = numVertices; // Simpan jumlah vertex
    new->adjList = malloc(numVertices * sizeof(Node*)); // Alokasi array pointer ke Node
    for (int i = 0; i < numVertices; i++) {
        new->adjList[i] = NULL; // Inisialisasi setiap daftar menjadi kosong
    }
    return new; // Kembalikan pointer ke graf
}

/**
 * @brief Menambahkan sisi (edge) antara dua simpul dalam graf.
 *
 * Vertex yang valid adalah 0 sampai numVertices-1. Jika vertex di luar range
 * tersebut, penambahan edge akan gagal.
 *
 * Vertex baru selalu ditambahkan di akhir adjacency list. Contoh:
 * - Jika addEdge(graph, 0, 1) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1]
 * - Jika addEdge(graph, 0, 2) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1, 2]
 * - Jika addEdge(graph, 0, 3) dipanggil, adjacency list untuk vertex 0 akan
 * berisi [1, 2, 3]
 *
 * Jika penambahan gagal: keluarkan output: "Penambahan edge
 * gagal.\n"
 *
 * @param graph Pointer ke graf.
 * @param v1 Simpul pertama (harus dalam range 0 sampai numVertices-1).
 * @param v2 Simpul kedua (harus dalam range 0 sampai numVertices-1).
 */
void addEdge(Graph *graph, int v1, int v2){
    if (graph == NULL) { // Cek apakah graf valid
        printf("Penambahan edge gagal.\n");
        return;
    }

    // Cek apakah indeks vertex valid
    if (v1 > graph->numVertices - 1 || v2 > graph->numVertices -1 || v1 < 0 || v2 < 0){
        printf("Penambahan edge gagal.\n");
        return;
    }

    Node* newNode = createNode(v2); // Buat node untuk v2
    if (newNode == NULL) { //Cek Alokasii
        printf("Penambahan edge gagal.\n");
        return;
    }

    // Tambah ke akhir adjacency list v1
    if (graph->adjList[v1] == NULL){
        graph->adjList[v1] = newNode;
    } else {
        Node* temp = graph->adjList[v1];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Buat node untuk v1 (karena graph tak berarah)
    Node* newNode2 = createNode(v1);
    if(newNode2 == NULL) {
        printf("Penambahan edge gagal.\n");
        return;
    }

    // Tambah ke akhir adjacency list v2
    if (graph->adjList[v2] == NULL){
        graph->adjList[v2] = newNode2;
    } else {
        Node* temp = graph->adjList[v2];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode2;
    }
}

/**
 * @brief Membebaskan memori yang dialokasikan untuk graf.
 *
 * @param graph Pointer ke graf yang akan dibebaskan.
 */
void freeGraph(Graph *graph){
    if (graph == NULL) return; // Jika NULL, langsung keluar

    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i]; // Ambil adjacency list untuk simpul i
        while(current != NULL) {
            Node* temp = current; // Simpan pointer ke simpul saat ini
            current = current->next; // Lanjut ke simpul berikutnya
            free(temp); // Bebaskan simpul
        }
    }

    free(graph->adjList); // Bebaskan array pointer
    free(graph); // Bebaskan struct graph
}
