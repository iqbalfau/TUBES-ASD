#include "listPengguna.h"
#include "listPengobatan.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void MainMenu(List_User &U, List_Pengobatan &E)
{

    system("cls");
    int choice2;
    int Content;
    int choice;
    cout<<" ==============================="<<endl;
    cout<<"||             Menu           ||" <<endl;
    cout<<" ==============================="<<endl;
    cout<<" 1.Insert data"<<endl;
    cout<<" 2.Search and view"<<endl;
    cout<<" 3.Search and delete"<<endl;
    cout<<" 4.View all"<<endl;
    cout<<" 5.Reporting"<<endl;
    cout<<" 6.Search and edit"<<endl;
    cout<<" 7.Sort"<<endl;
    cout<<" 8.Exit"<<endl;
    cout<<" ==============================="<<endl;
    cout<<"   Pilihan : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        system("cls");
        cout<<" 1.Input Data BPJS"<<endl;
        cout<<" 2.Input Data Berobat"<<endl;
        cout<<" 3.Back to Main Menu"<<endl;
        cout<<"   Pilihan : ";
        cin>>choice2;
        switch(choice2)
        {
            system("cls");
        case 1:
            inputDataBaru(U);
            cout<<" DATA HAS BEEN SAVED";
            system("pause");
            MainMenu(U,E);
            break;
        case 2:
            inputDataBaru(E,U);
            cout<<" DATA HAS BEEN SAVED";
            system("pause");
            MainMenu(U,E);
            break;

        case 3:
            MainMenu(U,E);
            break;
        }

    case 2:
        system("cls");
        cout<<" 1.View data BPJS"<<endl;
        cout<<" 2.View data Berobat"<<endl;
        cout<<" 3.Back to Main Menu"<<endl;
        cout<<"   Pilihan : ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
        {
            system("cls");
            cout<<" Masukkan id BPJS : ";
            cin>> Content;
            while(findElmByIDU(U,Content)==NULL)
            {
                cout<<" ID tidak ditemukan"<<endl;
                cout<<" masukan id yang ingin di lihat :   ";
                cin>>Content;
            }
            showDetail(findElmByIDU(U,Content));
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 2:
        {
            system("cls");
            cout<<" Masukkan id Berobat : ";
            cin>>Content;
            while(findElmByID(E,Content)==NULL)
            {
                cout<<" ID tidak ditemukan"<<endl;
                cout<<" masukan id yang ingin di lihat : ";
                cin>>Content;
            }
            showDetail(findElmByID(E,Content));
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 3:
            MainMenu(U,E);
            break;
        }
        break;
    case 3:
        system("cls");
        cout<<" 1.Delete data BPJS"<<endl;
        cout<<" 2.Delete data Berobat"<<endl;
        cout<<" 3.Back to Main Menu"<<endl;
        cout<<"   Pilihan : ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
        {
            system("cls");
            DeleteByIDU(U,E);
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 2:
        {
            system("cls");
            DeleteByID(E);
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 3:
            MainMenu(U,E);
            break;
        }
        break;
    case 4:
        // Fungsi view ALL
        printInfoUser(U,E);
        system("pause");
        MainMenu(U,E);
        break;
    case 5:
        system("cls");
        cout<<" 1.Jumlah Pengguna BPJS"<<endl;
        cout<<" 2.Jumlah Data Berobat"<<endl;
        cout<<" 3.Pengguna yang sering sakit"<<endl;
        cout<<" 4.Pengguna yang Sehat"<<endl;
        cout<<" 5.Rata-rata per kelas"<<endl;
        cout<<" 6.Keuntungan Pengguna BPJS"<<endl;
        cout<<" 7.Back to Main Menu"<<endl;

        cout<<"   Pilihan : ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
        {
            system("cls");
            cout<< "Jumlah Pengguna BPJS sekarang adalah "<<jmlUser(U)<<endl;
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 2:
        {
            system("cls");
            cout<< "Jumlah Data Pengobatan sekarang adalah "<<jmlPengobatan(E)<<endl;
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 3:
        {
            penggunatersakit(U,E);
            system("pause");

            MainMenu(U,E);
            break;
        }
        case 4:
        {
            penggunaterSehat(U,E);
            system("pause");
            MainMenu(U,E);
            break;
        }
        case 5:
        {
            system("cls");
            Perataan(E);
            system("pause");
            MainMenu(U,E);
            break;
        }
        case 6:
        {
            system("cls");
            Keuntungan(U,E);
            system("pause");
            MainMenu(U,E);
            break;
        }
        case 7:
        {
            system("cls");
            MainMenu(U,E);
            break;
        }
        default:
            cout<<"Input Salah"<<endl;
            MainMenu(U,E);
        break;
        }
    case 6:
        system("cls");
        cout<<" 1.Edit data BPJS"<<endl;
        cout<<" 2.Edit data Berobat"<<endl;
        cout<<" 3.Back to Main Menu"<<endl;
        cout<<"   Pilihan : ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
        {
            system("cls");
            EditUser(U);
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 2:
        {
            system("cls");
            EditPengobatan(E,U);
            system("pause");
            MainMenu(U,E);
            break;
        }

        case 3:
            MainMenu(U,E);
            break;
        }
        break;
    case 7:
        //fungsi sort;
    {
        sortbyclass(U,E);
        system("pause");
        MainMenu(U,E);
        break;
    }
    case 8:
    {
        system("cls");
        cout << "  Terima Kasih ";
        Sleep(1500);
        system("cls");
        cout << "       Terima Kasih ";
        Sleep(1500);
        system("cls");
        cout << "             Terima Kasih ";
        Sleep(1500);
        system("cls");
        cout << "                 Terima Kasih ";
        Sleep(1500);
        system("cls");
        cout << "  Dibuat Oleh ";
        Sleep(1500);
        system("cls");
        cout << "              Iqbal Fauzi ";
        Sleep(1500);
        system("cls");
        cout << "                            & ";
        Sleep(1500);
        system("cls");
        cout << "                                 Raden Rizky Falih";
        Sleep(1500);
        system("cls");
        cout <<"                 Terima Kasih"<<endl;
        cout<< "  Dibuat oleh Iqbal Fauzi dan Raden Rizky Falih";
        break;
    }
    default:
        cout<<" Input yang anda masukan salah";
        system("pause");
        system("cls");
        MainMenu(U,E);
        break;
    }
}
