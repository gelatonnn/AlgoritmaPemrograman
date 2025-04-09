#ifndef NIMONSATTACK_H
#define NIMONSATTACK_H

#define _INF 1000000000

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Koordinat;

typedef struct {
    Koordinat posisi;
    char kode[4];
} Kapal;

// Fungsi untuk menghitung jarak langsung antara kapal ke pulau
float hitungJarakKePulau(Kapal kapal, Koordinat pulau) {
    float jarak;
    jarak = sqrt((pulau.x-kapal.posisi.x)*(pulau.x-kapal.posisi.x) + (pulau.y-kapal.posisi.y)*(pulau.y-kapal.posisi.y));
    return jarak;
}

// Fungsi untuk menghitung jarak langsung antara dua kapal
float hitungJarakKeKapal(Kapal kapal1, Kapal kapal2) {
    float jarak;
    jarak = sqrt((kapal1.posisi.x-kapal2.posisi.x)*(kapal1.posisi.x-kapal2.posisi.x) + (kapal1.posisi.y-kapal2.posisi.y)*(kapal1.posisi.y-kapal2.posisi.y));
    return jarak;
}
// Fungsi untuk mengecek apakah kapal valid
// Kapal valid jika tidak ada kapal lain yang memiliki koordinat sama dengan kapal tersebut dan tidak ada kapal lain yang memiliki kode yang sama
// Kapal valid jika tidak berada di pulau
int isKapalValid(Kapal kapal, Koordinat pulau, Kapal *listKapal, int N) {
    if (kapal.posisi.x == pulau.x && kapal.posisi.y == pulau.y) {
        printf("%s nabrak pulau dong!\n", kapal.kode);
        return 1; 
    }
    for (int i = 0; i < N; i++) {
        if (listKapal[i].posisi.x == kapal.posisi.x && listKapal[i].posisi.y == kapal.posisi.y) {
            printf("%s nabrak kapal lain dong!\n", kapal.kode);
            return 2; 
        }
        if (strcmp(listKapal[i].kode, kapal.kode) == 0) {
            printf("%s kok ada dua!\n", kapal.kode);
            return 3;
        }
    }
    return 0;
}

// Silakan gunakan algoritma bubble sorting
// Fungsi untuk mengurutkan kapal berdasarkan jarak terdekat ke pulau
void urutkanKapalTerdekat(Kapal *listKapal, Koordinat pulau, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (hitungJarakKePulau(listKapal[j], pulau) > hitungJarakKePulau(listKapal[j + 1], pulau)) {
                Kapal temp = listKapal[j];
                listKapal[j] = listKapal[j + 1];
                listKapal[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk menerima input, mencari kapal terdekat, dan menampilkan hasil
void cariKapalTerdekat() {
    long long N, R, A, B;
    scanf("%lld %lld", &N, &R);
    scanf("%lld %lld", &A, &B);
    int countdalamRadius = 0;
    
    Koordinat pulau = {A, B};
    Kapal *listKapal = (Kapal *)malloc(N * sizeof(Kapal)); 
    int validCount = 0;

    for (int i = 0; i < N; i++) {
        Kapal temp;
        scanf("%d %d %s", &temp.posisi.x, &temp.posisi.y, temp.kode);
        if (isKapalValid(temp, pulau, listKapal, validCount) == 0) {
            listKapal[validCount++] = temp;
        } else {
            N++;
        }
    }
    
    urutkanKapalTerdekat(listKapal, pulau, validCount);
    for (int i = 0; i < validCount; i++) {
        if (hitungJarakKePulau(listKapal[i], pulau) <= R) {
            printf("%d - %s (%d,%d)\n", i + 1, listKapal[i].kode, listKapal[i].posisi.x, listKapal[i].posisi.y);
            countdalamRadius++;
        }
    }
    if (countdalamRadius < validCount){
        printf("Perdamaian di pulau Mackenbruh telah usai :(\n");
    }
    free(listKapal);
}

#endif
