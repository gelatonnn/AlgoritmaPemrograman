#include "graph_modules.h"

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
void printGraph(Graph *graph){
    if (graph == NULL) {
        printf("Graph is NULL\n");
        return;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node *temp = graph->adjList[i];

        if (temp == NULL) {
            printf("Kosong");
        } else {
            while (temp != NULL) {
                printf("%d", temp->vertex);
                if (temp->next != NULL) printf(" -> ");
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

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
void deleteEdge(Graph *graph, int v1, int v2){
    if (graph == NULL || v1 < 0 || v1 >= graph->numVertices || v2 < 0 || v2 >= graph->numVertices) {
        printf("Penghapusan edge gagal.\n");
        return;
    }
    int found = 0;
    Node **curr = &graph->adjList[v1];
    while (*curr != NULL) {
        if ((*curr)->vertex == v2) {
            Node *temp = *curr;
            *curr = (*curr)->next;
            free(temp);
            found = 1;
            break;
        }
        curr = &(*curr)->next;
    }

    curr = &graph->adjList[v2];
    while (*curr != NULL) {
        if ((*curr)->vertex == v1) {
            Node *temp = *curr;
            *curr = (*curr)->next;
            free(temp);
            found = 1;
            break;
        }
        curr = &(*curr)->next;
    }

    if (!found) {
        printf("Penghapusan edge gagal.\n");
    }
}