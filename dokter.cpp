#include "dokter.h"

void createDokter (List_D &LD){
    first(LD) = nil;
}

adr_Dokter alokasi_dokter (infotype_D dokter){
    adr_Dokter dok = new ElmDokter;
    info(dok) = dokter;
    next(dok) = nil;

    info(dok).id = dokter.id;
    info(dok).nama = dokter.nama;

    return dok;
}

void dealokasi (adr_Dokter &dok){
    delete(dok);
    dok = nil;
}

void inFirst_dokter (List_D &LD, adr_Dokter dok){
    adr_Dokter q;
    if (first(LD)==nil){
        first(LD) = dok;
        next(dok) = first(LD);
    }
    else{
        q = first(LD);
        while (next(q)!=first(LD)){
            q = next(q);
        }
        next(dok) = first(LD);
        next(q) = dok;
        first(LD) = dok;
    }
}

void inLast_dokter (List_D &LD, adr_Dokter dok){
    adr_Dokter q;
    if (first(LD)==nil)
        inFirst_dokter(LD,dok);
    else{
        q = first(LD);
        while (next(q)!=first(LD)){
            q = next(q);
        }
        next(q) = dok;
        next(dok) = first(LD);
    }
}

void inAfter_dokter (List_D &LD, adr_Dokter prec, adr_Dokter dok){
    if (prec==nil)
        cout<<"Prec tidak ditemukan"<<endl;
    else{
        if (first(LD)==nil)
            inFirst_dokter(LD,dok);
        else if (next(prec)==first(LD))
            inLast_dokter(LD,dok);
        else{
            next(dok) = next(prec);
            next(prec) = dok;
        }
    }
}

void delFirst_dokter (List_D &LD, adr_Dokter &dok){
    adr_Dokter q;
    if (first(LD)==nil)
        cout<<"List Dokter Kosong"<<endl;
    else if (next(first(LD))==first(LD))
        first(LD) = nil;
    else{
        q = first(LD);
        dok = first(LD);
        while (next(q)!=first(LD)){
            q = next(q);
        }
        next(q) = next(dok);
        first(LD) = next(dok);
        next(dok) = nil;
        dealokasi(dok);
    }
}

void delLast_dokter (List_D &LD, adr_Dokter &dok){
    adr_Dokter q;
    if (first(LD)==nil)
        cout<<"List Dokter Kosong"<<endl;
    else if (next(first(LD))==first(LD))
        delFirst_dokter(LD,dok);
    else{
        q = first(LD);
        dok = first(LD);
        while (next(q)!=first(LD)){
            dok = q;
            q = next(q);
        }
        next(dok) = first(LD);
        next(q) = nil;
        dealokasi(q);
    }
}

void delAfter_dokter (List_D &LD, adr_Dokter prec, adr_Dokter &dok){
    if (prec==nil)
        cout<<"Prec Dokter Tidak Ditemukan"<<endl;
    else{
        if (first(LD)==nil)
            cout<<"List Dokter Kosong"<<endl;
        else{
            dok = next(prec);
            if (prec==first(LD))
                delFirst_dokter(LD,dok);
            else if (next(dok)==first(LD))
                delLast_dokter(LD,dok);
            else{
                next(prec) = next(dok);
                next(dok) = nil;
                dealokasi(dok);
            }
        }
    }
}

adr_Dokter findDok (List_D LD, infotype_D dokter){
    adr_Dokter dok;
    if(first(LD)==nil)
        return nil;
    else{
        dok = first(LD);
        while(next(dok)!=first(LD) && info(dok).id!=dokter.id){
            dok = next(dok);
        }
        if(info(dok).id==dokter.id)
            return dok;
        else
            return nil;
    }
}

void printDokter (List_D LD){
    adr_Dokter dok;
    if (first(LD)==nil)
        cout<<"List Dokter Kosong"<<endl;
    else{
        dok = first(LD);
        do{
            cout<<"ID Dokter : "<<info(dok).id<<endl;
            cout<<"Nama      : "<<info(dok).nama<<endl;
            cout<<"------------"<<endl;
            dok = next(dok);
        }
        while (dok!=first(LD));
    }
    cout<<endl;
}

void inDokter (infotype_D *dokter){
    cout<<"ID Dokter : ";
    cin>>dokter->id;
    cout<<"Nama      : ";
    cin>>dokter->nama;
}

adr_Dokter delbyID_Dokter (List_D &LD, infotype_D dokter){
    adr_Dokter dok, dok2;
    dok = findDok(LD,dokter);
    if (dok==nil)
        return nil;
    else{
        if (dok==first(LD))
            delFirst_dokter(LD,dok);
        else if (next(dok)==nil)
            delLast_dokter(LD,dok);
        else{
            dok2 = first(LD);
            while (next(dok2)!=dok){
                dok2 = next(dok2);
            }
            delAfter_dokter(LD,dok2,dok);
        }
        return dok;
    }
}

void sortinsert_dokter (List_D &LD, infotype_D dokter){
    adr_Dokter dok,dok1,dok2;
    dok1 = findDok(LD,dokter);
    if (dok1==nil){
        dok2 = alokasi_dokter(dokter);
        if (first(LD)==nil)
            inFirst_dokter(LD,dok2);
        else{
            dok = first(LD);
            if (dokter.id > info(dok).id && dokter.id < info(next(dok)).id)
                inAfter_dokter(LD,dok,dok2);
            else if (dokter.id < info(dok).id)
                inFirst_dokter(LD,dok2);
            else{
                while (next(dok)!=first(LD) && info(next(dok)).id < dokter.id){
                    dok = next(dok);
                }
                if (next(dok)==first(LD))
                    inLast_dokter(LD,dok2);
                else
                    inAfter_dokter(LD,dok,dok2);
            }
        }
    }
    else
        cout<<"ID Sudah Digunakan"<<endl;
}

void printcurrent_dokter (List_D LD, infotype_D dokter){
    adr_Dokter dok;
    if (first(LD)==nil)
        cout<<"List Dokter Kosong"<<endl;
    else{
        dok = findDok(LD,dokter);
        if (dok==nil)
            cout<<"ID Tidak Ditemukan"<<endl;
        else{
            cout<<"ID Dokter : "<<info(dok).id<<endl;
            cout<<"Nama      : "<<info(dok).nama<<endl;
        }
    }
}
