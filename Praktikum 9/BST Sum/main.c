#include <stdio.h>
#include "bst_range_sum.h"

int main() {
    // Bentuk pohon BST nya begini:
    //         8
    //       /   \
    //      3     10
    //     / \      \
    //    2   6      14
    //   /   / \     /
    //  1   4   7   13
    
    BinTree T = NIL;
    ElType x;

    // Pengujian rangeSumBST (pohon kosong)
    int L = 5, R = 10;
    int result = rangeSumBST(T, L, R);
    printf("Hasil penjumlahan key node dalam rentang [%d, %d] adalah %d\n", L, R, result);

    // Bangun BST menggunakan insSearchTree
    int keys[] = {8, 3, 10, 2, 6, 14, 1, 7, 4, 13};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        x.key = keys[i];
        x.count = 1;
        insSearchTree(x, &T);
    }

    // Pengujian rangeSumBST (bukan kosong)
    L = 4; R = 13;
    result = rangeSumBST(T, L, R); // 4 + 6 + 7 + 8 + 10 + 13 = 48

    printf("Hasil penjumlahan key node dalam rentang [%d, %d] adalah %d\n", L, R, result);

    return 0;
}