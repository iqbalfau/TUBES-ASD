#include <iostream>
#include "listPengguna.h"
#include "listPengobatan.h"
using namespace std;
int main()
{
    List_User U;
    List_Pengobatan E;
    createList(U);
    createList(E);
    buatdata(U);
    buatDataP(E,U);
    MainMenu(U,E);
}
