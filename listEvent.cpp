#include "listPengobatan.h"
#include "ListPengguna.h"


void createList(List_Pengobatan &L)
{
    first(L) = NULL;
}

address_Pengobatan alokasi(infotype_Pengobatan x, address_User U)
{
    address_Pengobatan P;

    P = new elmlist_Pengobatan;
    info(P) = x;
    next(P) = NULL;
    Pengguna(P)= U;

    return P;
}

void insertFirst(List_Pengobatan &L, address_Pengobatan P)
{
    if(first(L) == NULL)
        first(L)= P;
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(List_Pengobatan &L, address_Pengobatan Prec, address_Pengobatan P)
{
    address_Pengobatan Q =first(L);
    while (next(Q)!=NULL)
        Q=next(Q);
    if (Prec==Q)
        insertLast(L,P);
    else
    {
        next(P)=next(Prec);
        next(Prec)=P;
    }
}

void insertLast(List_Pengobatan &L, address_Pengobatan P)
{
    if(first(L)==NULL)
        first(L) = P;
    else if (next(first(L))==NULL)
        next(first(L))=P;
    else
    {
        address_Pengobatan Q =first(L);
        while (next(Q)!=NULL)
            Q=next(Q);
        next(Q)=P;
    }
}

address_Pengobatan findElmByID(List_Pengobatan L, int x)
{
    if (first(L)!=NULL)
    {
        address_Pengobatan P = first(L);
        while(P!=NULL )
        {
            if(info(P).id == x)
                return P;

            P = next(P);
        }
    }
    return NULL;
}

address_Pengobatan findElmByU(List_Pengobatan L, address_User x)
{
    if (first(L)!=NULL)
    {
        address_Pengobatan P = first(L);
        while(P!=NULL )
        {
            if(Pengguna(P) == x)
                return P;

            P = next(P);
        }
    }
    return NULL;
}

void inputDataBaru(List_Pengobatan &L, List_User Q)
{
    int y;
    infotype_Pengobatan x;
    cout<<"Masukan ID   : ";
    cin>>x.id;
    while(findElmByID(L,x.id)!=NULL)
    {
        cout<<"ID sudah ada"<<endl;
        cout<<"Masukan ID   : ";
        cin>>x.id;
    }
    cout << " | Nama penyakit    : ";
    cin >> x.namaPenyakit ;
    cout << " | Nama Rumah sakit : ";
    cin >> x.namaRumahSakit ;
    cout << " | Masukan detail   : ";
    cin >> x.detail;
    cout << " | id Pengguna      : ";
    cin >> y;
    while(findElmByIDU(Q,y)==NULL)
    {
        cout<<"ID tidak ditemukan"<<endl;
        cout<<"Masukan ID pengguna  : ";
        cin>>y;
    }
    address_User p = findElmByIDU(Q,y);
    cout<<" | masukan Biaya pengobatan : ";
    cin>>x.Biaya;
    if (info(p).tingkat == 1)
    {
        if (x.Biaya <= 10000000)
            x.pembayaran = 0;
        else
            x.pembayaran = x.Biaya - 10000000;
    }
    else if (info(p).tingkat == 2)
    {
        if (x.Biaya <= 5000000)
            x.pembayaran = 0;
        else
            x.pembayaran = x.Biaya - 5000000;
    }
    else if (info(p).tingkat == 3)
    {
        if (x.Biaya <= 2000000)
            x.pembayaran = 0;
        else
            x.pembayaran = x.Biaya - 2000000;
    }

    inputDataPengobatan(L,alokasi(x,p));
}

void deleteFirst(List_Pengobatan &L, address_Pengobatan &P)
{
    if (first(L)!=NULL)
    {
        P=first(L);
        if (next(P)==NULL)
            first(L)=NULL;
        else
        {
            first(L)=next(P);
            next(P)=NULL;
        }
    }
}

void deleteAfter(List_Pengobatan &L, address_Pengobatan Prec, address_Pengobatan &P)
{
    if (first(L)!=NULL)
    {
        if (next(next(Prec))== NULL)
            deleteLast(L,P);
        else
        {
            P=next(Prec);
            next(Prec)=next(P);
            next(P)=NULL;
        }
    }
}

void deleteLast(List_Pengobatan &L, address_Pengobatan &P)
{
    if (first(L)!=NULL)
    {
        P=first(L);
        if (next(P)==NULL)
            first(L)=NULL;
        else
        {
            while (next(next(P))!=NULL)
                P=next(P);
            next(P)=NULL;
        }
    }

}

void inputDataPengobatan(List_Pengobatan &L,address_Pengobatan x)
{
    if (first(L)==NULL || info(x).id <info(first(L)).id)
        insertFirst(L,x);
    else
    {
        address_Pengobatan Q = first(L);
        address_Pengobatan P = first(L);
        while (next(P)!=NULL)
            P=next(P);
        if (info(x).id>info(P).id)
            insertLast(L,x);
        else
        {
            while (Q!=P)
            {
                if ((info(Q).id<info(x).id) && ( info(next(Q)).id > info(x).id))
                    insertAfter(L,Q,x);
                else
                    Q=next(Q);
            }
        }
    }
}

void DeleteByID(List_Pengobatan &L)
{
    int x;
    cout<<"Masukan ID Yang ingin di Hapus : ";
    cin>>x;
    address_Pengobatan P,Q;
    while(findElmByID(L,x)==NULL)
    {
        cout<<"ID tidak ditemukan"<<endl;
        cout<<"Masukan ID Yang ingin di Hapus : ";
        cin>>x;
    }
    P=findElmByID(L,x);
    if (P==first(L))
        deleteFirst(L,P);
    else if(next(P)==NULL)
        deleteLast(L,P);
    else
    {
        Q = first(L);
        while (next(Q)!=P)
            Q=next(Q);
        deleteAfter(L,Q,P);
    }
}

void EditPengobatan(List_Pengobatan &L, List_User Q)
{
    int x,y;
    cout<<" masukan id yang ingin di edit : ";
    cin>>x;
    while(findElmByID(L,x)==NULL)
    {
        cout<<" data tidak ditemukan"<<endl;
        cout<<" masukan id yang ingin di edit : ";
        cin>>x;
    }
    address_Pengobatan U = findElmByID(L,x);
    cout<<" | Nama penyakit    : ";
    cin>>info(U).namaPenyakit;
    cout<<" | Nama Rumah sakit : ";
    cin>>info(U).namaRumahSakit;
    cout << " | Masukan detail   : ";
    cin >> info(U).detail;
    cout << " | id Pengguna      : ";
    cin >> y;
    while(findElmByIDU(Q,y)==NULL)
    {
        cout<<" ID tidak ditemukan"<<endl;
        cout<<" Masukan ID pengguna  : ";
        cin>>y;
    }
    address_User p = findElmByIDU(Q,y);
    cout<<" | masukan Biaya pengobatan : ";
    cin>>info(U).Biaya;
    if (info(p).tingkat == 1)
    {
        if (info(U).Biaya <= 10000000)
            info(U).pembayaran = 0;
        else
            info(U).pembayaran = info(U).Biaya - 10000000;
    }
    else if (info(p).tingkat == 2)
    {
        if (info(U).Biaya <= 5000000)
            info(U).pembayaran = 0;
        else
            info(U).pembayaran = info(U).Biaya - 5000000;
    }
    else if (info(p).tingkat == 3)
    {
        if (info(U).Biaya <= 2000000)
            info(U).pembayaran = 0;
        else
            info(U).pembayaran = info(U).Biaya - 2000000;
    }
}

void showDetail(address_Pengobatan P )
{
    cout<<" ||=============================================="<<endl;
    cout<<" || ID               : ";
    cout<<info(P).id<<endl;
    cout<<" || Pengguna         : ";
    cout<<info(Pengguna(P)).namaPeserta<<endl;
    cout<<" || Nama penyakit    : ";
    cout<<info(P).namaPenyakit<<endl;
    cout<<" || Nama Rumah sakit : ";
    cout<<info(P).namaRumahSakit<<endl;
    cout<<" || Biaya   : Rp";
    cout<<info(P).Biaya<<endl;
    cout<<" ||Biaya yang harus Dibayar : Rp ";
    cout<<info(P).pembayaran<<endl;
    cout<<" ||=============================================="<<endl<<endl;

}

void printInfoUser(List_User L, List_Pengobatan O)
{
    address_User P = first(L);
    if(first(L)!=NULL)
    {
        int x = 0;
        do
        {
            x++;
            cout<<"||==============================================||"<<endl;
            cout<<"  "<<x<<endl;
            cout<<"|| ID               : ";
            cout<<info(P).id<<endl;
            cout<<"|| Nama             : ";
            cout<<info(P).namaPeserta<<endl;
            cout<<"||==============================================||"<<endl<<endl;

            address_Pengobatan U = first(O);
            int y = 0;
            while (U!=NULL)
            {
                if (P == Pengguna(U))
                {
                    y++;
                    cout<<"    |--------------------------------------------|"<<endl;
                    cout<<"    "<< y <<endl;
                    cout<<"    | ID               : ";
                    cout<<info(U).id<<endl;
                    cout<<"    | Nama penyakit    : ";
                    cout<<info(U).namaPenyakit<<endl;
                    cout<<"    | Biaya : ";
                    cout<<info(U).pembayaran<<endl;
                    cout<<"    |--------------------------------------------|"<<endl<<endl;

                    U = next(U);
                }
                else U = next(U);
            }
            P = next(P);

        }
        while(P!=NULL);
    }
    else
        cout<<"data kosong"<<endl;
}

void sortbyclass (List_User U, List_Pengobatan O)
{
    address_User P = first(U);
    if (P!=NULL)
    {
        List_User G;
        address_User M;
        createList(G);
        while (P!=NULL)
        {
            M=alokasi(info(P));
            if (info(M).tingkat == 1)
                insertFirst(G,M);

            else if (info(M).tingkat == 3)
                insertLast(G,M);
            else
            {
                if (first(G)==NULL)
                    insertFirst(G,M);
                else
                {
                    address_User Q = first(G);
                    while (Q!=NULL)
                    {
                        if (info(first(G)).tingkat==3)

                            insertFirst(G,M);

                        else if (info(first(G)).tingkat==1 && next(first(G))==NULL)
                            insertLast(G,M);
                        else if (((info(Q).tingkat==1) && (info(next(Q)).tingkat==3))|| ((info(Q).tingkat==1) && (info(next(Q)).tingkat==2))|| ((info(Q).tingkat==1) && (next(Q)==NULL)))

                            insertAfter(G,Q,M);

                        Q=next(Q);
                    }
                }
            }
            P=next(P);
        }
        cout<<"masuk";

        printInfoUser(G,O);
    }
}

void DeleteByIDU(List_User &L, List_Pengobatan O)
{
    int x;
    cout<<"Masukan ID Yang ingin di Hapus : ";
    cin>>x;
    address_User P;
    while(findElmByIDU(L,x)==NULL)
    {
        cout<<"ID tidak ditemukan"<<endl;
        cout<<"Masukan ID Yang ingin di Hapus : ";
        cin>>x;
    }
    P=findElmByIDU(L,x);
    if (findElmByU(O,P)==NULL)
    {
        if (P==first(L))
        {
            deleteFirst(L,P);
        }
        else if(P==L.last)
        {
            deleteLast(L,P);
        }
        else
        {
            deleteAfter(L,prev(P),P);
        }
    }
    else
        cout<<"Data Pengguna BPJS tidak dapat dihapus karena masih memiliki Data Berobat (CHILD)"<<endl;

}

int jmlPengobatan (List_Pengobatan L)
{
    address_Pengobatan P = first(L);
    int x = 0;
    if(first(L)!=NULL)
    {
        while (P!=NULL)
        {
            x++;
            P=next(P);
        }
        return x;
    }

}

void penggunatersakit(List_User U, List_Pengobatan O)
{
    address_User Makss;
    address_User P = first(U);
    address_Pengobatan Q = first(O);
    int maks = 0;

    while (P!=NULL)
    {
        int coun = 0;
        while (Q!=NULL)
        {
            if (P==Pengguna(Q))
                coun++;
            Q=next(Q);
        }
        if (coun>maks)
        {
            maks=coun;
            Makss = P;
        }
        P=next(P);
    }

    cout<<"Pengguna yang sering sakit adalah "<< info(Makss).namaPeserta<<endl;
    cout<<"Dengan jumlah "<<maks<<" kali sakit"<<endl;
}

void Keuntungan(List_User U, List_Pengobatan O)
{
    address_Pengobatan Q = first(O);

    int counb = 0,counp = 0, sel=0,x;
    cout<<"Masukan id = ";
    cin>>x;
    while(findElmByIDU(U,x)==NULL)
    {
        cout<<" data tidak ditemukan"<<endl;
        cout<<" masukan id : ";
        cin>>x;
    }
    address_User k = findElmByIDU(U,x);


    while (Q!=NULL)
    {
        if (k==Pengguna(Q))
            {counb=counb+info(Q).Biaya;
        counp=counp+info(Q).pembayaran;}
        Q=next(Q);
    }
    sel = counb-counp;


    system("cls");
    cout<< info(k).namaPeserta<< " mendapatkan keuntungan Rp"<<sel<<endl;
    cout<<"  dengan biaya pengobatan Rp"<<counb<<"  dan yang harus "<<info(k).namaPeserta<<" bayar adalah sebesar Rp"<<counp<<endl;

}

void penggunaterSehat(List_User U, List_Pengobatan O)
{
    address_User P = first(U);
    address_Pengobatan Q = first(O);
    int x=0;
    while (next(P)!=NULL)
    {
        int coun = 0;
        address_Pengobatan Q = first(O);
        while (Q!=NULL)
        {
            if (P==Pengguna(Q))
                coun++;
            Q=next(Q);
        }
        if (coun==0)
        {
            x++;

            cout<<x<<". Pengguna yang paling sehat adalah "<< info(P).namaPeserta<<endl;
        }
        P=next(P);
    }
    if (x==0)
        cout <<"Tidak ada pengguna yang tidak pernah sakit :)"<<endl;

}

void buatDataP(List_Pengobatan &O, List_User U)
{
    infotype_Pengobatan E;
    address_User Q;
    Q= findElmByIDU(U,2);

    E.id= 2;
    E.namaPenyakit= "RHEUMATOID ARTHRITIS";
    E.Biaya=15000000;
    E.namaRumahSakit= "RS.Boromeus";
    E.detail= "Terapi dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 4;
    Q= findElmByIDU(U,2);
    E.namaPenyakit= "ASTHMA";
    E.Biaya=2000000;
    E.namaRumahSakit= "RS.Citra Indonesia";
    E.detail= "Terapi";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 8;
    Q= findElmByIDU(U,31);
    E.namaPenyakit= "Cancer";
    E.Biaya=70000000;
    E.namaRumahSakit= "RS.Sanjaya";
    E.detail= "Terapi dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 3;
    Q= findElmByIDU(U,21);
    E.namaPenyakit= "sclerosis";
    E.Biaya=11000000;
    E.namaRumahSakit= "RS.Santosa";
    E.detail= "Terapi dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 7;
    Q= findElmByIDU(U,12);
    E.namaPenyakit= "demam dan batuk";
    E.Biaya=1000000;
    E.namaRumahSakit= "RS.Santo Yusuf";
    E.detail= "pengecekan dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 6;
    Q= findElmByIDU(U,15);
    E.namaPenyakit= "TBC";
    E.Biaya=13000000;
    E.namaRumahSakit= "RS.Boromeus";
    E.detail= "perawatan dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 9;
    Q= findElmByIDU(U,28);
    E.namaPenyakit= "Tifus";
    E.Biaya=10000000;
    E.namaRumahSakit= "RS.Santosa";
    E.detail= "perawatan dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 14;
    Q= findElmByIDU(U,7);
    E.namaPenyakit= "muntaber";
    E.Biaya=2000000;
    E.namaRumahSakit= "RS.Maulana";
    E.detail= "pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 10;
    Q= findElmByIDU(U,9);
    E.namaPenyakit= "gagal ginjal";
    E.Biaya=11000000;
    E.namaRumahSakit= "RS.Boromeus";
    E.detail= "Operasi";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 21;
    Q= findElmByIDU(U,28);
    E.namaPenyakit= "DBD";
    E.Biaya=1000000;
    E.namaRumahSakit= "RS.Boromeus";
    E.detail= "pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 23;
    Q= findElmByIDU(U,21);

    E.namaPenyakit= "sclerosis";
    E.Biaya=11000000;
    E.namaRumahSakit= "RS.Santosa";
    E.detail= "Terapi dan pengobatan";

    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 19;
    Q= findElmByIDU(U,15);
    E.namaPenyakit= "Cacar";
    E.Biaya=11000000;
    E.namaRumahSakit= "RS.Santosa";
    E.detail= "Terapi dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 15;
    Q= findElmByIDU(U,9);
    E.namaPenyakit= "demam";
    E.Biaya=1000000;
    E.namaRumahSakit= "RS.Santosa";
    E.detail= "pengecekan dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

    E.id= 25;
    Q= findElmByIDU(U,7);
    E.namaPenyakit= "DBD";
    E.Biaya=16000000;
    E.namaRumahSakit= "RS.Surya";
    E.detail= "Terapi dan pengobatan";
    if (info(Q).tingkat == 1)
    {
        if (E.Biaya <= 10000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 10000000;
    }
    else if (info(Q).tingkat == 2)
    {
        if (E.Biaya <= 5000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 5000000;
    }
    else if (info(Q).tingkat == 3)
    {
        if (E.Biaya <= 2000000)
            E.pembayaran = 0;
        else
            E.pembayaran = E.Biaya - 2000000;
    }
    inputDataPengobatan(O,alokasi(E,Q));

}

void Perataan(List_Pengobatan E)
{
    int k1=0,k2=0,k3=0,jml1=0,jml2=0,jml3=0;
    address_Pengobatan P=first(E);
    while (P!= NULL)
    {
        if (info(Pengguna(P)).tingkat==1)
        {
            k1++;
            jml1=jml1+info(P).pembayaran;
        }
        else if (info(Pengguna(P)).tingkat==2)
        {
            k2++;
            jml2=jml2+info(P).pembayaran;
        }
        else if(info(Pengguna(P)).tingkat==3)
        {
            k3++;
            jml3=jml3+info(P).pembayaran;
        }
        P=next(P);
    }
    cout<<"biaya rata-rata kelas 1 adalah RP"<<jml1/k1<<endl;
    cout<<"biaya rata-rata kelas 2 adalah RP"<<jml2/k2<<endl;
    cout<<"biaya rata-rata kelas 3 adalah RP"<<jml3/k3<<endl;
}
