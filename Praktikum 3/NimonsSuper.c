#include <stdio.h>
#include <stdlib.h>

int cariPemenang(int n, int i, int k) {
    int *nimons = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
        nimons[j] = j + 1; 
    }
    
    int jumlahTersisa = n;
    int index = i - 1;
    
    while (jumlahTersisa > 1) {
        index = (index + k) % jumlahTersisa;
        for (int j = index; j < jumlahTersisa - 1; j++) {
            nimons[j] = nimons[j + 1]; 
        }
        jumlahTersisa--; 
    }
    
    int pemenang = nimons[0];
    free(nimons);
    return pemenang;
}

int main() {
    int n, i, k;
    scanf("%d %d %d", &n, &i, &k);
    printf("%d\n", cariPemenang(n, i, k));
    return 0;
}
