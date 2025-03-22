#include <stdio.h>

int main() {
    int n, t, i = 1;
    
    scanf("%d %d", &n, &t);

    while (i <= t) {
        n += 9; 
        printf("tahun ke-%d = %d\n", i, n);
        i++;
    }

    return 0;
}
