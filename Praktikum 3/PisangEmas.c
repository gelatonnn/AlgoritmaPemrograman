#include <stdio.h>

void reverse(int *arr, int mulai, int selesai) {
    while (mulai < selesai) {
        int temp = arr[mulai];
        arr[mulai] = arr[selesai];
        arr[selesai] = temp;
        mulai++;
        selesai--;
    }
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    
    int batu[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &batu[i]);
    }
    
    reverse(batu, 0, n - 1);
    
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (batu[i] == target) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        if (index == 0) {
            batu[index] = batu[index + 1];
        } else if (index == n - 1) {
            batu[index] = batu[index - 1];
        } else {
            batu[index] = batu[index - 1] + batu[index + 1];
        }
        reverse(batu, index + 1, n - 1);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", batu[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
