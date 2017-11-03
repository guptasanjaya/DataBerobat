#include "menu.h"

    List_P LP;
    adr_Pasien pas = nil;
    adr_Pasien caripas;
    infotype_P infopas;

    List_D LD;
    adr_Dokter dok = nil;
    adr_Dokter caridok;
    infotype_D infodok;

    List_R LR;
    adr_Relasi rel = nil;

void menutama(){
    createPasien(LP);
    createDokter(LD);
    createRelasi(LR);
    int pil;

    do{
        cout<<"************* MENU *************"<<endl;
        cout<<"1. Insert Data Dokter"<<endl;
        cout<<"2. Insert Data Pasien"<<endl;
        cout<<"3. Lihat Daftar Dokter"<<endl;
        cout<<"4. Lihat Daftar Pasien"<<endl;
        cout<<"5. Pencarian Dokter"<<endl;
        cout<<"6. Pencarian Pasien"<<endl;
        cout<<"7. Relasikan Dokter <-> Pasien"<<endl;
        cout<<"8. Lihat Relasi"<<endl;
        cout<<"9. Pencarian Relasi"<<endl;
        cout<<"10. Putus Relasi"<<endl;
        cout<<"11. Hapus Data Dokter "<<endl;
        cout<<"12. Hapus Data Pasien"<<endl;
        cout<<"13. Sort Relasi"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"************* <<>> *************"<<endl;

        cout<<endl;

        cout<<"Pilihan Menu : ";
        cin>>pil;
        cout<<endl;
        switch(pil){
        case 1:
            insertDokter();
            break;
        case 2:
            insertPasien();
            break;
        case 3:
            viewDokter();
            break;
        case 4:
            viewPasien();
            break;
        case 5:
            find_Dokter();
            break;
        case 6:
            find_Pasien();
            break;
        case 7:
            relasi();
            break;
        case 8:
            viewRelasi();
            break;
        case 9:
            findRelasi();
            break;
        case 10:
            putusRelasi();
            break;
        case 11:
            delDokter();
            break;
        case 12:
            delPasien();
            break;
        case 13:
            sortRelasi(LR);
            printRelasi(LR);
            break;
        case 0:
            cout<<"Terima Kasih"<<endl;
            break;
        default:
            cout<<"Input Salah"<<endl;
            break;

        }
        cout<<"Tekan Enter Untuk Melanjutkan"<<endl;
        getche();
        system("cls");
    }
    while(pil!=0);
}

void insertDokter(){
    inDokter(&infodok);
    sortinsert_dokter(LD,infodok);
}

void viewDokter(){
    printDokter(LD);
}

void find_Dokter(){
    cout<<"Masukkan ID Dokter: "<<endl;
    cin>>infodok.id;
    printcurrent_dokter(LD,infodok);
}

void insertPasien(){
    inPasien(&infopas);
    sortinsert_pasien(LP,infopas);
}

void viewPasien(){
    printPasien(LP);
}

void find_Pasien(){
    cout<<"Masukkan No. Pasien: "<<endl;
    cin>>infopas.no_pasien;
    printcurrent_pasien(LP,infopas);
}

void relasi(){
    cout<<"** Merelasikan Dokter dengan Pasien **"<<endl;
    cout<<endl;
    cout<<"Masukkan ID Dokter  : ";
    cin>>infodok.id;
    cout<<"masukkan No. Pasien : ";
    cin>>infopas.no_pasien;
    caridok = findDok(LD,infodok);
    caripas = findPas(LP,infopas);
    if (caridok!=nil && caripas!=nil){
        rel = alokasi_relasi(caridok,caripas);
        inLast_relasi(LR,rel);
        cout<<"ID Dokter : "<<info(caridok).id<<" dengan No. Pasien : "<<info(caripas).no_pasien<<" berhasil direlasikan "<<endl;
    }
    else
        cout<<"ID Dokter/No. Pasien Tidak Ditemukan"<<endl;
}

void viewRelasi(){
    printRelasi(LR);
}

void findRelasi(){
    cout<<"Masukkan ID Dokter  : ";
    cin>>infodok.id;
    cout<<"Masukkan No. Pasien : ";
    cin>>infopas.no_pasien;
    caridok = findDok(LD,infodok);
    caripas = findPas(LP,infopas);
    if (caridok==nil && caripas==nil)
        cout<<"ID Dokter/Film Tidak Ditemukan"<<endl;
    else{
        rel = searchRel(LR,caridok,caripas);
        if (rel==nil)
            cout<<"ID Dokter : "<<info(caridok).id<<" dengan No. Pasien : "<<info(caripas).no_pasien<<" tidak berelasi."<<endl;
        else
            cout<<"ID Dokter : "<<info(caridok).id<<" dengan No. Pasien : "<<info(caripas).no_pasien<<" berelasi."<<endl;
    }
}

void putusRelasi(){
    cout<<"Masukkan ID Dokter  : ";
    cin>>infodok.id;
    cout<<"Masukkan No. Pasien : ";
    cin>>infopas.no_pasien;
    caridok = findDok(LD,infodok);
    caripas = findPas(LP,infopas);
    if (caridok==nil && caripas==nil)
        cout<<"ID Dokter/Film Tidak Ditemukan"<<endl;
    else{
        rel = searchRel(LR,caridok,caripas);
        if (rel==nil)
            cout<<"ID Dokter : "<<info(caridok).id<<" dengan No. Pasien : "<<info(caripas).no_pasien<<" tidak berelasi."<<endl;
        else{
            cout<<"ID Dokter : "<<info(caridok).id<<" dengan No. Pasien : "<<info(caripas).no_pasien<<" berelasi."<<endl;
            delbyRelasi(LR,rel);
            delRelasi(LR,rel);
            cout<<"Relasi Berhasil Dihapus"<<endl;
        }
    }
}

void delDokter(){
    cout<<"Masukkan ID Dokter"<<endl;
    cin>>infodok.id;
    caridok = delbyID_Dokter(LD,infodok);
    if (caridok==nil)
        cout<<"ID Tidak Ditemukan"<<endl;
    else{
        cout<<"Dokter dengan ID : "<<info(caridok).id<<" berhasil dihapus "<<endl;
        rel = searchRelDokter(LR,caridok);
        dealokasi(caridok);
        if (rel==nil)
            cout<<"List Tidak Berelasi"<<endl;
        else{
            delbyRelasi(LR,rel);
            delRelasi(LR,rel);
        }
    }
}

void delPasien(){
    cout<<"Masukkan No. Pasien"<<endl;
    cin>>infopas.no_pasien;
    caripas = delbynumber_Pasien(LP,infopas);
    if (caripas==nil)
        cout<<"Nomor Pasien Tidak Ditemukan"<<endl;
    else{
        cout<<"Pasien dengan nomor : "<<info(caripas).no_pasien<<" berhasil dihapus "<<endl;
        rel = searchRelPasien(LR,caripas);
        dealokasi(caripas);
        if (rel==nil)
            cout<<"List Tidak Berelasi"<<endl;
        else{
            delbyRelasi(LR,rel);
            delRelasi(LR,rel);
        }
    }
}
