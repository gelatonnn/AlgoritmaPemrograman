#include <stdio.h>

void rotasi_kanan(int arr[], int n, int k) {
    k %= n;
    int temp[100]; 
    int i;
    for (i = 0; i < n; i++) temp[(i + k) % n] = arr[i];
    for (i = 0; i < n; i++) arr[i] = temp[i];
}

int main() {
    int n, angka_rotasi;
    scanf("%d %d", &n, &angka_rotasi);
    
    int arr[100], rotasi[100];
    int i, j;
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = 0; i < angka_rotasi; i++) scanf("%d", &rotasi[i]);
    
    for (i = 0; i < angka_rotasi; i++) {
        int temp[100]; 
        for (j = 0; j < n; j++) temp[j] = arr[j];
        rotasi_kanan(temp, n, rotasi[i]);
        
        printf("[");
        for (j = 0; j < n; j++) printf("%d%s", temp[j], (j == n - 1) ? "" : ", ");
        printf("]\n");
    }
    return 0;
}
