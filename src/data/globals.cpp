#include "../../include/data/globals.h"
#include "../../include/data/service.h"
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct tm parseDateString(string dateStr) {
    int d, m, y;
    sscanf(dateStr.c_str(), "%d-%d-%d", &d, &m, &y);
    struct tm t = {0};
    t.tm_mday = d;
    t.tm_mon = m - 1;
    t.tm_year = y + 100;
    return t;
}

time_t parseDate(string dateStr) {
    struct tm t = parseDateString(dateStr);
    return mktime(&t);
}

string addOneDay(string dateStr) {
    struct tm t = parseDateString(dateStr);
    t.tm_mday += 1;  // Add one day
    mktime(&t);
    char buffer[10];
    strftime(buffer, sizeof(buffer), "%d-%m-%y", &t);
    return string(buffer);
}

bool isDateTaken(string date, Service* skipService = nullptr) {
    Service* curr = headQueue;
    while (curr) {
        if (curr != skipService && curr->outDate == date) return true;
        curr = curr->next;
    }
    return false;
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

