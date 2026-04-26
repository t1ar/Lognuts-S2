#include "../../include/data/service.h"
#include "../../include/data/globals.h"
#include "../../include/io/fileHandler.h"
#include "../../include/menu/menu.h"

using namespace std;

void TitleASCII(){
    cout << R"(===============================================
__     _____   ____  __  __ __ __ _____   __ v2
||    ((   )) (( ___ ||\\|| || ||  ||    ((    
||__|  \\_//   \\_|| || \|| \\_//  ||   \_))   
===============================================)" << endl;
}

void MainMenu(){
    int choice;
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
    Pilihan : )"; cin >> choice; cout << "\n";
        
        if (!IsValidInt(choice)) continue;

        switch (choice) {
            case 1: BookingMenu(); break;
            case 2: QueueMenu(); break;
            case 3: FinishService(); break;
            case 4: ChangeDate(); break;
            case 0: return;
            default : cout << "Pilihan tidak valid! \n";
        }
    } while (choice != 0);
}

void BookingMenu() {
    cout << R"(-----------------------------------------------
                Booking Servis
-----------------------------------------------)" << endl;
    BookingServis();
}

void QueueMenu(){
    char choose = 'Q';
    do {
        CleanScreen();
        cout << R"(-----------------------------------------------
		           Antrian
-----------------------------------------------)" << endl;
        Service* cloneHead = nullptr;
        Service* cloneTail = nullptr;
        Service* originalCurr = headQueue;
        
        while (originalCurr) {
            Service* newNode = new Service(*originalCurr);
            newNode->next = nullptr;
            if (!cloneHead) {
                cloneHead = newNode;
                cloneTail = newNode;
            } else {
                cloneTail->next = newNode;
                cloneTail = newNode;
            }
            originalCurr = originalCurr->next;
        }
        
        if (choose == 'D') QueueSort(cloneHead, 'D');
        else if (choose == 'U') QueueSort(cloneHead, 'U');
        
        Service* printCurr = cloneHead;
        if (!printCurr) {
            cout << "Antrian kosong.\n";
        }
        while (printCurr) {
            PrintServiceData(printCurr);
            printCurr = printCurr->next;
        }
        
        // Hapus kloning list dari memori (Garbage Collection)
        Service* deleteCurr = cloneHead;
        while (deleteCurr) {
            Service* temp = deleteCurr;
            deleteCurr = deleteCurr->next;
            delete temp;
        }
        cout << "Sort by : " << endl;
        cout << "[D]ate [U]rgency [Q]ueue [E]xit" << endl;
        cout << "Option : " ; cin >> choose; CinClean();
        choose = toupper(choose);
    } while (choose != 'E');
}

void FinishService() {
    
    cout << R"(-----------------------------------------------
		      Selesaikan Servis
-----------------------------------------------)" << endl;
    if (!headQueue) {
        cout << "Antrian kosong.\n";
        return;
    }

    string chosenMech = SelectMechanic();

    Service* curr = headQueue;
    int count = 0;
    
    cout << "\nDaftar kendaraan yang ditangani oleh " << chosenMech << ":\n";
    while (curr) {
        if (curr->mechanic == chosenMech) {
            count++;
            cout << count << ". " << curr->carBrand << " " << curr->carModel 
                 << " (Pelanggan: " << curr->customer << ") [Pri: " << curr->priority << "]\n";
        }
        curr = curr->next;
    }

    if (count == 0) {
        cout << "Tidak ada servis untuk montir " << chosenMech << ".\n";
        return;
    }
    
    int choice;
    while (true) {
        cout << "\nPilih kendaraan yang selesai (1-" << count << ") atau 0 untuk batal: > ";
        cin >> choice;
        if (!IsValidInt(choice)) continue;
        
        if (choice == 0) {
            cout << "Penyelesaian servis dibatalkan.\n";
            return;
        } else if (choice >= 1 && choice <= count) {
            CinClean();
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    curr = headQueue;
    Service* prev = nullptr;
    Service* target = nullptr;
    Service* prevTarget = nullptr;
    int current_idx = 0;

    // Mencari servis sesuai pilihan
    while (curr) {
        if (curr->mechanic == chosenMech) {
            current_idx++;
            if (current_idx == choice) {
                target = curr;
                prevTarget = prev;
                break;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    
    // Konfirmasi penyelesaian
    char confirm;
    cout << "Konfirmasi penyelesaian servis " << target->carBrand << " " << target->carModel 
         << " milik " << target->customer << "? (Y/N): > ";
    cin >> confirm;
    CinClean();
    
    if (toupper(confirm) != 'Y') {
        cout << "Penyelesaian servis dibatalkan.\n";
        return;
    }
    
    // Cabut target dari antrian aktif (headQueue)
    if (!prevTarget) {
        headQueue = target->next;
    } else {
        prevTarget->next = target->next;
    }
    
    // Pindahkan target ke dalam riwayat selesai (headDone)
    target->next = headDone;
    headDone = target;
    
    cout << "\nServis " << target->carBrand << " " << target->carModel 
         << " milik pelanggan " << target->customer 
         << " berhasil diselesaikan oleh " << chosenMech << "!\n";
}

void ChangeDate(){
    cout << R"(-----------------------------------------------
		     Ganti Tanggal Ambil
-----------------------------------------------)" << endl;

    if (!headQueue) {
         cout << "Antrian kosong.\n"; return; 
    }

    Service* curr = headQueue;
    int idx = 1;
    while (curr) {
        cout << "Servis Ke-" << idx << ":\n";
        PrintServiceData(curr);
        curr = curr->next;
        idx++;
    }
    
    int choose;
    cout << "Pilih servis yang ingin di reschedule\n: >";
    cin >> choose;
    if (!IsValidInt(choose) || choose < 1) {
        cout << "Pilihan tidak valid.\n";
        return;
    }
    
    Service* target = headQueue;
    for (int i = 1; i < choose && target != nullptr; i++) {
        target = target->next;
    }
    
    if (!target) { cout << "Pilihan tidak valid.\n"; return; }
    
    string newDate;
    cout << "Masukkan Tanggal baru: >";
    cin >> newDate;
    CinClean();
    
    string finalDate = RecursionDate(newDate, 0, target);
    target->outDate = finalDate;
    if (finalDate != newDate) {
        cout << "Tanggal ambil yang baru adalah " << finalDate << "\n";
    }
    cout << "Servis " << target->carBrand << " " << target->carModel << " berhasil di undur!!\n";
}

void ChooseMechanicUI(){
    cout << "\nPilih Montir:\n";
    for (int i = 0; i < mechanic_count; i++) {
        cout << (i + 1) << ". " << mechanics[i] << "\n";
    }
}