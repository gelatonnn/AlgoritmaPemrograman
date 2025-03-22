#include <stdio.h>

int main() {
    long kode;
    scanf("%ld", &kode);

    while (kode >= 10) {
        long sum = 0;
        while (kode > 0) {
            sum += kode % 10;
            kode /= 10;
        }
        kode = sum; 
    }

    printf("%ld\n", kode); 
    return 0;
}
