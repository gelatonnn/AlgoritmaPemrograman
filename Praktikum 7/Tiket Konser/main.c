#include <stdio.h>
#include "tiket_konser.h"

int main() {
    Queue Q;
    CreateQueue(&Q);

    // Cek apakah queue kosong
    if (IsEmpty(Q)) {
        printf("Queue kosong\n");
    }

    Penonton p1 = {"Kebin", 3, 2};
    Penonton p2 = {"Pop", 1, 5};
    Penonton p3 = {"Toto", 2, 4};
    Penonton p4 = {"CloneKebin", 3, 0}; // SN duplikat
    Penonton p5 = {"Jeffrey", 4, 1};

    printf(">> Mendaftarkan: %s\n", NAMA(p1));
    enqueue(&Q, p1);
    displayQueue(Q);

    printf(">> Mendaftarkan: %s\n", NAMA(p2));
    enqueue(&Q, p2);
    displayQueue(Q);

    printf(">> Mendaftarkan: %s\n", NAMA(p3));
    enqueue(&Q, p3);
    displayQueue(Q);

    printf(">> Mendaftarkan: %s\n", NAMA(p4));
    enqueue(&Q, p4); // Seharusnya ditolak karena SN duplikat
    displayQueue(Q);

    printf(">> Mendaftarkan: %s\n", NAMA(p5));
    enqueue(&Q, p5);
    displayQueue(Q);

    // Cek panjang queue
    printf("Panjang antrean penonton: %d antrean\n", Length(Q));

    printf("\n>> Dequeue satu penonton\n");
    Penonton keluar = dequeue(&Q);
    printf("Penonton masuk venue: (%s-%d-%d)\n", NAMA(keluar), SN(keluar), QN(keluar));
    displayQueue(Q);

    printf("\n>> Antrean penonton paling depan sekarang: (%s-%d-%d)\n", NAMA(peek(Q)), SN(peek(Q)), QN(peek(Q)));

    return 0;
}