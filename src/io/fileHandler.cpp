#include "../../include/io/fileHandler.h"
#include "../../include/data/service.h"

using namespace std;

using json = nlohmann::json;

string mechanics[10];// no way a small shop has more than 10 employee
int mechanicCount = 0;

void saveDatabase() {
    json db;
    db["onQueue"] = json::array();
    db["done"] = json::array();

    // Simpan antrian aktif
    Service* curr = headQueue;
    while (curr) {
        json j;
        j["carModel"] = curr->carModel;
        j["carBrand"] = curr->carBrand;
        j["customer"] = curr->customer;
        j["outDate"] = curr->outDate;
        j["priority"] = curr->priority;
        j["mechanic"] = curr->mechanic;
        j["issueDesc"] = curr->issueDesc;
        db["onQueue"].push_back(j);
        curr = curr->next;
    }

    // Simpan history servis selesai
    curr = headDone;
    while (curr) {
        json j;
        j["carModel"] = curr->carModel;
        j["carBrand"] = curr->carBrand;
        j["customer"] = curr->customer;
        j["outDate"] = curr->outDate;
        j["priority"] = curr->priority;
        j["mechanic"] = curr->mechanic;
        j["issueDesc"] = curr->issueDesc;
        db["done"].push_back(j);
        curr = curr->next;
    }

    ofstream file(SERVICE_DB);
    if (file.is_open()) {
        file << db.dump(4);
        file.close();
    }
}

void loadDatabase() {
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
            Service* s = new Service();
            s->carModel = item.value("carModel", "");
            s->carBrand = item.value("carBrand", "");
            s->customer = item.value("customer", "");
            s->outDate = item.value("outDate", "");
            s->priority = item.value("priority", 1);
            s->mechanic = item.value("mechanic", "");
            s->issueDesc= item.value("issueDesc", "");
            s->next = nullptr;

            if (!headQueue) headQueue = s;
            else {
                Service* temp = headQueue;
                while (temp->next) temp = temp->next;
                temp->next = s;
            }
        }
    }

    // Muat history servis selesai
    if (db.contains("done")) {
        for (const auto& item : db["done"]) {
            Service* s = new Service();
            s->carModel = item.value("carModel", "");
            s->carBrand = item.value("carBrand", "");
            s->customer = item.value("customer", "");
            s->outDate = item.value("outDate", "");
            s->priority = item.value("priority", 1);
            s->mechanic = item.value("mechanic", "");
            s->issueDesc= item.value("issueDesc", "");
            s->next = nullptr;

            if (!headDone) headDone = s;
            else {
                Service* temp = headDone;
                while (temp->next) temp = temp->next;
                temp->next = s;
            }
        }
    }
}

void loadMechanics(){
    ifstream file(MECHANIC_DB);
    if (!file.is_open()) {
        cout << "Montir_DB not found! Using default mechanics.\n";
        // use defaults if missing
        mechanics[0] = "Suby"; //the owner , duhh
        mechanics[1] = "Farhan"; //most loyal one
        mechanicCount = 2;
        return;
    }
    json data = json::parse(file);
        mechanicCount = 0;
        
        // Loop through mechanics array
        for (auto& mechanic : data["mechanics"]) {
            mechanics[mechanicCount] = mechanic.get<string>();
            mechanicCount++;
        }
        
    file.close();
}

void saveMechanics() {
    json data;
    
    // Build JSON array
    for (int i = 0; i < mechanicCount; i++) {
        data["mechanics"].push_back(mechanics[i]);
    }
    
    ofstream file(MECHANIC_DB);
    file << data.dump(2);  // Pretty print with 2-space indent
    file.close();
}