#include "hashmap.h"

void CreateEmpty(HashMap *M) {
    M->Count = Nil;
    for (int i = 0; i < MaxEl; i++) {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

address Hash(keytype K) {
    return K % MaxEl;
}

valuetype Value(HashMap M, keytype k) {
    address idx = Hash(k);
    for (int i = 0; i < MaxEl; i++) {
        int probeIdx = (idx + i) % MaxEl;
        if (M.Elements[probeIdx].Key == k) {
            return M.Elements[probeIdx].Value;
        } else if (M.Elements[probeIdx].Key == Undefined) {
            return Undefined;
        }
    }
    return Undefined;
}

void Insert(HashMap *M, keytype k, valuetype v) {
    if (M->Count == MaxEl || Value(*M, k) != Undefined) {
        return;
    }

    address idx = Hash(k);
    for (int i = 0; i < MaxEl; i++) {
        int probeIdx = (idx + i) % MaxEl;
        if (M->Elements[probeIdx].Key == Undefined) {
            M->Elements[probeIdx].Key = k;
            M->Elements[probeIdx].Value = v;
            M->Count++;
            return;
        }
    }
}

void printHashMap(HashMap M) {
    for (int i = 0; i < MaxEl; i++) {
        printf("%d:\n", i);
        printf("  Key: %d\n", M.Elements[i].Key);
        printf("  Value: %d\n", M.Elements[i].Value);
    }
}

void Delete(HashMap *M, keytype k) {
    address idx = Hash(k);
    for (int i = 0; i < MaxEl; i++) {
        int probeIdx = (idx + i) % MaxEl;
        if (M->Elements[probeIdx].Key == k) {
            M->Elements[probeIdx].Key = Undefined;
            M->Elements[probeIdx].Value = Undefined;
            M->Count--;
            return;
        } else if (M->Elements[probeIdx].Key == Undefined) {
            return; 
        }
    }
}


