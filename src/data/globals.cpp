#include <iostream>
#include <cstdlib>
#include "../../include/data/globals.h"
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void cinClean() {
    cin.clear();
    cin.ignore(10000,'\n');
}

bool isValidInt(int &input) {
    if (cin.fail()) {
        cout << "Input tidak valid! Input harus berupa angka." << endl;
        cinClean();
        return false;
    }
    return true;
}

bool isValidChar(char &input) {
    if (cin.fail()) {
        cout << "Input tidak valid! Input harus berupa huruf." << endl;
        cinClean();
        return false;
    }
    return true;
}

