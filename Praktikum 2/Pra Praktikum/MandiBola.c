#include <stdio.h>
#include "MandiBola.h"

int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    return 10000*jumlah_anak+20000*jumlah_dewasa+15000*jumlah_lansia;
} 

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    int total_biaya = HitungBiayaTiket(jumlah_anak,jumlah_dewasa,jumlah_lansia);
    printf("Tiket berhasil dibeli!\nRincian:\n");
    printf("- Jumlah anak-anak: %d\n",jumlah_anak);
    printf("- Jumlah dewasa: %d\n",jumlah_dewasa);
    printf("- Jumlah lansia: %d\n",jumlah_lansia);
    printf("- Total biaya: %d\n", total_biaya);
}

void SelamatDatang(int input){
    int jumlah_anak,jumlah_dewasa,jumlah_lansia;
    jumlah_anak = input%10;
    jumlah_dewasa = (input/10)%10;
    jumlah_lansia = input/100;
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    printf("Jumlah anak: %d\n",jumlah_anak);
    printf("Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("Jumlah lansia: %d\n", jumlah_lansia);
    PrintTiket(jumlah_anak,jumlah_dewasa,jumlah_lansia);
}

void HandleNimonsHunting(long input){
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    
    int jumlah_pergerakan = input % 10;
    input /= 10;
    int jumlah_lubang = input % 10;
    input /= 10;
    int jumlah_harta_karun = input % 10;
    input /= 10;
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", jumlah_pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n", jumlah_lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n", jumlah_harta_karun);
    
    int jumlah_lubang_ditutup = 0;
    int total_harta_karun = 0;
    int total_langkah = 0;
    for(int i = 1; i <= jumlah_pergerakan; i++){
        printf("Langkah ke-%d\n", i);
        if(input%10 == 0 && i == 1){
            printf("Nimons tidak bergerak\n");
            input /= 10;
        } else if(input%10 > 0){
            printf("Nimons bergerak sejauh %d langkah\n",input%10);
            total_langkah += input%10;
            input /= 10;
        }
        if(input%10 == 1){
            printf("Nimons menemukan harta karun!\n");
            total_harta_karun++;
        }
        input /= 10;
        if(input%10 == 1){
            printf("Nimons menutup lubang!\n");
            jumlah_lubang_ditutup++;
        }
        input /= 10;
    }
    int harga = input;
    int total_harga_harta_karun = total_harta_karun*harga*5;
    int total_biaya_ganti_rugi = harga*jumlah_lubang_ditutup;
    printf("\nTotal lubang yang ditutup: %d dari %d lubang\n",jumlah_lubang_ditutup,jumlah_lubang);
    printf("Total harta karun yang ditemukan: %d\n",total_harta_karun);
    printf("Total harga harta karun yang ditemukan: %d\n",total_harga_harta_karun);
    printf("Total langkah yang ditempuh: %d\n",total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %d\n",total_biaya_ganti_rugi);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n",total_harga_harta_karun-total_biaya_ganti_rugi);
}