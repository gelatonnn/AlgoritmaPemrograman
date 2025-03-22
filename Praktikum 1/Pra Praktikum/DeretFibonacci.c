#include <stdio.h>

int main (){
    int N;
    scanf("%d", &N);

    int a = 0, b = 1, next;
    for (int i = 0; i<N; i++){
        printf("%d", a);
        if (i < N - 1){
            printf(" ");
        }
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}