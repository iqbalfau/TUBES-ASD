#ifndef LISTPENGOBATAN_H_INCLUDED
#define LISTPENGOBATAN_H_INCLUDED
#include "listPengguna.h"
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define Pengguna(P) P->Pengguna

using namespace std;

typedef struct elmlist_Pengobatan *address_Pengobatan;
struct infotype_Pengobatan
{
    int id;
    string namaPenyakit;
    string namaRumahSakit;
    string detail;
    int Biaya;
    int pembayaran;


};
struct elmlist_Pengobatan
{
    infotype_Pengobatan info;
    address_Pengobatan next;
    address_User Pengguna;
};

struct List_Pengobatan
{
    address_Pengobatan first;
};

void createList(List_Pengobatan &L);//1

void insertFirst(List_Pengobatan &L, address_Pengobatan P);//1
void insertAfter(List_Pengobatan &L, address_Pengobatan Prec, address_Pengobatan P);
void insertLast(List_Pengobatan &L, address_Pengobatan P);

void deleteFirst(List_Pengobatan &L, address_Pengobatan &P);
void deleteAfter(List_Pengobatan &L, address_Pengobatan Prec, address_Pengobatan &P);
void deleteLast(List_Pengobatan &L, address_Pengobatan &P);

address_Pengobatan alokasi(infotype_Pengobatan x, address_User U);//1
void dealokasi(address_Pengobatan &P);

address_Pengobatan findElmByID(List_Pengobatan L, int x);//1

void inputDataPengobatan(List_Pengobatan &L,address_Pengobatan x);
void inputDataBaru(List_Pengobatan &L, List_User Q) ;

void DeleteByID(List_Pengobatan &L);
void EditPengobatan(List_Pengobatan &L, List_User Q);
void showDetail(address_Pengobatan U);
void printInfoPengobatan(List_Pengobatan L, List_User Q);//1
void MainMenu(List_User &U, List_Pengobatan &E);
void printInfoUser(List_User L, List_Pengobatan P);
void sortbyclass (List_User U, List_Pengobatan O);
int jmlPengobatan (List_Pengobatan L);
void penggunatersakit(List_User U, List_Pengobatan O);
void penggunaterSehat(List_User U, List_Pengobatan O);
void DeleteByIDU(List_User &L, List_Pengobatan O);
void buatDataP(List_Pengobatan &O, List_User U);
void Perataan(List_Pengobatan E);
void Keuntungan(List_User U, List_Pengobatan O);
#endif // LISTPENGOBATAN_H_INCLUDED
