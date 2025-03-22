#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    int tengah = N / 2; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == tengah - i || j == tengah + i || j == i - tengah || j == N - (i - tengah) - 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}
