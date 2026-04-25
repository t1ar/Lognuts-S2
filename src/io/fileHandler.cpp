#include "../../include/io/fileHandler.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

string mechanics[10];// no way a small shop has more than 10 employee
int mechanicCount = 0;

void loadData() {
    ifstream file("data/customers.json");
    if (!file.is_open()) return;
    
    json data = json::parse(file);
    // Load logic here
    file.close();
}

void saveData() {
    json data;
    // Build JSON from linked list
    ofstream file("data/customers.json");
    file << data.dump(2);
    file.close();
}

void loadMechanics(){
    ifstream file(MECHANIC_DB);
    if (!file.is_open()) {
        cout << "Montir_DB.json not found! Using default mechanics.\n";
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
        
        cout << "Loaded " << mechanicCount << " mechanics from file.\n";
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