#ifndef LISTPENGGUNA_H_INCLUDED
#define LISTPENGGUNA_H_INCLUDED
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
//#define last(L) L.last

using namespace std;

typedef struct elmlist_User *address_User;
struct infotype_User
{
    int id;
    string namaPeserta;
    string TTL;
    int tingkat;
    string alamat;
    string NoHP;
};

struct elmlist_User
{
    infotype_User info;
    address_User next;
    address_User prev;
};

struct List_User
{
    address_User first;
    address_User last;
};

void createList(List_User &L);//1
void insertFirst(List_User &L, address_User P);//1
void insertAfter(List_User &L, address_User Prec, address_User P);
void insertLast(List_User &L, address_User P);
void deleteFirst(List_User &L, address_User &P);
void deleteLast(List_User &L, address_User &P);
void deleteAfter(List_User &L, address_User Prec, address_User &P);
address_User alokasi(infotype_User x);//1
void dealokasi(address_User &P);
address_User findElmByIDU(List_User L, int x);//1
//1
void inputDataUser(List_User &L,address_User x);
void inputDataBaru(List_User &L);
void EditUser(List_User &L);
int jmlUser (List_User L);


void showDetail(address_User U);
void buatdata(List_User &L);

#endif // LISTPENGGUNA_H_INCLUDED
