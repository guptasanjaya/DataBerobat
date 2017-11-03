#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "hastag.h"
#include "dokter.h"
#include "pasien.h"

typedef struct ElmRelasi *adr_Relasi;

struct ElmRelasi {
    adr_Dokter nexdok;
    adr_Pasien nexpas;
    adr_Relasi next;
};

struct List_R{
    adr_Relasi first;
};

void createRelasi (List_R LR);
adr_Relasi alokasi_relasi (adr_Dokter dok, adr_Pasien pas);
void dealokasi (adr_Relasi &rel);

void inFirst_relasi (List_R &LR, adr_Relasi rel);
void inLast_relasi (List_R &LR, adr_Relasi rel);
void inAfter_relasi (List_R &LR, adr_Relasi prec, adr_Relasi rel);

void delFirst_relasi (List_R &LR, adr_Relasi &rel);
void delLast_relasi (List_R &LR, adr_Relasi &rel);
void delAfter_relasi (List_R &LR, adr_Relasi prec, adr_Relasi &rel);

adr_Relasi searchRel (List_R LR, adr_Dokter dok, adr_Pasien pas);
adr_Relasi searchRelPasien (List_R LR, adr_Pasien &pas);
adr_Relasi searchRelDokter (List_R LR, adr_Dokter &dok);

void printRelasi (List_R LR);

void delRelasi (List_R &LR, adr_Relasi &rel);
void delbyRelasi (List_R &LR, adr_Relasi &rel);

void sortRelasi (List_R &LR);

#endif // RELASI_H_INCLUDED
