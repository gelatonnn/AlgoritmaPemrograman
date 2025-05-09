#include <stdio.h>
#include "stack.h"

void printStack(Stack s)
{
    if (isEmpty(s))
    {
        printf("EMPTY\n");
    }
    else
    {
        for (int i = 0; i <= s.idxTop; i++)
        {
            printf("%d ", s.buffer[i]);
        }
        printf("\n");
    }
}

int main()
{
    Stack s1, s2;
    ElType val;

    CreateStack(&s1);
    CreateStack(&s2);

    push(&s1, 23);
    push(&s1, 92);
    push(&s1, 98);
    push(&s1, 31);
    push(&s1, 3);
    push(&s1, 34);
    printf("Stack 1 :\n");
    printStack(s1);
    printf("Stack 2 :\n");
    printStack(s2);

    SortirStack(&s1, &s2);

    printf("Stack 1 :\n");
    printStack(s1);
    printf("Stack 2 :\n");
    printStack(s2);

    return 0;
}