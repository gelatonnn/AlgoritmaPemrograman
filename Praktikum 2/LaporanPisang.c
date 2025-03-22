#include <stdio.h>

int mentah = 0, matang = 0, terlalu_matang = 0;

void klasifikasi_pisang(int hari) {
/*Fungsi untuk menerima input hari yg menunjukan berapa lama pinsang disimpan
Fungsi ini juga menentukan kategori pisang tersebut*/
    if (hari >= 0 && hari <= 2) { //Jika jumlah hari antara 0 hingga 2, maka pisang = mentah
        printf("Kategori: Mentah\n");
        mentah++; //menambahkan jumlah pisang mentah
    } else if (hari >= 3 && hari <= 5) { //Jika jumlah hari antara 3 hingga 5, maka pisang = matang
        printf("Kategori: Matang\n");
        matang++; //menambahkan jumlah pisang matang
    } else if (hari > 5) { //Jika jumlah hari lebih dari 5, maka pisang = terlalu matang
        printf("Kategori: Terlalu matang\n");
        terlalu_matang++;//menambahkan jumlah pisang terlalu matang
    }
}

void laporan_kategori() { //Fungsi untuk menampilkan jumlah pisang di setiap kategori
    printf("Laporan Kematangan Pisang\n");
    printf("Mentah: %d\n", mentah);
    printf("Matang: %d\n", matang);
    printf("Terlalu matang: %d\n", terlalu_matang);
}

int main() {
    int N, perintah, hari;
    scanf("%d", &N);
    
    for (int i = 0; i < N;) { /*Loop berjalan hingga N valid
        Kondisi ke 3 gak dicantumin, agar perintah yg salah ga dihitung*/
        scanf("%d", &perintah); //Input perintah ke berapa
        
        if (perintah == 1) {//jika perintah = 1, maka akan diminta memasukan jumlah hari penyimpanan pisang
            scanf("%d", &hari);
            if (hari >= 0) { //jika hari >= 0, maka fungsi klasifikasi diatas akan dipanggil
                klasifikasi_pisang(hari);
                i++; //menambahkan jumlah perintah yg valid
            } else {
                printf("Input salah. Masukkan kembali input dengan benar.\n");
            }
        } else if (perintah == 2) { //jika perintah = 2, maka fungsi laporan kategori akan dipanggil
            laporan_kategori();
        } else { //jika input /= 1 ataupun 2, maka perintah tidak valid
            printf("Input salah. Masukkan kembali input dengan benar.\n");
        }
    }
    
    printf("Program selesai\n");
    return 0;
}
