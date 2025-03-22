#include <stdio.h>

int main() {
    float jari2 = 3.1415; 
    float r;
    float hasil;

    printf("Masukan angka : ");
    scanf("%f", &r);
    hasil = jari2 * r * r;
    printf("Luas lingkaran = %f\n", hasil);

  return 0;
}