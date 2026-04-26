#include "../../include/data/service.h"
#include <iostream>
using namespace std;

// Forward declarations
void bookingMenu();
void bookingServis();
void queueMenu();
void finishService();

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
        case 1: bookingMenu(); break;
        case 2: queueMenu(); break;
        case 3: finishService(); break;
        case 0: return;
        default : cout << "Pilihan tidak valid! \n";
        }
    } while (pilihan != 0);
}

void bookingMenu() {
    cout << R"(-----------------------------------------------
                Booking Servis
-----------------------------------------------)" << endl;
    bookingServis();
}

void queueMenu(){
    char choose;
    cout << R"(-----------------------------------------------
		           Antrian
-----------------------------------------------)" << endl;

    cout << "Sort by : " << endl;
    cout << "[D]ate [U]rgency [Q}ueue [E]xit" << endl;
    cout << "Option : " ; cin >> choose;
}

void finishService() {
    // TODO: Implement finish service logic
    cout << "Finish Service - Coming Soon!\n";
}

