#include <stdio.h>

int main() {
    int N, angka = 0, original, palindrom;

    scanf("%d", &N);

    original = N;  

    while (N > 0) {
        palindrom = N % 10;
        angka = angka * 10 + palindrom;
        N /= 10;
    }

    if (original == angka)
        printf("1\n"); 
    else
        printf("0\n"); 

    return 0;
}
