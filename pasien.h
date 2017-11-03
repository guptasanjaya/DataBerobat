#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include "hastag.h"

struct infotype_P{
    string nama;
    int no_pasien;
    char gender;
};

typedef struct ElmPasien *adr_Pasien;

struct ElmPasien{
    infotype_P info;
    adr_Pasien next;
    adr_Pasien prev;
};

struct List_P{
    adr_Pasien first;
    adr_Pasien last;
};

void createPasien (List_P &LP);
void inPasien (infotype_P *pasien);
void dealokasi (adr_Pasien &pas);

void inFirst_pasien (List_P &LP, adr_Pasien pas);
void inLast_pasien (List_P &LP, adr_Pasien pas);
void inAfter_pasien (List_P &LP, adr_Pasien prec, adr_Pasien pas);

void delFirst_pasien (List_P &LP, adr_Pasien &pas);
void delLast_pasien (List_P &LP, adr_Pasien &pas);
void delAfter_pasien (List_P &LP, adr_Pasien prec, adr_Pasien &pas);


void printPasien (List_P LP);
void sortinsert_pasien (List_P &LP, infotype_P pasien);
void printcurrent_pasien (List_P LP, infotype_P pasien);

adr_Pasien alokasi_pasien (infotype_P x);
adr_Pasien findPas (List_P LP, infotype_P x);
adr_Pasien delbynumber_Pasien (List_P &LP, infotype_P pasien);

#endif // PASIEN_H_INCLUDED
