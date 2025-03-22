#include <stdio.h>

int main() {
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    while (B != 0) {
        int temp = B;
        B = A % B;
        A = temp;
    }
    printf("%d\n", A);
    return 0;
}
