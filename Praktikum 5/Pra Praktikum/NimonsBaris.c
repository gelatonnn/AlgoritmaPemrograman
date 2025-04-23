#include "Boolean.h"
#include "NimonsBaris.h"

void MakeEmpty(BarisanNimons *T){
    (*T).Neff = 0;
}

int NbElmt(BarisanNimons T){
    return T.Neff;
}

int MaxNbEl(BarisanNimons T){
    return IdxMax-IdxMin+1;
}

IdxType GetFirstIdx(BarisanNimons T){
    return IdxMin;
}

IdxType GetLastIdx(BarisanNimons T){
    return T.Neff;
}

ElType GetElmt(BarisanNimons T, IdxType i){
    return T.baris[i];
}

void SetTab(BarisanNimons Tin, BarisanNimons *Tout){
    for (int i = IdxMin; i<=Tin.Neff ; i++) {
        Tout->baris[i]=Tin.baris[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl(BarisanNimons *T, IdxType i, ElType v){
    (*T).baris[i]=v;
    if (i > (*T).Neff) {
        (*T).Neff = i;
    }
}

void SetNeff(BarisanNimons *T, IdxType N){
    (*T).Neff=N;
}

boolean IsIdxValid(BarisanNimons T, IdxType i){
    boolean valid = FALSE;
    if (i>=IdxMin && i<=IdxMax){
        valid = TRUE;
    } 
    return valid;
}

boolean IsIdxEff(BarisanNimons T, IdxType i){
    boolean eff = FALSE;
    if (i<=T.Neff && i>=IdxMin){
        eff = TRUE;
    } 
    return eff;
}

boolean IsEmpty(BarisanNimons T){
    return (T.Neff==0);
}

boolean IsFull(BarisanNimons T){
    return (T.Neff == IdxMax); 
}

void TulisIsi(BarisanNimons T){
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (int i=IdxMin; i<=T.Neff ; i++){
            printf("%d:%d\n", i-IdxMin, T.baris[i]);
        }
    } 
}

BarisanNimons PlusTab(BarisanNimons T1, BarisanNimons T2){
    BarisanNimons Thsl;
    MakeEmpty(&Thsl);
    if (T1.Neff==T2.Neff){
        for (int i=IdxMin;i<=T2.Neff;i++) {
            Thsl.baris[i]=(T1.baris[i]+T2.baris[i]);
        }
        Thsl.Neff = T1.Neff;
    }
    return Thsl;
}

BarisanNimons MinusTab(BarisanNimons T1, BarisanNimons T2){
    BarisanNimons Thsl;
    MakeEmpty(&Thsl);
    if (T1.Neff==T2.Neff && !IsEmpty(T1) && !IsEmpty (T2)){
        for (int i=IdxMin;i<=T2.Neff;i++) {
            Thsl.baris[i]=(T1.baris[i]-T2.baris[i]);
        }
    }
    Thsl.Neff = T1.Neff;
    return Thsl;
}

ElType ValMax(BarisanNimons T){
    ElType max=T.baris[IdxMin];
    for (int i=IdxMin+1; i<=T.Neff; i++) {
        if (T.baris[i]>max){
            max=T.baris[i];
        }
    }
    return max;
}

ElType ValMin(BarisanNimons T){
    ElType min=T.baris[IdxMin];
    for (int i=IdxMin+1; i<=T.Neff; i++) {
        if (T.baris[i]<min){
            min=T.baris[i];
        }
    }
    return min;
}

IdxType IdxMaxTab(BarisanNimons T){
    ElType max = ValMax(T);
    for (int i = IdxMin; i<=T.Neff; i++) {
        if (T.baris[i]==max){
            return i;
        }
    }
    return IdxUndef;
}

IdxType IdxMinTab(BarisanNimons T){
    ElType min = ValMin(T);
    for (int i = IdxMin; i<=T.Neff; i++) {
        if (T.baris[i]==min){
            return i;
        }
    }
    return IdxUndef;
}
