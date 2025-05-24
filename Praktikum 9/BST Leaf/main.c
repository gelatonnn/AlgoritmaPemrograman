#include <stdio.h>
#include "bst.h"

int main()
{
    BinTree p = NIL;
    ElType x;

    x.key = 5;
    x.count = 1;
    insSearchTree(x, &p);

    x.key = 3;
    insSearchTree(x, &p);

    x.key = 7;
    insSearchTree(x, &p);

    x.key = 2;
    insSearchTree(x, &p);

    printf("Leaf : %d\n", nbLeaf(p));
    printf("Depth : %d\n", depth(p));

    x.key = 6;
    addLeft(&p, x);

    delLeft(&p, &x);
    printf("Delete : %d\n", x.key);

    delLeft(&p, &x);
    printf("Delete : %d\n", x.key);

    delLeft(&p, &x);
    printf("Delete : %d\n", x.key);

    return 0;
}