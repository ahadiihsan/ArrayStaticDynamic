#include "boolean.h"

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 

typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; 
  int Neff; 
} TabInt;

void MakeEmpty(TabInt *T){
    (*T).Neff = 0;
}

ElType GetFirstIdx(TabInt T){
    return T.TI[1];
}

ElType GetLastIdx(TabInt T){
    return T.TI[T.Neff];
}

void SetTab(TabInt *Tout, TabInt Tin){
    *Tout = Tin;
}

void SetElmt(TabInt *Tout, IdxType indeks, ElType nilai){
    (*Tout).TI[indeks] = nilai;
}

void SetNeff(TabInt *Tout, IdxType neffBaru){
    (*Tout).Neff = neffBaru;
}

boolean IsIdxValid(TabInt T, IdxType i){
    return (i>=0) && (i<=IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i){
    return (i>=0) && (i<=T.Neff);
}

boolean IsEmpty(TabInt T){
    return (T.Neff == 0);
}

boolean IsFull(TabInt T){
    return (T.Neff == IdxMax);
}

