#include "boolean.h"

#define IdxMin 1
#define IdxUndef -999 
#include <stdlib.h>

typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct { 
  ElType *TI; 
  int Neff; 
  int MaxEl;
} TabInt;

void MakeEmpty(TabInt *T){
  (*T).Neff = 0;
  (*T).MaxEl = 100;
  (*T).TI = (ElType *) malloc ((*T).MaxEl * sizeof(ElType));
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

void SetMaxEl(TabInt *Tout, IdxType maxElBaru){
    (*Tout).MaxEl = maxElBaru;
    (*Tout).TI = (ElType *) malloc ((*Tout).MaxEl * sizeof(ElType));
}

boolean IsIdxValid(TabInt T, IdxType i){
    return (i>=0) && (i<=T.MaxEl);
}

boolean IsIdxEff(TabInt T, IdxType i){
    return (i>=0) && (i<=T.Neff);
}

boolean IsEmpty(TabInt T){
    return (T.Neff == 0);
}

boolean IsFull(TabInt T){
    return (T.Neff == T.MaxEl);
}
