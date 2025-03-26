#include <stdio.h>
#include <stdlib.h>

int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long kpk(int a, int b) {
    return (long long)a * b / fpb(a, b);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long maxScore = 0;

    for (int skip = -1; skip < n; skip++) {
        int temp[1000], size = 0;
        for (int j = 0; j < n; j++) {
            if (j != skip) {
                temp[size++] = arr[j];
            }
        }

        if (size == 0) continue;

        int currFPB = temp[0], currKPK = temp[0];
        for (int j = 1; j < size; j++) {
            currFPB = fpb(currFPB, temp[j]);
            currKPK = kpk(currKPK, temp[j]);
        }

        long long score = (long long)currFPB * currKPK;
        if (score > maxScore) {
            maxScore = score;
        }
    }

    printf("%lld\n", maxScore);
    return 0;
}
