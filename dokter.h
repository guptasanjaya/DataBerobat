#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED
#include "hastag.h"

struct infotype_D{
    int id;
    string nama;
};

typedef struct ElmDokter *adr_Dokter;

struct ElmDokter{
    infotype_D info;
    adr_Dokter next;
};

struct List_D{
    adr_Dokter first;
};

void createDokter (List_D &LD);
void inDokter (infotype_D *dokter);
void dealokasi (adr_Dokter &dok);

void inFirst_dokter (List_D &LD, adr_Dokter dok);
void inLast_dokter (List_D &LD, adr_Dokter dok);
void inAfter_dokter (List_D &LD, adr_Dokter prec, adr_Dokter dok);

void delFirst_dokter (List_D &LD, adr_Dokter &dok);
void delLast_dokter (List_D &LD, adr_Dokter &dok);
void delAfter_dokter (List_D &LD, adr_Dokter prec, adr_Dokter &dok);


void printDokter (List_D LD);
void sortinsert_dokter (List_D &LD, infotype_D dokter);
void printcurrent_dokter (List_D LD, infotype_D dokter);

adr_Dokter alokasi_dokter (infotype_D dokter);
adr_Dokter findDok (List_D LD, infotype_D dokter);
adr_Dokter delbyID_Dokter (List_D &LD, infotype_D dokter);

#endif // DOKTER_H_INCLUDED
