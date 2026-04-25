#include <iostream>
using namespace std;

void titleASCII(){
    cout << R"(===============================================
__     _____   ____  __  __ __ __ _____   __ v2
||    ((   )) (( ___ ||\\|| || ||  ||    ((    
||__|  \\_//   \\_|| || \|| \\_//  ||   \_))   
===============================================)" << endl;
}

void mainMenu(){
    int pilihan;
    do {cout << R"(-----------------------------------------------
                    Main Menu
-----------------------------------------------
+++++++++++++++++++++++++++++++++++++++++++++++
        1. Booking Service
        2. Lihat Antrian
        3. Selesaikan Service
        0. Keluar
+++++++++++++++++++++++++++++++++++++++++++++++
    Pilihan : )"; cin >> pilihan; cout << "\n";
    switch (pilihan) {
        case 1:;
        case 2:;
        case 3:;
        default : cout << "Pilihan tidak valid! \n";
        }
    } while (pilihan != 0);
}