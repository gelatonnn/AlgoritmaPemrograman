#include <stdio.h>

int prima(int angka) { //fungsi untuk menerima suatu bilangan sebagai parameter
    if (angka < 2) return 0; //
    if (angka == 2) return 1;
    if (angka % 2 == 0) return 0; 
    for (int i = 3; i * i <= angka; i += 2) { /*Loop dari i = 3 hingga kuadrat dari angka dengan kenaikan 2 (hanya bilangan ganjil)
    Hanya ganjil karena bilangan genap sudah dicek sebelumnya*/
        if (angka % i == 0) return 0; //jika angka habis dibagi i, maka angka tersebut bukan prima
    }
    return 1; 
}

int main() {
    int A, B; //deklarasi variabel A dan B
    scanf("%d %d", &A, &B); //input 2 bilangan A dan B untuk menandakan rentang angka
    
    int result = 0; //inisialisasi awal untuk menyimpan jumlah bilangan prima dalam rentang A sampai B
    for (int i = A; i <= B; i++) { //Loop dari i = A hingga B untuk mengecek setiap angka dalam rentang tersebut
        result += prima(i); //Jika i adalah prima, maka fungsi prima(i) mengembalikan 1, dan ditambah ke result
    }
    
    printf("%d\n", result); //mencetak jumlah bilangan prima di rentang A sampai B
    return 0;
}
