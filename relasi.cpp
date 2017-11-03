#include "relasi.h"

void createRelasi(List_R LR){
    first(LR) = nil;
}

adr_Relasi alokasi_relasi (adr_Dokter dok, adr_Pasien pas){
    adr_Relasi rel = new ElmRelasi;
    next(rel) = nil;
    nexdok(rel) = dok;
    nexpas(rel) = pas;
    return rel;
}

void dealokasi (adr_Relasi &rel){
    delete rel;
    rel = nil;
}

void inFirst_relasi (List_R &LR, adr_Relasi rel){
    if (first(LR)==nil){
        first(LR) = rel;
    }
    else{
        next(rel) = first(LR);
        first(LR) = rel;
    }
}

void inLast_relasi (List_R &LR, adr_Relasi rel){
    if (first(LR)==nil)
        inFirst_relasi(LR,rel);
    else{
        adr_Relasi q = first(LR);
        while (next(q)!=nil){
            q = next(q);
        }
        next(q) = rel;
    }
}

void inAfter_relasi (List_R &LR, adr_Relasi prec, adr_Relasi rel){
    if (prec==nil)
        cout<<"Prec tidak ditemukan"<<endl;
    else{
        if (first(LR)==nil)
            inFirst_relasi(LR,rel);
        else if (next(prec)==nil)
            inLast_relasi(LR,rel);
        else{
            next(rel) = next(prec);
            next(prec) = rel;
        }
    }
}

void delFirst_relasi (List_R &LR, adr_Relasi &rel){
    if (first(LR)==nil)
        cout<<"List Relasi Kosong"<<endl;
    else if (next(first(LR))==nil)
        first(LR) = nil;
    else{
        rel = first(LR);
        first(LR) = next(rel);
        next(rel) = nil;
        dealokasi(rel);
    }
}

void delLast_relasi (List_R &LR, adr_Relasi &rel){
    adr_Relasi q;
    if (first(LR)==nil)
        cout<<"List Relasi Kosong"<<endl;
    else if (next(first(LR))==nil)
        delFirst_relasi(LR,rel);
    else{
        q = first(LR);
        while (next(q)!=nil){
            rel = q;
            q = next(q);
        }
        next(q) = nil;
        dealokasi(q);
    }
}

void delAfter_relasi (List_R &LR, adr_Relasi prec, adr_Relasi &rel){
    if (prec==nil)
        cout<<"Prec Relasi Tidak Ditemukan"<<endl;
    else{
        if (first(LR)==nil)
            cout<<"List Relasi Kosong"<<endl;
        else{
            rel = next(prec);
            if (prec==first(LR))
                delFirst_relasi(LR,rel);
            else if (next(rel)==nil)
                delLast_relasi(LR,rel);
            else{
                next(prec) = next(rel);
                next(rel) = nil;
                dealokasi(rel);
            }
        }
    }
}

adr_Relasi searchRel (List_R LR, adr_Dokter dok, adr_Pasien pas){
    adr_Relasi rel;
    if (first(LR)==nil)
        return nil;
    else{
        rel = first(LR);
        while (next(rel)!=nil){
            if (nexdok(rel)!=dok && nexpas(rel)!=pas)
                rel = next(rel);
        }
        if (nexdok(rel)==dok && nexpas(rel)==pas)
            return rel;
        else
            return nil;
    }
}

adr_Relasi searchRelPasien (List_R LR, adr_Pasien &pas){
    adr_Relasi rel;
    if (first(LR)==nil)
        return nil;
    else{
        rel = first(LR);
        while (next(rel)!=nil && nexpas(rel)!=pas){
            rel = next(rel);
        }
        if (nexpas(rel)==pas)
            return rel;
        else
            return nil;
    }
}

adr_Relasi searchRelDokter (List_R LR, adr_Dokter &dok){
    adr_Relasi rel;
    if (first(LR)==nil)
        return nil;
    else{
        rel = first(LR);
        while (next(rel)!=nil && nexdok(rel)!=dok){
            rel = next(rel);
        }
        if (nexdok(rel)==dok)
            return rel;
        else
            return nil;
    }
}

void printRelasi (List_R LR){
    adr_Relasi rel = first(LR);
    if (first(LR)==nil)
        cout<<"List Relasi Kosong"<<endl;
    else{
        rel = first(LR);
        while (rel!=nil){
            cout<<"ID Dokter       : "<<info(nexdok(rel)).id<<endl;
            cout<<"Nama            : "<<info(nexdok(rel)).nama<<endl;
            cout<<"<<---Berelasi--->>"<<endl;
            cout<<"No. Pasien      : "<<info(nexpas(rel)).no_pasien<<endl;
            cout<<"Nama            : "<<info(nexpas(rel)).nama<<endl;
            cout<<"Jenis Kelamin   : "<<info(nexpas(rel)).gender<<endl;
            cout<<endl;
            rel = next(rel);
        }
    }
}

void delRelasi (List_R &LR, adr_Relasi &rel){
    nexdok(rel) = nil;
    nexpas(rel) = nil;
    dealokasi(rel);
}

void delbyRelasi (List_R &LR, adr_Relasi &rel){
    adr_Relasi q;
    if (first(LR)==nil)
        cout<<"List Relasi Kosong"<<endl;
    else{
        if (rel==first(LR))
            delFirst_relasi(LR,rel);
        else{
            q = first(LR);
            while (next(q)!=rel){
                q = next(q);
            }
        }
        if (next(q)==rel && next(rel)==nil)
            delLast_relasi(LR,rel);
        else{
            delAfter_relasi(LR,q,rel);
        }
    }
}

void sortRelasi(List_R &LR){
    adr_Relasi rel, rel2;
    if (first(LR)==nil)
        cout<<"List Relasi Kosong"<<endl;
    else{
        rel = first(LR);
        while (next(rel)!=nil){
            if (info(nexdok(rel)).id > info(next(nexdok(rel))).id){
                rel2 = first(LR);
                while (next(rel2)!=rel){
                    rel2 = next(rel2);
                }
                delAfter_relasi(LR,rel2,rel);
                inAfter_relasi(LR,next(rel),rel);
            }
            rel = next(rel);
        }
    }
}
