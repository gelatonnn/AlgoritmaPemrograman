#include "NimonsBalap.h"

char *getKode(kendaraan k) {
    return k.kode;
}

void setKode(kendaraan *k, char *kode) {
    strcpy(k->kode, kode);
}

int getJumlahKursi(kendaraan k) {
    return k.jumlahKursi;
}

void setJumlahKursi(kendaraan *k, int jumlahKursi) {
    k->jumlahKursi = jumlahKursi;
}

int getJumlahRoda(kendaraan k) {
    return k.jumlahRoda;
}

void setJumlahRoda(kendaraan *k, int jumlahRoda) {
    k->jumlahRoda = jumlahRoda;
}

int getKecepatan(kendaraan k) {
    return k.kecepatan;
}

void setKecepatan(kendaraan *k, int kecepatan) {
    k->kecepatan = kecepatan;
}

int getPanjang(kendaraan k) {
    return k.dim.panjang;
}

void setPanjang(kendaraan *k, int panjang) {
    k->dim.panjang = panjang;
}

int getLebar(kendaraan k) {
    return k.dim.lebar;
}

void setLebar(kendaraan *k, int lebar) {
    k->dim.lebar = lebar;
}

int getTinggi(kendaraan k) {
    return k.dim.tinggi;
}

void setTinggi(kendaraan *k, int tinggi) {
    k->dim.tinggi = tinggi;
}

int getBerat(kendaraan k) {
    return k.berat;
}

void setBerat(kendaraan *k, int berat) {
    k->berat = berat;
}

int getHargaJual(kendaraan k) {
    return k.hargaJual;
}

void setHargaJual(kendaraan *k, int hargaJual) {
    k->hargaJual = hargaJual;
}

kendaraan buatKendaraan(char *kode, int jumlahKursi, int jumlahRoda, int kecepatan, dimensi d, int berat, int hargaJual) {
    kendaraan k;
    strcpy(k.kode, kode);
    k.jumlahKursi = jumlahKursi;
    k.jumlahRoda = jumlahRoda;
    k.kecepatan = kecepatan;
    k.dim = d;
    k.berat = berat;
    k.hargaJual = hargaJual;
    return k;
}

void buatKendaraanDefault(kendaraan *k) {
    dimensi d = {10, 10, 10};
    *k = buatKendaraan("XXX", 4, 4, 10, d, 100, 100000);
}

void buatKendaraanInput(kendaraan *k) {
    char kode[4];
    int jumlah_kendaraan, jumlah_roda, kecepatan, panjang, lebar, tinggi, berat, harga;
    scanf("%s %d %d %d %d %d %d %d %d", kode, &jumlah_kendaraan, &jumlah_roda, &kecepatan, &panjang, &lebar, &tinggi, &berat, &harga);
    dimensi d = {panjang, lebar, tinggi};
    *k = buatKendaraan(kode, jumlah_kendaraan, jumlah_roda, kecepatan, d, berat, harga);
}

void printDetailKendaraan(kendaraan k) {
    printf("%s %d %d %d %d %d %d %d %d\n", k.kode, k.jumlahKursi, k.jumlahRoda, k.kecepatan, k.dim.panjang, k.dim.lebar, k.dim.tinggi, k.berat, k.hargaJual);
}

void printJenisKendaraanBerdasarkanRoda(kendaraan k) {
    int roda = getJumlahRoda(k);
    if (roda <= 2) {
        printf("NimoRide\n");
    } else if (roda <= 4) {
        printf("NimoCar\n");
    } else if (roda <= 6) {
        printf("NimoTruck\n");
    } else {
        printf("NimoTanker\n");
    }
}

void printJenisKendaraanBerdasarkanKecepatan(kendaraan k) {
    int kecepatan = getKecepatan(k);
    if (kecepatan <= 10) {
        printf("NimoSlow\n");
    } else if (kecepatan <= 20) {
        printf("NimoFast\n");
    } else if (kecepatan <= 30) {
        printf("NimoSuperFast\n");
    } else { 
        printf("NimoSpeedy\n");
    }
}

void printJenisKendaraanBerdasarkanBerat(kendaraan k) {
    int berat = getBerat(k);
    if (berat <= 100) {
        printf("NimoLight\n");
    } else if (berat <= 200) {
        printf("NimoMedium\n");
    } else if (berat <= 300) {
        printf("NimoHeavy\n");
    } else {
        printf("NimoSuperHeavy\n");
    }
}

void jualKendaraan(kendaraan *k) {
    int hargaRoda = k->jumlahRoda * 1000;
    int hargaKursi = k->jumlahKursi * 10000;
    int hargaDimensi = (k->dim.panjang + k->dim.lebar + k->dim.tinggi) * 100;
    int hargaBerat = k->berat * 100;
    int totalHarga = hargaRoda + hargaKursi + hargaDimensi + hargaBerat;

    if (totalHarga > k->hargaJual) {
        printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", k->kode);
    } else if (totalHarga < k->hargaJual) {
        printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", k->kode);
    } else {
        printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", k->kode);
    }
}

void pBalap(kendaraan *k1, kendaraan *k2) {
    int skor1 = k1->kecepatan * 10 - k1->berat * 2 - k1->dim.lebar;
    int skor2 = k2->kecepatan * 10 - k2->berat * 2 - k2->dim.lebar;

    if (skor1 > skor2) {
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", k1->kode, skor1);
    } else if (skor2 > skor1) {
        printf("Nimons Balap! Kendaraan %s menang! dengan skor %d\n", k2->kode, skor2);
    } else {
        printf("Nimons Balap! Kedua kendaraan %s dan %s seri! dengan skor %d\n", k1->kode, k2->kode, skor1);
    }
}
