#include "pasien.h"

void createPasien (List_P &LP){
    first(LP) = nil;
    last(LP) = nil;
}

adr_Pasien alokasi_pasien (infotype_P pasien){
    adr_Pasien pas = new ElmPasien;
    info(pas) = pasien;
    next(pas) = nil;
    prev(pas) = nil;

    info(pas).nama = pasien.nama;
    info(pas).no_pasien = pasien.no_pasien;
    info(pas).gender = pasien.gender;

    return pas;
}

void dealokasi (adr_Pasien &pas){
    delete(pas);
    pas = nil;
}

void inFirst_pasien (List_P &LP, adr_Pasien pas){
    if (first(LP)==nil && last(LP)==nil){
        first(LP) = pas;
        last(LP) = pas;
        next(pas) = nil;
        prev(pas) = nil;
    }
    else{
        next(pas) = first(LP);
        prev(first(LP)) = pas;
        first(LP) = pas;
    }
}

void inLast_pasien (List_P &LP, adr_Pasien pas){
    if (first(LP)==nil && last(LP)==nil)
        inFirst_pasien(LP,pas);
    else{
        prev(pas) = last(LP);
        next(last(LP)) = pas;
        last(LP) = pas;
    }
}

void inAfter_pasien (List_P &LP, adr_Pasien prec, adr_Pasien pas){
    if (prec==nil)
        cout<<"Prec tidak ditemukan"<<endl;
    else{
        if (first(LP)==nil && last(LP)==nil)
            inFirst_pasien(LP,pas);
        else if (next(prec)==nil)
            inLast_pasien(LP,pas);
        else{
            next(pas) = next(prec);
            prev(pas) = prec;
            prev(next(pas)) = pas;
            next(prec) = pas;
        }
    }
}

void delFirst_pasien (List_P &LP, adr_Pasien &pas){
    if (first(LP)==nil && last(LP)==nil)
        cout<<"List Pasien Kosong"<<endl;
    else if (next(first(LP))==nil){
        first(LP) = nil;
        last(LP) = nil;
    }
    else{
        pas = first(LP);
        first(LP) = next(pas);
        next(pas) = nil;
        prev(pas) = nil;
        dealokasi(pas);
    }
}

void delLast_pasien (List_P &LP, adr_Pasien &pas){
    if (first(LP)==nil && last(LP)==nil)
        cout<<"List Pasien Kosong"<<endl;
    else if (first(LP)==last(LP))
        delFirst_pasien(LP,pas);
    else{
        pas = last(LP);
        last(LP) = prev(pas);
        prev(pas) = nil;
        next(last(LP)) = nil;
        dealokasi(pas);
    }
}

void delAfter_pasien (List_P &LP, adr_Pasien prec, adr_Pasien &pas){
    if (prec==nil)
        cout<<"Prec Tidak Ditemukan"<<endl;
    else{
        if (first(LP)==nil && last(LP)==nil)
            cout<<"List Pasien Kosong"<<endl;
        else{
            pas = next(prec);
            if (prec == first(LP))
                delFirst_pasien(LP,pas);
            else if (next(pas)==last(LP)){
                delLast_pasien(LP,pas);
            }
            else
                next(prec) = next(pas);
                prev(next(pas)) = prec;
                next(pas) = nil;
                prev(pas) = nil;
                dealokasi(pas);
        }
    }
}

adr_Pasien findPas (List_P LP, infotype_P pasien){
    adr_Pasien pas;
    if (first(LP)==nil)
        return nil;
    else{
        pas = first(LP);
        while (next(pas)!=nil && info(pas).no_pasien!=pasien.no_pasien){
            pas = next(pas);
        }
        if (info(pas).no_pasien==pasien.no_pasien)
            return pas;
        else
            return nil;
    }
}

void printPasien (List_P LP){
    adr_Pasien pas = first(LP);
    if (first(LP)==nil)
        cout<<"List Kosong"<<endl;
    else{
        pas = first(LP);
        do{
            cout<<"No. Pasien    : "<<info(pas).no_pasien<<endl;
            cout<<"Nama          : "<<info(pas).nama<<endl;
            cout<<"Jenis Kelamin : "<<info(pas).gender<<endl;
            cout<<"----------------"<<endl;
            pas = next(pas);
        }
        while (pas!=nil);
    }
    cout<<endl;
}

void inPasien (infotype_P *pasien){
    cout<<"No. Pasien    : ";
    cin>>pasien->no_pasien;
    cout<<"Nama          : ";
    cin>>pasien->nama;
    cout<<"Jenis Kelamin : ";
    cin>>pasien->gender;
}

adr_Pasien delbynumber_Pasien (List_P &LP, infotype_P pasien){
    adr_Pasien pas, pas2;
    pas = findPas(LP,pasien);
    if (pas==nil)
        return nil;
    else{
        if (pas==first(LP))
            delFirst_pasien(LP,pas);
        else if (pas==last(LP))
            delLast_pasien(LP,pas);
        else{
            pas2 = prev(pas);
            delAfter_pasien(LP,pas2,pas);
        }
        return pas;
    }
}

void sortinsert_pasien (List_P &LP, infotype_P pasien){
    adr_Pasien pas,pas1,pas2;
    pas1 = findPas(LP,pasien);
    if (pas1==nil){
        pas2 = alokasi_pasien(pasien);
        if (first(LP)==nil)
            inFirst_pasien(LP,pas2);
        else{
            pas = first(LP);
            if (pasien.no_pasien < info(pas).no_pasien && pasien.no_pasien > info(next(pas)).no_pasien)
                inAfter_pasien(LP,pas,pas2);
            else if (pasien.no_pasien < info(pas).no_pasien)
                inFirst_pasien(LP,pas2);
            else{
                while (next(pas)!=nil && info(next(pas)).no_pasien < pasien.no_pasien){
                    pas = next(pas);
                }
                if (next(pas)==nil)
                    inLast_pasien(LP,pas2);
                else
                    inAfter_pasien(LP,pas,pas2);
            }
        }
    }
    else
        cout<<"No Pasien Sudah Digunakan"<<endl;
}

void printcurrent_pasien (List_P LP, infotype_P pasien){
    adr_Pasien pas;
    if (first(LP)==nil)
        cout<<"List Pasien Kosong"<<endl;
    else{
        pas = findPas(LP,pasien);
        if (pas==nil)
            cout<<"No. Pasien Tidak Ditemukan"<<endl;
        else{
        cout<<"No. Pasien    : "<<info(pas).no_pasien<<endl;
        cout<<"Nama          : "<<info(pas).nama<<endl;
        cout<<"Jenis Kelamin : "<<info(pas).gender<<endl;
        }
    }
}
