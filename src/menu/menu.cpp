#include "../../include/data/service.h"
#include "../../include/data/globals.h"
#include "../../include/io/fileHandler.h"
#include "../../include/menu/menu.h"

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
        4. Ganti Tanggal Ambil
        0. Keluar
+++++++++++++++++++++++++++++++++++++++++++++++
    Pilihan : )"; cin >> pilihan; cout << "\n";
    switch (pilihan) {
        case 1: bookingMenu(); break;
        case 2: queueMenu(); break;
        case 3: finishService(); break;
        case 4: changeDate(); break;
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
    
    cout << R"(-----------------------------------------------
		      Selesaikan Servis
-----------------------------------------------)" << endl;
    chooseMechanic();
    int choice;
    

}

void changeDate(){
    cout << R"(-----------------------------------------------
		     Ganti Tanggal Ambil
-----------------------------------------------)" << endl;
}

void chooseMechanicUI(){
    cout << "\nPilih Montir:\n";
    for (int i = 0; i < mechanicCount; i++) {
        cout << (i + 1) << ". " << mechanics[i] << "\n";
    }
}