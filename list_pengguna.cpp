#include "listPengguna.h"

void createList(List_User &L)
{
    first(L) = NULL;
    L.last = NULL;
}

address_User alokasi(infotype_User x)
{
    address_User P;

    P = new elmlist_User;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void insertFirst(List_User &L, address_User P)
{
    if(first(L) == NULL)
    {
        first(L)= P;
        L.last = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L))=P;
        first(L) = P;
    }
}

void insertAfter(List_User &L, address_User Prec, address_User P)
{

    if (Prec==L.last)
    {
        insertLast(L,P);
    }
    else
    {
        next(P)=next(Prec);
        prev(P)=Prec;

        prev(next(Prec))=P;
        next(Prec)=P;
    }
}

void insertLast(List_User &L, address_User P)
{
    if(first(L)==NULL)
    {
        first(L) = P;
        L.last = P;
    }
    else if (L.last==first(L))
    {
        prev(P)=first(L);
        next(first(L))=P;
        L.last=P;
    }
    else
    {
        prev(P)= L.last;
        next(L.last)=P;
        L.last=P;
    }
}

address_User findElmByIDU(List_User L, int x)
{
    if (first(L)!=NULL)
    {
        address_User P = first(L);
        while(P!=NULL )
        {
            if(info(P).id == x)
                return P;
            P = next(P);
        }
    }
    return NULL;
}

void inputDataBaru(List_User &L)
{
    infotype_User x;
    cout<<"Masukan ID   : ";
    cin>>x.id;
    while(findElmByIDU(L,x.id)!=NULL)
    {
        cout<<"ID sudah ada"<<endl;
        cout<<"Masukan ID   : ";
        cin>>x.id;
    }
    cout << "Nama    : ";
    cin >> x.namaPeserta;
    cout << "Tempat/Tgl Lahir : ";
    cin >> x.TTL;
    cout << "Kelas  : ";
    cin >> x.tingkat;
    cout << "alamat : ";
    cin >> x.alamat;
    cout << "No HP  : ";
    cin >> x.NoHP;
    inputDataUser(L,alokasi(x));
    cout<<"Data telah di masukan"<<endl;

}

void buatdata(List_User &L)
{

    infotype_User x;

    x.id=2;//1
    x.namaPeserta="Panu";
    x.TTL="Jakarta, 12 Februari 1990";
    x.tingkat=1;
    x.alamat= "Jl. Anggrek no.20,Jakarta";
    x.NoHP = "087523123412";
    inputDataUser(L,alokasi(x));

    x.id=21;
    x.namaPeserta="Tyo";
    x.TTL="Jakarta, 2 Februari 1952";
    x.tingkat=1;//2
    x.alamat= "jl. Mangga no.12,Jakarta";
    x.NoHP = "089212453121";
    inputDataUser(L,alokasi(x));

    x.id=31;//3
    x.namaPeserta="rio";
    x.TTL="Bekasi, 16 September 1961";
    x.tingkat=1;
    x.alamat= "jl. kalijati no.123,Bekasi";
    x.NoHP = "085483948082";
    inputDataUser(L,alokasi(x));

    x.id=12;//4
    x.namaPeserta="Yono";
    x.TTL="Surakarta, 12 Oktober 1972";
    x.tingkat=2;
    x.alamat= "jl. manggis no.87,Surakarta";
    x.NoHP = "085643920487";
    inputDataUser(L,alokasi(x));

    x.id=15;//5
    x.namaPeserta="Chris";
    x.TTL="Bandung, 13 Juni 1988";
    x.tingkat=2;
    x.alamat= "jl. malaka no. 79,Bandung";
    x.NoHP = "089763543213";
    inputDataUser(L,alokasi(x));

    x.id=28;//6
    x.namaPeserta="Asep";
    x.TTL="Bandung, 6 Mei 1990";
    x.tingkat=2;
    x.alamat= "jl. riung no. 23,Bandung";
    x.NoHP = "087564839294";
    inputDataUser(L,alokasi(x));

    x.id=7;//7
    x.namaPeserta="Tri";
    x.TTL="Surabaya, 27 juli 1989";
    x.tingkat=3;
    x.alamat= "jl. kaliki no. 177,Surabaya";
    x.NoHP = "086724214587";
    inputDataUser(L,alokasi(x));

    x.id=9;//8
    x.namaPeserta="Stevani";
    x.TTL="Surabaya, 30 Desember 1991";
    x.tingkat=3;
    x.alamat= "jl. kalibi no.199,Surabaya";
    x.NoHP = "089765432142";
    inputDataUser(L,alokasi(x));

    x.id=30;//9
    x.namaPeserta="Trisha";
    x.TTL="Jakarta, 23 Juli 1986";
    x.tingkat=3;
    x.alamat= "Jl. Mangga dua no,207,Jakarta";
    x.NoHP = "085632412431";
    inputDataUser(L,alokasi(x));
}

void deleteFirst(List_User &L, address_User &P)
{
    if (first(L)!=NULL)
    {
        P=first(L);
        if (next(P)==NULL)
        {
            first(L)=NULL;
            L.last=NULL;
        }
        else
        {
            first(L)=next(P);
            next(P)=NULL;
            prev(first(L))=NULL;
        }
    }
}

void deleteLast(List_User &L, address_User &P)
{
    if (first(L)!=NULL)
    {
        P=L.last;
        if (first(L)==L.last)
        {
            first(L)=NULL;
            L.last=NULL;
        }
        else
        {
            L.last=prev(P);
            next(L.last)=NULL;
            prev(P)=NULL;
        }
    }

}

void deleteAfter(List_User &L, address_User Prec, address_User &P)
{
    if (first(L)!=NULL)
    {
        if (next(Prec)==L.last)
        {
            deleteLast(L,P);
        }
        else
        {
            P=next(Prec);
            next(Prec)=next(P);
            prev(next(P))=Prec;
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

void inputDataUser(List_User &L, address_User x)
{

    address_User Q = first(L);
    if (first(L)==NULL || info(x).id < info(first(L)).id)
    {
        insertFirst(L,x);

    }
    else if (info(x).id>info(L.last).id)
    {
        insertLast(L,x);
    }
    else
    {
        while (Q!=L.last)
        {
            if ((info(Q).id<info(x).id) && ( info(next(Q)).id > info(x).id))
            {
                insertAfter(L,Q,x);
            }
            else
            {
                Q=next(Q);
            }
        }
    }
}

void EditUser(List_User &L)
{
    int x;
    cout<<"masukan id yang ingin di edit : ";
    cin>>x;
    while(findElmByIDU(L,x)==NULL)
    {
        cout<<"data tidak ditemukan"<<endl;
        cout<<"masukan id yang ingin di edit : ";
        cin>>x;
    }
    address_User y = findElmByIDU(L,x);
    cout << "Nama    : ";
    cin >> info(y).namaPeserta;
    cout << "Tempat/Tgl Lahir : ";
    cin >> info(y).TTL;
    cout << "Kelas  : ";
    cin >> info(y).tingkat;
    cout << "alamat : ";
    cin >> info(y).alamat;
    cout << "No HP  : ";
    cin >> info(y).NoHP;
}


void showDetail(address_User U)
{



    cout<<"||=============================================="<<endl;

    cout<<"|| ID               : ";
    cout<<info(U).id<<endl;
    cout<<"|| Nama             : ";
    cout<<info(U).namaPeserta<<endl;
    cout<<"|| Tempat/Tgl Lahir : ";
    cout<<info(U).TTL<<endl;
    cout<<"|| Kelas            : ";
    cout<<info(U).tingkat<<endl;
    cout<<"|| alamat           : ";
    cout<<info(U).alamat<<endl;
    cout<<"||=============================================="<<endl<<endl;

}
int jmlUser (List_User L)
{
    address_User P = first(L);
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
