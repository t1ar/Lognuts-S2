#include "../../include/data/service.h"
#include "../../include/data/globals.h"
#include "../../include/io/fileHandler.h"
#include "../../include/menu/menu.h"

using namespace std;

Service* headQueue = nullptr;
Service* headDone = nullptr;

int GetValidPriority() {
    int priority;
    while (true) {
        cout << "Kepentingan (1-4): ";
        cin >> priority;
        
        if (!IsValidInt(priority)) continue;
        
        if (priority >= 1 && priority <= 4) {
            cin.ignore(10000, '\n');  // Clear remaining input
            return priority;
        } else {
            cout << "Error: Hanya input 1, 2, 3, atau 4!\n";
        }
    }
}

string SelectMechanic() {
    LoadMechanics();
    
    ChooseMechanicUI();
    
    int choice;
    while (true) {
        cout << "Masukkan nomor (1-" << mechanic_count << "): ";
        cin >> choice;
        
        if (!IsValidInt(choice)) continue;
        
        if (choice >= 1 && choice <= mechanic_count) {
            cin.ignore(10000, '\n');
            return mechanics[choice - 1];
        } else {
            cout << "Error: Pilihan tidak valid!\n";
        }
    }
}

void SwapServiceData(Service* a, Service* b) {
    // save the next pointer first
    Service* temp_next_a = a->next;
    Service* temp_next_b = b->next;

    Service temp_service = *a;
    *a = *b;
    *b = temp_service;

    // restore the pointer to avoid corruption
    a->next = temp_next_a;
    b->next = temp_next_b;
}

// uses bubble sort
void QueueSort(Service* head, char mode) {
    // Jika antrian kosong atau hanya ada 1 elemen, tidak perlu disortir
    if (!head || !head->next) return;
    
    bool swapped;
    Service* ptr1;
    Service* lptr = nullptr; // Batas akhir pengecekan

    do {
        swapped = false;
        ptr1 = head;

        // Loop berjalan sampai menyentuh elemen yang sudah terurut di akhir (lptr)
        while (ptr1->next != lptr) {
            bool condition = false;
            
            if (mode == 'D') { 
                // Sort By Date (Ascending / Tanggal terawal di atas)
                if (ParseDate(ptr1->outDate) > ParseDate(ptr1->next->outDate)) {
                    condition = true;
                }
            } else if (mode == 'U') { 
                // Sort By Urgency (Descending / Kepentingan tertinggi di atas)
                if (ptr1->priority < ptr1->next->priority) {
                    condition = true;
                } else if (ptr1->priority == ptr1->next->priority) {
                    // Jika urgensi sama, prioritaskan tanggal terawal 
                    if (ParseDate(ptr1->outDate) > ParseDate(ptr1->next->outDate)) {
                        condition = true;
                    }
                }
            }
            
            // Lakukan swap data jika posisinya salah
            if (condition) {
                SwapServiceData(ptr1, ptr1->next);
                swapped = true;
            }
            
            ptr1 = ptr1->next; // Pindah ke node selanjutnya
        }
        
        // Optimasi: Setelah satu putaran, elemen paling ujung pasti sudah nilai terbesar/terkecil.
        // Jadi, iterasi berikutnya tidak perlu mengecek sampai ujung lagi.
        lptr = ptr1; 
        
    } while (swapped);
}

void BookingServis() {
    Service* new_service = new Service();
    cout << "====== New Service ======\n";
    cout << "Model Mobil: "; cin >> ws; getline(cin, new_service->carModel);
    cout << "Merek Mobil: "; getline(cin, new_service->carBrand);
    cout << "Kendala: "; getline(cin, new_service->issueDesc);
    new_service->mechanic = SelectMechanic();
    cout << "Nama Pelanggan: "; getline(cin, new_service->customer);
    new_service->priority = GetValidPriority();
    cout << "Tanggal Ambil (DD-MM-YY): >"; cin >> new_service->outDate;
    
    // Verifikasi tanggal dengan recursion
    //new_service->outDate = rekursifTanggal(new_service->outDate);
    new_service->next = nullptr;
    
    // Insert di akhir (Queue) dengan cara iterasi manual ke ujung [cite: 18]
    if (!headQueue) {
        headQueue = new_service;
    } else {
        Service* temp = headQueue;
        while (temp->next) temp = temp->next;
        temp->next = new_service;
    }
    cout << "Servis berhasil ditambahkan!\n";
}

void PrintServiceData(Service* service) {
    cout << "-----------------------\n";
    cout << "Model Mobil: " << service->carModel << "\n";
    cout << "Merek Mobil: " << service->carBrand << "\n";
    cout << "Kendala: " << service->issueDesc << "\n";
    cout << "Montir: " << service->mechanic << "\n";
    cout << "Nama Pelanggan: " << service->customer << "\n";
    cout << "Kepentingan: " << service->priority << "\n";
    cout << "Tanggal Ambil: " << service->outDate << "\n";
    cout << "-----------------------\n";
}