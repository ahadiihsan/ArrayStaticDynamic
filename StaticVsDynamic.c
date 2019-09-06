/* Tugas Algoritma dan Struktur Data */

/* Nama Anggota Kelompok */
// 1. Ahadi Ihsan Rasyidin 13518006
// 2. Jundullah            13518027

/* Perbedaan Deklarasi Array Static dan Array Dynamic serta primitif lain yang
   terkait */
/*===========================================================================*/
   #include "boolean.h"
   #include <math.h>

   #define IdxMax 100
    /*
       IdxMax didefinisikan "HANYA" untuk Array Static. Hal itu merujuk pada
       array Dynamic yang tidak memiliki batas khusus yang telah didevinisikan.
    */

   #define IdxMin 1       /* Indeks minimum array */
   #define IdxUndef -999  /* Indeks tak terdefinisi*/
   typedef int IdxType;   /* type indeks */
   typedef int ElType;    /* type elemen tabel */
   /* Devinisi di atas digunakan oleh kedua jenis array */

/*===========================================================================*/

/*Deklarasi Array -----------------------------------------------------------*/

/*Array Static*/
typedef struct {
  ElType TI[IdxMax+1];
  int Neff;
} TabInt;
/*Array Static telah didevinisikan dengan memori sebesar IdxMax (100)*/

/*Array Dynamic*/
typedef struct {
  ElType *TI;
  int Neff;
  int MaxEl;
} TabInt;

/*
   Dalam deklarasi awalnya array static telah ditentukan ukuran jumlah elemen
   yang dapat ditampung oleh array terdevinisi. Ukuran array static ini tidak
   dapat dirubah didalam keberjalanan program.
   Berkebalikan dengan array static, array dynamic memiliki ukuran memori yang
   belum didevinisikan. Ukuran ini akan ditentukan saat program telah berjalan.
   Dengan demikian array Dynamic memiliki fleksibilitas dalam jumlah elemennya.
*/

/* KONSTRUKTOR --------------------------------------------------------------*/

/*Array Static*/
void MakeEmpty(TabInt *T){
    (*T).Neff = 0;
}
/*Array Dynamic*/
void MakeEmpty(TabInt *T, IdxType size){
  (*T).Neff = 0;
  (*T).MaxEl = size;
  (*T).TI = (ElType *) malloc (((*T).MaxEl+1) * sizeof(ElType));
}

/*
  Ada Perbedaan yang terlihat dengan jelas dalam konstruktor array. Pada array
  Static konstruktor MakeEmpty() hanya berisi inisialisasi nilai Efektif array
  menjadi nol, yang berarti array kosong. Berbeda dengan array Dynamic dimana
  konstruktor MakeEmpty() juga berfungsi sebagai prosedur untuk memberikan
  ukuran memori pada array dynamic.
*/

/*SELEKTOR ------------------------------------------------------------------*/

/*Array Static dan Array Dynamic*/
ElType GetElmt(TabInt T, IdxType i){
  return T.TI[i];
}
IdxType GetNeff(TabInt T){
  return T.Neff;
}
IdxType GetFirstIdx(TabInt T){
  return IdxMin;
}
IdxType GetLastIdx(TabInt T){
  return GetNeff(T);
}

/*
  Pada selektor tidak ada perbedaan antara array Static dengan
  array Dynamic. Index pertama didevinisikan dengan IdxMin dan index element
  terakhir didapatkan dengan nilai Neff. Cara akses terhadap element array juga
  tidak memiliki perbedaan.
*/
/*****************************************************************************/

/*Array Static*/
int MaxNbEl (TabInt T) {
	return IdxMax;
}
/*Array Dynamic*/
int MaxNbEl (TabInt T) {
	return (T).MaxEl;
}

/*
  Pada selektor yang memberikan ukuran array, terdapat perbedaan dimana Array
  Static mengembalikan nilai IdxMax sedangkan array Dynamic mengembalikan nilai
  MaxEl yang tersimpan dalam kesatuan typedef array.
*/

/*SELEKTOR set --------------------------------------------------------------*/

void SetTab (TabInt *Tout, TabInt Tin) {
	/*	Kamus */
	int i=GetFirstIdx(Tin);
	/*	Algoritma */
  	MakeEmpty(MaxNbEl(Tin),Tout);
  	while (i<=GetLastIdx(Tin))
    {
  		SetElmt(Tout,i,GetElmt(Tin,i));
  		i++;
  	}
} /*Pada selektor ini tidak ada perlakuan khusus untuk kedua jenis array*/

void SetElmt(TabInt *Tout, IdxType indeks, ElType nilai){
    (*Tout).TI[indeks] = nilai;
}/*Pada selektor ini tidak ada perlakuan khusus untuk kedua jenis array*/

void SetNeff(TabInt *Tout, IdxType neffBaru){
    GetNeff(*T) = neffBaru;
} /*Selektor ini berlaku untuk kedua jenis array tanpa ada perlakuan khusus*/

/*
  Selektor set diatas dapat digunakan di kedua jenis array, baik Static atau
  Dynamic.
*/

/*****************************************************************************/
void SetSize (TabInt *T, IdxType N) {
	(*T).TI = (ElType *) malloc ((N+1)* sizeof (ElType));
	(*T).Size = N;
}/*Selektor khusus untuk array Dynamic. Dengan selektor ini penggantian Ukuran
   array dapat dilakukan dengan lebih mudah.*/

/*Test Index ----------------------------------------------------------------*/

/*Array Static*/
boolean IsIdxValid(TabInt T, IdxType i){
  return (i>=0) && (i<=IdxMax);
}
/*Array Dynamic*/
boolean IsIdxValid(TabInt T, IdxType i){
  return (i>=0) && (i<=T.MaxEl);
}

/*
  IsIdxValid digunakan untuk menguji apakah index i berada pada range Ukuran
  dari array. Ada perbedaan antara array Static dengan array Dynamic yaitu
  pada batas akhir index terdevinisi. Dimana array Static telah didevinisikan
  dengan IdxMax sedangkan array Dynamic dapat berubah dan diakses dengan T.maxEl
*/

boolean IsIdxEff(TabInt T, IdxType i){
  return (i>=GetFirstIdx(T)) && (i<=GetLastIdx(T));
}/*Pada selektor ini penggunaan pada kedua array tidak memiliki perbedaan*/

boolean IsEmpty(TabInt T){
  return (GetNeff(T) == 0);
}
boolean IsFull(TabInt T){
  return (GetNeff(T) == MaxNbEl(T));
}
/*
  Dua fungsi di atas yaitu IsEmpty() dan IsFull() dapat digunakan pada kedua
  jenis array tanpa ada perlakuan khusus. Perbedaan akan didapat pada fungsi
  MaxNbEl() dimana ukuran array masing-masing jenis didevinisikan dengan cara
  yang berbeda.
*/

/*Primitif lain -------------------------------------------------------------*/

boolean IsSimetris(TabInt T)
/*
Menghasilkan true jika tabel simetrik
Tabel disebut simetrik jika:
  elemen pertama= elemen terakhir,
  elemen kedua= elemen sebelum terakhir, dan seterusnya
Tabel kosong adalah tabel simetris.
*/
{
  boolean simetrik;
  IdxType i;
  simetrik = true;
  j = GetNeff(T);
  i = GetFirstIdx(T);
  if (IsEmpty(T)){
    simetrik = true;
  }
  else{
    while (i<=j) {
      if (GetElmt(T,j) != GetElmt(T,i)) {
        simetrik = false;
      }
      j--;
      i++;
    }
  }
  return simetrik;
}
/*
  Fungsi IsSimetris() dapat digunakan pada kedua jenis array tanpa adanya
  perlakuan khusus.
*/
/*###########################################################################*/

TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/*
   Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama
   dijumlahkan
*/
{
  IdxType i;
  for (i = IdxMin; i <= GetNeff(T1); i++) {
    GetElmt(T1,i) = GetElmt(T1,i)+GetElmt(T2,i);
  }
  return T1;
}
/*
  Fungsi PlusTab() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

int NbOccX(TabInt T, ElType X)
/*
  Menghasilkan berapa banyak kemunculan elemen bernilai X ditabel T.
  Jika tabel kosong, menghasilkan 0
*/
{
  int count = 0;
  for (i = GetFirstIdx(T); i <=GetLastIdx(T); i++) {
    if (GetElmt(T,i) == X){
      count++;
    }
  return count;
  }
}
/*
  Fungsi NbOccX() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

boolean IsEQ (TabInt T1, TabInt T2)
/*
   Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2
   dan semua elemennya sama
*/
{
  boolean equal = true;
  IdxType i;
  if (GetNeff(T1)==GetNeff(T2)){
    for (i = 1; i<=GetNeff(T1); i++) {
      if (GetElmt(T1,i)!=GetElmt(T2,i)) {
        equal = false;
      }
    }
  }
  else{
    equal = false;
  }
  return equal;
}
/*
  Fungsi IsEQ() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  IdxType i=1;
  if (IsEmpty(T)) {
    return IdxUndef;
  }
  else{
    while ((GetElmt(T,i)!=X) && (i<GetNeff(T)))
    {
      i++;
    }
    if (GetElmt(T,i)==X){
      return i;
    }
    else{
      return IdxUndef;
    }
  }
}
/*
  Fungsi Search1() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
  IdxType i;
  i = GetNeff(*T)
  if (IsEmpty(*T)){
  	SetElmt(T,1,X);
  }
  else{
  		SetElmt(T,0,X);
      while((i>=0) || (GetElmt(*T,i)!=X)){
        i--;
      }
      if (i>0){
        printf("nilai sudah ada");
      }
      else{
        SetElmt(T,GetLastIdx(*T)+1,X);
      }
}
/*
  prosedur AddElUnik() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

void ClosestPair(TabInt T, ElType * P1, Eltype * P2 )
/*
  I.S.: T terdefinisi, mungkin kosong, P1 dan P2 sembarang.
  F.S.: Jika T tidak kosong, P1 dan P2 berisi 2 elemen T
        pada posisi berurutan yang memiliki selisih (selalu positif) terkecil.
        Jika kedua elemen nilainya berbeda,
        maka P1 adalah elemen yang bernilai lebih kecil.
        Jika ada beberapa pasang elemen yang memiliki selisih terkecil,
        maka diambil pasangan elemen yang muncul pertama kali.
        Jika T kosong atau hanya terdiri atas 1 elemen,
        P1 dan P2 berisi elemen tidak terdefinisi yaitu -999.
*/
{
  IdxType i,iSel;
  ElType mSel;

  if ((IsEmpty(T)) || (GetNeff(T)==1)) {
    *P1 = IdxUndef;
    *P2 = IdxUndef;
  }
  else{
    mSel = abs(GetElmt(T,1) - GetElmt(T,2));
    iSel = 1;
    for (i = 2; i < GetNeff(T); i++) {
      if (abs(GetElmt(T,i)-GetElmt(T,i+1)) < mSel) {
        mSel = abs(GetElmt(T,i)-GetElmt(T,i+1));
        iSel = i;
      }
    }
    if (iSel < (iSel+1)) {
      *P1 = GetElmt(T,iSel);
      *P2 = GetElmt(T,iSel+1);
    }
    else{
      *P1 = GetElmt(T,iSel+1);
      *P2 = GetElmt(T,iSel);
    }
  }
}

/*
  prosedur ClosestPair() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

boolean IsFront(TabInt T1, TabInt T2)
/*Mengembalikan true jika elemen-elemen T1 merupakan bagian awal dari T2*/
{
  boolean front = true;
  IdxType i;
  if (IsEmpty(T)) {
    front = true;
  }
  else{
    if (GetNeff(T1)>GetNeff(T2)){
      front = false;
    }
    else{
      i = 1;
      while (i<=GetNeff(T1)) {
        if (GetElmt(T1,i)!=GetElmt(T2,i){
          front = false;
        }
        i++;
      }
    }
  }
  return front;
}
/*
  prosedur ClosestPair() juga dapat diimplementasikan secara langsung pada kedua
  jenis array. karena sub fungsi yang digunakan telah di definisikan secara
  terpisah.
*/
/*###########################################################################*/

/*===========================================================================*/
/*KESIMPULAN*/

/*
  Pada penggunaan primitif dalam array Static dan array Dynamic ketika Fungsi
  atau Prosedur tersebut tidak mengakses langsung batas ukuran array maka tidak
  terdapat perbedaan atau perlakuan khusus terhadap fungsi atau prosedur itu.
  Jadi fungsi atau prosedur tersebut dapat langsung di diimplementasikan pada
  masing-masing jenis array baik Static maupun Dynamic.
*/
