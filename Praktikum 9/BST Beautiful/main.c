#include "bst.h"
#include <stdio.h>

int main() {
    BinTree root = NIL;
    ElType x;

    // Insert nodes
    x.key = 50;
    x.count = 1;
    insSearchTree(x, &root);
    
    // Print the tree
    printf("Preorder:\n");
    preBeautifulView(root);
    printf("\n");

    printf("Inorder:\n");
    inBeautifulView(root);
    printf("\n");

    printf("Postorder:\n");
    postBeautifulView(root);
    printf("\n");
    
    x.key = 30;
    x.count = 1;
    insSearchTree(x, &root);
    
    // Print the tree
    printf("Preorder:\n");
    preBeautifulView(root);
    printf("\n");

    printf("Inorder:\n");
    inBeautifulView(root);
    printf("\n");

    printf("Postorder:\n");
    postBeautifulView(root);
    printf("\n");

    x.key = 70;
    x.count = 1;
    insSearchTree(x, &root);

    x.key = 20;
    x.count = 1;
    insSearchTree(x, &root);

    x.key = 40;
    x.count = 1;
    insSearchTree(x, &root);

    x.key = 60;
    x.count = 1;
    insSearchTree(x, &root);

    x.key = 80;
    x.count = 1;
    insSearchTree(x, &root);

    // Print the tree
    printf("Preorder:\n");
    preBeautifulView(root);
    printf("\n");

    printf("Inorder:\n");
    inBeautifulView(root);
    printf("\n");

    printf("Postorder:\n");
    postBeautifulView(root);
    printf("\n");

    return 0;
}