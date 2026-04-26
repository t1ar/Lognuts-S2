#include "../../include/data/service.h"
#include "../../include/data/globals.h"
#include "../../include/io/fileHandler.h"
#include "../../include/menu/menu.h"

using namespace std;

Service* headQueue = nullptr;
Service* headDone = nullptr;

int getValidPriority() {
    int priority;
    while (true) {
        cout << "Kepentingan (1-4): ";
        cin >> priority;
        
        if (!isValidInt(priority)) continue;
        
        if (priority >= 1 && priority <= 4) {
            cin.ignore(10000, '\n');  // Clear remaining input
            return priority;
        } else {
            cout << "Error: Hanya input 1, 2, 3, atau 4!\n";
        }
    }
}

string selectMechanic() {
    loadMechanics();
    
    chooseMechanicUI();
    
    int choice;
    while (true) {
        cout << "Masukkan nomor (1-" << mechanicCount << "): ";
        cin >> choice;
        
        if (!isValidInt(choice)) continue;
        
        if (choice >= 1 && choice <= mechanicCount) {
            cin.ignore(10000, '\n');
            return mechanics[choice - 1];
        } else {
            cout << "Error: Pilihan tidak valid!\n";
        }
    }
}

void swapServiceData(Service* a, Service* b) {
    // save the next pointer first
    Service* tempNextA = a->next;
    Service* tempNextB = b->next;

    Service temp = *a;
    *a = *b;
    *b = temp;

    // restore the pointer to avoid corruption
    a->next = tempNextA;
    b->next = tempNextB;
}

void bookingServis() {
    Service* newService = new Service();
    cout << "====== New Service ======\n";
    cout << "Model Mobil: "; cin >> ws; getline(cin, newService->carModel);
    cout << "Merek Mobil: "; getline(cin, newService->carBrand);
    cout << "Kendala: "; getline(cin, newService->issueDesc);
    newService->mechanic = selectMechanic();
    cout << "Nama Pelanggan: "; getline(cin, newService->customer);
    newService->priority = getValidPriority();
    cout << "Tanggal Ambil (DD-MM-YY): >"; cin >> newService->outDate;
    
    // Verifikasi tanggal dengan recursion
    //newService->outDate = rekursifTanggal(newService->outDate);
    newService->next = nullptr;
    
    // Insert di akhir (Queue) dengan cara iterasi manual ke ujung [cite: 18]
    if (!headQueue) {
        headQueue = newService;
    } else {
        Service* temp = headQueue;
        while (temp->next) temp = temp->next;
        temp->next = newService;
    }
    cout << "Servis berhasil ditambahkan!\n";
}

void printServiceData(Service* s) {
    cout << "-----------------------\n";
    cout << "Model Mobil: " << s->carModel << "\n";
    cout << "Merek Mobil: " << s->carBrand << "\n";
    cout << "Kendala: " << s->issueDesc << "\n";
    cout << "Montir: " << s->mechanic << "\n";
    cout << "Nama Pelanggan: " << s->customer << "\n";
    cout << "Kepentingan: " << s->priority << "\n";
    cout << "Tanggal Ambil: " << s->outDate << "\n";
    cout << "-----------------------\n";
}