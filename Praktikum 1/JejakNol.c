#include <stdio.h>

int main() {
    int N, hasil = 0;
    
    scanf("%d", &N);
    
    while (N >= 5) {
        hasil += N / 5;
        N /= 5;
    }

    printf("%d\n", hasil);

    return 0;
}