#include <stdio.h>

int prima(int n) { //fungsi untuk mengecek bilangan itu prima atau bukan
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0; //mengecek apakah n habis dibagi i atau i+2, jika iya, n bukan prima
    }
    return 1;
}

int jumlah_digit(int n) { //fungsi untuk menghitung jumlah semua digit dalam bilangan
    int total = 0;
    while (n > 0) {
        total += n % 10; //menambahkan digit terakhir dari n kedalam total
        n /= 10; //menghapus digit terakhir dari n dengan membagi dengan 10
    }
    return total;
}

int konversi_bingro(int n) { //fungsi untuk konversi int ke bingro
    if (n == 0) return 0;
    
    int hasil = 0;
    while (n > 0) {
        hasil = hasil * 10 + (n % 2); 
        n /= 2;
    }
    
    return hasil;
}

int main() {
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    if (1 <= A && A <= B && B <= 10000) { //validasi batasan
        int hitung = 0;
        
        for (int angka = A; angka <= B; angka++) { //cari bilangan prima di rentang A hingga B
            if (prima(angka)) {
                int digit = jumlah_digit(angka);
                if (prima(digit)) {
                    hitung++;
                }
            }
        }
        
        int hasil_bingro = konversi_bingro(hitung); //konversi bilangan prima yg memenuhi syarat ke bingro
        
        printf("%d\n", hasil_bingro);
    } else {
        printf("Input tidak valid\n");
    }
    
    return 0;
}
