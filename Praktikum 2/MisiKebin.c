#include <stdio.h>

int prima(int angka) {
    if (angka < 2) return 0; 
    if (angka == 2) return 1;
    if (angka % 2 == 0) return 0; 
    for (int i = 3; i * i <= angka; i += 2) {
        if (angka % i == 0) return 0; 
    }
    return 1; 
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    
    int result = 0;
    for (int i = A; i <= B; i++) {
        result += prima(i);
    }
    
    printf("%d\n", result);
    return 0;
}
