#include <stdio.h>
#include <math.h> //library untuk operasi matematika

int length(int angka) {
    if (angka == 0) return -1; //jika angka 0, maka panjangnya adalah -1
    return (int) log10(angka) + 1; //menghitung jumlah digit dalam angka
}

int getDigit(int angka, int index) { //input angka (bilangan bulat) dan index (posisi digit)
    int len = length(angka);
    if (index >= len || index < 0) return -1;
    return (angka / (int) pow(10, index)) % 10; //mengecek apakah index valid atau tidak (0 <= Index , len)
}

int removeDigit(int angka, int index) { 
    int len = length(angka);
    if (index >= len || index < 0) return angka;
    
    int left = angka / (int) pow(10, index + 1);
    int right = angka % (int) pow(10, index);
    
    return left * (int) pow(10, index) + right;
}

void cariKombinasi(int angka, int current, int panjangAwal) {
    if (length(current) == panjangAwal) {
        printf("%d\n", current);
        return;
    }
    
    for (int i = 0; i < length(angka); i++) {
        int newAngka = removeDigit(angka, i);
        cariKombinasi(newAngka, current * 10 + getDigit(angka, i), panjangAwal);
    }
}

void NimonBruteforce(int angka) {
    cariKombinasi(angka, 0, length(angka));
}