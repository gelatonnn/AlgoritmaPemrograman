#include "set.h"
#include <stdio.h>

void CreateEmpty(Set *S) {
    S->Count = Nil;
}

boolean IsEmpty(Set S) {
    return S.Count == Nil;
}

boolean IsFull(Set S) {
    return S.Count == MaxEl;
}

void Insert(Set *S, int Elmt) {
    if (IsFull(*S)) {
        return;
    }
    
    for (int i = 0; i < S->Count; i++) {
        if (S->Elements[i] == Elmt) {
            return;
        }
    }
    
    int pos = 0;
    while (pos < S->Count && S->Elements[pos] < Elmt) {
        pos++;
    }
    
    for (int i = S->Count; i > pos; i--) {
        S->Elements[i] = S->Elements[i-1];
    }
    
    S->Elements[pos] = Elmt;
    S->Count++;
}

void Delete(Set *S, int Elmt) {
    if (IsEmpty(*S)) {
        return;
    }
    
    int pos = -1;
    for (int i = 0; i < S->Count; i++) {
        if (S->Elements[i] == Elmt) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        return; 
    }
    
    for (int i = pos; i < S->Count - 1; i++) {
        S->Elements[i] = S->Elements[i+1];
    }
    
    S->Count--;
}

boolean IsMember(Set S, int Elmt) {
    for (int i = 0; i < S.Count; i++) {
        if (S.Elements[i] == Elmt) {
            return true;
        }
    }
    return false;
}
