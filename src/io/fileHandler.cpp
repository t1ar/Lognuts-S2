#include "../../include/io/fileHandler.h"
#include "../../include/data/service.h"

using namespace std;

using json = nlohmann::json;

string mechanics[10];// no way a small shop has more than 10 employee
int mechanic_count = 0;

void SaveDatabase() {
    json db;
    db["onQueue"] = json::array();
    db["done"] = json::array();

    // Simpan antrian aktif
    Service* current = headQueue;
    while (current) {
        json j;
        j["carModel"] = current->carModel;
        j["carBrand"] = current->carBrand;
        j["customer"] = current->customer;
        j["outDate"] = current->outDate;
        j["priority"] = current->priority;
        j["mechanic"] = current->mechanic;
        j["issueDesc"] = current->issueDesc;
        db["onQueue"].push_back(j);
        current = current->next;
    }

    // Simpan history servis selesai
    current = headDone;
    while (current) {
        json j;
        j["carModel"] = current->carModel;
        j["carBrand"] = current->carBrand;
        j["customer"] = current->customer;
        j["outDate"] = current->outDate;
        j["priority"] = current->priority;
        j["mechanic"] = current->mechanic;
        j["issueDesc"] = current->issueDesc;
        db["done"].push_back(j);
        current = current->next;
    }

    ofstream file(SERVICE_DB);
    if (file.is_open()) {
        file << db.dump(4);
        file.close();
    }
}

void LoadDatabase() {
    ifstream file(SERVICE_DB);
    if (!file.is_open()) {
        cout << "Service_DB not found! Creating a new one." << endl;
        return;
    }

    json db;
    try {
        file >> db;
    } catch (json::parse_error& e) {
        cout << "[Error] Database rusak: " << e.what() << '\n';
        return;
    }
    file.close();

    // Muat antrian aktif
    if (db.contains("onQueue")) {
        for (const auto& item : db["onQueue"]) {
            Service* service = new Service();
            service->carModel = item.value("carModel", "");
            service->carBrand = item.value("carBrand", "");
            service->customer = item.value("customer", "");
            service->outDate = item.value("outDate", "");
            
            if (item.contains("priority")) {
                if (item["priority"].is_number()) {
                    service->priority = item["priority"].get<int>();
                } else if (item["priority"].is_string()) {
                    try { service->priority = stoi(item["priority"].get<string>()); }
                    catch (...) { service->priority = 1; }
                } else {
                    service->priority = 1;
                }
            } else {
                service->priority = 1;
            }
            
            service->mechanic = item.value("mechanic", "");
            service->issueDesc= item.value("issueDesc", "");
            service->next = nullptr;

            if (!headQueue) headQueue = service;
            else {
                Service* temp = headQueue;
                while (temp->next) temp = temp->next;
                temp->next = service;
            }
        }
    }

    // Muat history servis selesai
    if (db.contains("done")) {
        for (const auto& item : db["done"]) {
            Service* service = new Service();
            service->carModel = item.value("carModel", "");
            service->carBrand = item.value("carBrand", "");
            service->customer = item.value("customer", "");
            service->outDate = item.value("outDate", "");
            
            if (item.contains("priority")) {
                if (item["priority"].is_number()) {
                    service->priority = item["priority"].get<int>();
                } else if (item["priority"].is_string()) {
                    try { service->priority = stoi(item["priority"].get<string>()); }
                    catch (...) { service->priority = 1; }
                } else {
                    service->priority = 1;
                }
            } else {
                service->priority = 1;
            }
            
            service->mechanic = item.value("mechanic", "");
            service->issueDesc= item.value("issueDesc", "");
            service->next = nullptr;

            if (!headDone) headDone = service;
            else {
                Service* temp = headDone;
                while (temp->next) temp = temp->next;
                temp->next = service;
            }
        }
    }
}

void LoadMechanics(){
    ifstream file(MECHANIC_DB);
    if (!file.is_open()) {
        cout << "Montir_DB not found! Using default mechanics.\n";
        // use defaults if missing
        mechanics[0] = "Suby"; //the owner , duhh
        mechanics[1] = "Farhan"; //most loyal one
        mechanic_count = 2;
        return;
    }
    json data = json::parse(file);
        mechanic_count = 0;
        
        // Loop through mechanics array
        for (auto& mechanic : data["mechanics"]) {
            mechanics[mechanic_count] = mechanic.get<string>();
            mechanic_count++;
        }
        
    file.close();
}

void SaveMechanics() {
    json data;
    
    // Build JSON array
    for (int i = 0; i < mechanic_count; i++) {
        data["mechanics"].push_back(mechanics[i]);
    }
    
    ofstream file(MECHANIC_DB);
    file << data.dump(2);  // Pretty print with 2-space indent
    file.close();
}

void LoadData() {
    LoadDatabase();
    LoadMechanics();
}

void SaveData() {
    SaveDatabase();
    SaveMechanics();
}