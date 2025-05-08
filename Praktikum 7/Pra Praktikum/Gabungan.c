// #include "queue.h"

// /*
//  * Fungsi untuk menginisialisasi queue.
//  * Mengatur count ke 0.
//  * Parameter:
//  * - q: Pointer ke struct Queue yang akan diinisialisasi.
//  */
// void initQueue(struct Queue *q) {
//     q->count = 0;
// }

// /*
//  * Fungsi untuk mengecek apakah queue kosong.
//  * Parameter:
//  * - q: Pointer ke struct Queue.
//  * Return:
//  * - true jika queue kosong (count == 0), false jika tidak.
//  */
// bool isEmpty(struct Queue *q) {
//     return q->count == 0;
// }

// /*
//  * Fungsi untuk mengecek apakah queue penuh.
//  * Parameter:
//  * - q: Pointer ke struct Queue.
//  * Return:
//  * - true jika queue penuh (count == MAX_SIZE - 1), false jika tidak.
//  */
// bool isFull(struct Queue *q) {
//     return q->count == MAX_SIZE;
// }

// /*
//  * Fungsi untuk menambahkan elemen ke belakang (enqueue) queue.
//  * Prekondisi: Queue belum penuh. Periksa isFull()
//  * sebelum memanggil fungsi ini untuk menghindari overflow. Parameter:
//  * - q: Pointer ke struct Queue.
//  * - value: Nilai integer yang akan ditambahkan.
//  * Postkondisi: Elemen ditambahkan ke queue jika tidak penuh.
//  * Catatan: Jika queue kosong sebelum penambahan keluarkan pesan "Queue penuh!".
//  */
// void enqueue(struct Queue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue penuh!\n");
//         return;
//     }
//     q->items[q->count] = value;
//     q->count++;
// }

// /*
//  * Fungsi untuk mengambil elemen dari depan (dequeue) queue.
//  * Jika queue kosong, fungsi ini akan mencetak pesan error
//  * dan mengembalikan nilai SENTINEL. Karena bukan circular queue, maka array
//  * perlu di geser ke depan untuk mengisi ruang yang kosong setelah dequeue
//  * Parameter:
//  * - q: Pointer ke struct Queue.
//  * Return:
//  * - Nilai elemen integer yang diambil dari depan queue.
//  * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
//  * kosong!".
//  */
// int dequeue(struct Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue kosong!\n");
//         return SENTINEL;
//     }

//     int result = q->items[0];

//     for (int i = 1; i < q->count; i++) {
//         q->items[i - 1] = q->items[i];
//     }
//     q->count--;

//     return result;
// }

// /*
//  * Fungsi untuk melihat elemen di depan queue tanpa menghapusnya (peek).
//  * Prekondisi: Queue tidak kosong. Periksa isEmpty()
//  * sebelum memanggil fungsi ini.
//  * Parameter:
//  * - q: Pointer ke struct Queue.
//  * Return:
//  * - Nilai elemen integer yang berada di depan queue.
//  * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
//  * kosong!".
//  */
// int front(struct Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue kosong!\n");
//         return SENTINEL;
//     }
//     return q->items[0];
// }

// /*
//  * Fungsi untuk mendapatkan jumlah elemen saat ini dalam queue.
//  * Parameter:
//  * - q: Pointer ke struct Queue.
//  * Return:
//  * - Jumlah elemen integer dalam queue saat ini (nilai count).
//  */
// int size(struct Queue *q) {
//     return q->count;
// }


// ----------------------------------------------------------------------------------------------------
// Circular Queue

// NIM     : 18224072
// NAMA    : Francis Galton
// Tanggal : 7 Mei 2025

// #include <stdio.h>
// #include <string.h>
// #include "circular_queue.h"

// /* Mengirim true jika Q kosong */
// /* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
// boolean IsEmpty(Queue Q) {
//     return (IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
// }

// /* Mengirim true jika tabel penampung elemen Q sudah penuh */
// /* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
// boolean IsFull(Queue Q) {
//     return ((IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX) ||
//             (IDX_HEAD(Q) >  (IDX_TAIL(Q))) && (IDX_HEAD(Q) == (IDX_TAIL(Q) + 1)));
// }

// /* Mengirimkan banyaknya elemen Q, 0 jika kosong */
// int Length(Queue Q) {
//     if (IsEmpty(Q)) {
//         return 0;
//     } else if (IDX_HEAD(Q) <= IDX_TAIL(Q)) {
//         return IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
//     } else {
//         return (IDX_MAX - IDX_HEAD(Q) + 1) + (IDX_TAIL(Q) + 1);
//     }
// }

// /* I.S. sembarang */
// /* F.S. mengembalikan Q kosong dengan kondisi sbb: */
// /* - idxHead=IDX_UNDEF; */
// /* - idxTail=IDX_UNDEF. */
// void CreateQueue(Queue *Q) {
//     IDX_HEAD(*Q) = IDX_UNDEF;
//     IDX_TAIL(*Q) = IDX_UNDEF;
// }

// /* Proses: Menambahkan X pada Q dengan aturan FIFO */
// /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
// /* F.S. Tail "maju" dengan mekanisme circular buffer,
//         X menjadi idxTail yang baru
//         Jika Q kosong, idxHead dimulai dari 0 */
// void enqueue(Queue *Q, ElType X) {
//     if (IsEmpty(*Q)) {
//         IDX_HEAD(*Q) = 0;
//         IDX_TAIL(*Q) = 0;
//     } else {
//         if (IDX_TAIL(*Q) == IDX_MAX){
//             IDX_TAIL(*Q) = 0;
//         } else {
//             IDX_TAIL(*Q) ++;
//         }
//     }
//     TAIL(*Q) = X;
// }

// /* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
// /* I.S. Q tidak mungkin kosong */
// /* F.S. mengembalikan nilai Q pada idxHead;
//         Head "maju" dengan mekanisme circular buffer;
//         Q mungkin kosong */
// ElType dequeue(Queue *Q) {
//     ElType val = HEAD(*Q);
//     if (IDX_HEAD(*Q) == IDX_TAIL(*Q)) {
//         IDX_HEAD(*Q) = IDX_UNDEF;
//         IDX_TAIL(*Q) = IDX_UNDEF;
//     } else {
//         if (IDX_HEAD(*Q) == IDX_MAX) {
//             IDX_HEAD(*Q) = 0;
//         } else {
//             IDX_HEAD(*Q)++;
//         }
//     }
//     return val;
// }

// /* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
// /* I.S. Q tidak mungkin kosong */
// /* F.S. Mengembalikan nilai pada idxHead */
// ElType peek(Queue Q) {
//     return HEAD(Q);
// }

// /* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
//    siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
// /* I.S. q boleh kosong */
// /* F.S. Jika q tidak kosong: [e1, e2, ..., en] */
// /* Contoh : jika ada tiga elemen bernilai "Tim_1", "Tim_2", dan "Tim_3" akan dicetak: [Tim_1, Tim_2, Tim_3] */
// /* Jika Queue kosong : menulis [] */
// /* Note: Output mengandung newline */
// void displayQueue(Queue q) {
//     printf("[");
//     if (!IsEmpty(q)) {
//         int i = IDX_HEAD(q);
//         while (i != IDX_TAIL(q)) {
//             printf("%s, ", q.Tab[i].namaTim);
//             i = (i + 1) % (IDX_MAX + 1);
//         }
//         printf("%s", q.Tab[i].namaTim);
//     }
//     printf("]\n");
// }



// -------------------------------------------------------------------------------------

// #include <stdio.h>
// #include "stack.h"

// /* I.S. Sembarang */
// /* F.S. Membuat sebuah Stack s yang kosong berkapasitas CAPACITY */
// /* jadi indeksnya antara 0..CAPACITY-1 */
// void CreateStack(Stack *s) {
//     IDX_TOP(*s) = IDX_UNDEF;
// }

// /* Ciri stack kosong: idxTop bernilai IDX_UNDEF */
// /********** Predikat Untuk test keadaan KOLEKSI **********/
// /* Mengirim true jika Stack kosong: lihat definisi di atas */
// boolean isEmpty(Stack s) {
//     return IDX_TOP(s) == IDX_UNDEF;
// }

// /* Mengirim true jika Stack penuh */
// boolean isFull(Stack s) {
//     return IDX_TOP(s) == CAPACITY - 1;
// }

// /* Mengirim ukuran Stack s saat ini */
// int length(Stack s) {
//     return isEmpty(s) ? 0 : IDX_TOP(s) + 1;
// }

// /* Menambahkan val sebagai elemen Stack s.
// I.S. s mungkin kosong, tidak penuh
// F.S. val menjadi TOP yang baru, TOP bertambah 1 */
// void push(Stack *s, ElType val) {
//     if (isEmpty(*s)) {
//         IDX_TOP(*s) = 0;
//     } else {
//         IDX_TOP(*s)++;
//     }
//     TOP(*s) = val;
// }

// /* Menghapus X dari Stack S.
// I.S. S tidak mungkin kosong
// F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
// void pop(Stack *s, ElType *val) {
//     *val = TOP(*s);
//     if (IDX_TOP(*s) == 0) {
//         IDX_TOP(*s) = IDX_UNDEF;
//     } else {
//         IDX_TOP(*s)--;
//     }
// }

// ----------------------------------------------------------------------------------------------
// ROUND ROBIN
// void roundRobin(Queue *q, int t) {
//     int n = q->count;
//     for (int i = 0; i < n; i++) {
//         ElType job;
//         dequeue(q, &job);
//         if (job.cost <= t) {
//             printf("%d telah selesai diproses\n", job.id);
//         } else {
//             job.cost -= t;
//             enqueue(q, job);
//         }
//     }
// }

// ------------------------------------------------------------------------------------
// //PRIORITY QUEUE
// ----------------------------------------
// ~~~~~ CONTOH KASUS KALO PRIORITAS TERTINGGI ADALAH ANGKA YANG TERESAR ~~~~~
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 10  // Ukuran queue

// // Struktur untuk queue
// struct Queue {
//     int items[MAX_SIZE];
//     int size;
// };

// // Fungsi untuk inisialisasi queue
// void initQueue(struct Queue *q) {
//     q->size = 0;
// }

// // Fungsi untuk mengecek apakah queue kosong
// int isEmpty(struct Queue *q) {
//     return q->size == 0;
// }

// // Fungsi untuk mengecek apakah queue penuh
// int isFull(struct Queue *q) {
//     return q->size == MAX_SIZE;
// }

// // Fungsi untuk menambahkan elemen ke dalam queue dengan urutan prioritas
// void enqueue(struct Queue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue penuh!\n");
//         return;
//     }
//     int i = q->size - 1;
//     while (i >= 0 && q->items[i] < value) {  // Menemukan posisi yang sesuai untuk elemen dengan prioritas lebih tinggi
//         q->items[i + 1] = q->items[i];  // Geser elemen
//         i--;
//     }
//     q->items[i + 1] = value;  // Tempatkan elemen di posisi yang benar
//     q->size++;
// }

// kalo semisalkan di soal diminta untuk bisa mengeluarkan elemen dengan prioritas tertinggi makan gini=>
// // Fungsi untuk mengeluarkan elemen dengan prioritas tertinggi
// int dequeue(struct Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue kosong!\n");
//         return -1;
//     }
//     int value = q->items[0];  // Ambil elemen pertama yang memiliki prioritas tertinggi
//     for (int i = 1; i < q->size; i++) {
//         q->items[i - 1] = q->items[i];  // Geser semua elemen
//     }
//     q->size--;
//     return value;
// }

// int main() {
//     struct Queue q;
//     initQueue(&q);

//     enqueue(&q, 30);
//     enqueue(&q, 20);
//     enqueue(&q, 50);
//     enqueue(&q, 10);

//     printf("Dequeued: %d\n", dequeue(&q));  // Keluarin 50
//     return 0;
// }

// ----------------------------------------------------
// ----------------------------------------------------
// semisalkan ada =>
// typedef struct {
//     int prio;    // prioritas
//     int data;    // isi data
// } ElType;

// nah otomatis untuk unqueuenya bakal gini =>
// void enqueue(Queue *Q, ElType X) {
//     if (IsEmpty(*Q)) {
//         IDX_HEAD(*Q) = IDX_TAIL(*Q) = 0;
//         TAIL(*Q) = X;
//     } else {
//         int i = IDX_TAIL(*Q);
//         // geser semua elemen yang prioritasnya lebih kecil
//         while (i >= IDX_HEAD(*Q) && Q->Tab[i].prio < X.prio) {
//             Q->Tab[i + 1] = Q->Tab[i];
//             i--;
//         }
//         Q->Tab[i + 1] = X;
//         IDX_TAIL(*Q)++;
//     }
// }

// dequeue bisa kaya gini =>
// void dequeue(Queue *Q, ElType *X) {
//     *X = HEAD(*Q);
//     if (IDX_HEAD(*Q) == IDX_TAIL(*Q)) {
//         IDX_HEAD(*Q) = IDX_UNDEF;
//         IDX_TAIL(*Q) = IDX_UNDEF;
//     } else {
//         IDX_HEAD(*Q)++;
//     }
// }
// ----------------------------------------------------
// ----------------------------------------------------
// ~~~~~ CONTOH KASUS KALO PRIORITAS TERTINGGI ADALAH ANGKA YANG TEKECIL ~~~~~
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 10

// struct Queue {
//     int items[MAX_SIZE];
//     int size;
// };

// void initQueue(struct Queue *q) {
//     q->size = 0;
// }

// int isEmpty(struct Queue *q) {
//     return q->size == 0;
// }

// int isFull(struct Queue *q) {
//     return q->size == MAX_SIZE;
// }

// void enqueue(struct Queue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue penuh!\n");
//         return;
//     }
//     int i = q->size - 1;
//     while (i >= 0 && q->items[i] > value) {  // Prioritas lebih tinggi ke angka kecil
//         q->items[i + 1] = q->items[i];
//         i--;
//     }
//     q->items[i + 1] = value;
//     q->size++;
// }

// int dequeue(struct Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue kosong!\n");
//         return -1;
//     }
//     int value = q->items[0];
//     for (int i = 1; i < q->size; i++) {
//         q->items[i - 1] = q->items[i];
//     }
//     q->size--;
//     return value;
// }

// int main() {
//     struct Queue q;
//     initQueue(&q);
    
//     enqueue(&q, 5);
//     enqueue(&q, 3);
//     enqueue(&q, 7);
    
//     printf("Dequeue: %d\n", dequeue(&q));  // Output: 3
//     printf("Dequeue: %d\n", dequeue(&q));  // Output: 5
//     printf("Dequeue: %d\n", dequeue(&q));  // Output: 7
    
//     return 0;
// }

// -------------------------------------------------------------------------
/** DYNAMIC STACK
 * #include "dynstack.h"

void CreateDynStack(DynStack *s) {
    s->capacity = INITIAL_CAPACITY;
    s->buffer = (ElType *)malloc(s->capacity * sizeof(ElType));
    s->top = -1;
}

boolean isEmpty(DynStack s) {
    return s.top == -1;
}

int length(DynStack s) {
    return s.top + 1;
}

void push(DynStack *s, ElType val) {
    if (s->top == s->capacity - 1) {
        // Perlu resize
        s->capacity *= 2;
        s->buffer = (ElType *)realloc(s->buffer, s->capacity * sizeof(ElType));
    }
    s->top++;
    s->buffer[s->top] = val;
}

void pop(DynStack *s, ElType *val) {
    if (!isEmpty(*s)) {
        *val = s->buffer[s->top];
        s->top--;
    }
}

void destroy(DynStack *s) {
    free(s->buffer);
    s->buffer = NULL;
    s->top = -1;
    s->capacity = 0;
}

 */
