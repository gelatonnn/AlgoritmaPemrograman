#include <stdio.h>
#include <string.h>
#include "listnimons.h"

void CreateListNimons(ListNimons *l) {
    int i;
    for (i = 0; i < NIMONS_CAPACITY; i++) {
        l->contents[i].name[0] = '\0'; 
        l->contents[i].age = -1;       
        l->contents[i].height = 0;
    }
}

int listNimonsLength(ListNimons l) {
    int count = 0;
    while (count < NIMONS_CAPACITY && l.contents[count].age != -1) {
        count++;
    }
    return count;
}

boolean isIdxValidNimons(ListNimons l, int i) {
    return (i >= IDX_MIN && i < NIMONS_CAPACITY);
}

boolean isIdxEffNimons(ListNimons l, int i) {
    return (i >= IDX_MIN && i < listNimonsLength(l));
}

boolean isNimonsEmpty(ListNimons l) {
    return listNimonsLength(l) == 0;
}

boolean isNimonsFull(ListNimons l) {
    return listNimonsLength(l) == NIMONS_CAPACITY;
}

void readNimonsList(ListNimons *l) {
    int n;
    scanf("%d", &n);
    getchar(); 
    CreateListNimons(l);
    for (int i = 0; i < n; i++) {
        Nimons m;
        scanf("%s %d %d", m.name, &m.age, &m.height);
        ELMT_NIMONS(*l, i) = m;
    }
}

void printNimonsList(ListNimons l) {
    int len = listNimonsLength(l);
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%s-%d-%d", l.contents[i].name, l.contents[i].age, l.contents[i].height);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
}

void insertNimonsLast(ListNimons *l, Nimons m) {
    int len = listNimonsLength(*l);
    if (len < NIMONS_CAPACITY) {
        ELMT_NIMONS(*l, len) = m;
    }
}

void deleteNimonsLast(ListNimons *l, Nimons *m) {
    int len = listNimonsLength(*l);
    if (len > 0) {
        *m = ELMT_NIMONS(*l, len - 1);
        l->contents[len - 1].name[0] = '\0';
        l->contents[len - 1].age = -1;
        l->contents[len - 1].height = 0;
    }
}

int indexOfNimons(ListNimons l, char *name) {
    for (int i = 0; i < listNimonsLength(l); i++) {
        if (strcmp(l.contents[i].name, name) == 0) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest) {
    int len = listNimonsLength(l);
    if (len == 0) return;
    
    *tallest = l.contents[0];
    *shortest = l.contents[0];
    
    for (int i = 1; i < len; i++) {
        if (l.contents[i].height > tallest->height) {
            *tallest = l.contents[i];
        }
        if (l.contents[i].height < shortest->height) {
            *shortest = l.contents[i];
        }
    }
}
