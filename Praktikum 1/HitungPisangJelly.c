#include <stdio.h>

int main() {
    long N, X, total_pisang = 0, total_jelly = 0;
    long stop = 0; 

    scanf("%ld", &N);

    for (long i = 0; i < N; i++) {
        scanf("%ld", &X);

        if (X == 0) {
            stop = 1;
        }

        if (!stop) { 
            if (X % 2 == 0) {
                total_pisang += X; 
            } else {
                total_jelly += X;
            }
        }
    }

    printf("%ld %ld\n", total_pisang, total_jelly); 
    return 0;
}
