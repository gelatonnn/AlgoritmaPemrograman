#include <stdio.h>

int mentah = 0, matang = 0, terlalu_matang = 0;

void klasifikasi_pisang(int hari) {
    if (hari >= 0 && hari <= 2) {
        printf("Kategori: Mentah\n");
        mentah++;
    } else if (hari >= 3 && hari <= 5) {
        printf("Kategori: Matang\n");
        matang++;
    } else if (hari > 5) {
        printf("Kategori: Terlalu matang\n");
        terlalu_matang++;
    }
}

void laporan_kategori() {
    printf("Laporan Kematangan Pisang\n");
    printf("Mentah: %d\n", mentah);
    printf("Matang: %d\n", matang);
    printf("Terlalu matang: %d\n", terlalu_matang);
}

int main() {
    int N, perintah, hari;
    scanf("%d", &N);
    
    for (int i = 0; i < N;) { 
        scanf("%d", &perintah);
        
        if (perintah == 1) {
            scanf("%d", &hari);
            if (hari >= 0) {
                klasifikasi_pisang(hari);
                i++; 
            } else {
                printf("Input salah. Masukkan kembali input dengan benar.\n");
            }
        } else if (perintah == 2) {
            laporan_kategori();
        } else {
            printf("Input salah. Masukkan kembali input dengan benar.\n");
        }
    }
    
    printf("Program selesai\n");
    return 0;
}
