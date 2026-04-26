#include "../../include/data/globals.h"
#include "../../include/data/service.h"
#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

void CleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct tm ParseDateString(string date_str) {
    int day, month, year;
    sscanf(date_str.c_str(), "%d-%d-%d", &day, &month, &year);
    struct tm date_time = {0};
    date_time.tm_mday = day;
    date_time.tm_mon = month - 1;
    date_time.tm_year = year + 100;
    return date_time;
}

time_t ParseDate(string date_str) {
    struct tm date_time = ParseDateString(date_str);
    return mktime(&date_time);
}

string AddOneDay(string date_str) {
    struct tm date_time = ParseDateString(date_str);
    date_time.tm_mday += 1;  // Add one day
    mktime(&date_time);
    char buffer[10];
    strftime(buffer, sizeof(buffer), "%d-%m-%y", &date_time);
    return string(buffer);
}

bool IsDateTaken(string date, Service* skip_service) {
    Service* current = headQueue;
    while (current) {
        if (current != skip_service && current->outDate == date) return true;
        current = current->next;
    }
    return false;
}

string RecursionDate(string date, int shiftCount, Service* skipService) {
    if (shiftCount == 5) {
        cout << "Tanggal sudah diundur sebanyak 5 kali, masukkan tanggal baru : >";
        string newDate;
        cin >> newDate;
        return RecursionDate(newDate, 0, skipService);
    }
    
    if (IsDateTaken(date, skipService)) {
        if (shiftCount == 0) cout << "Tanggal sudah dijadwalkan oleh servis lain\n";
        cout << "Tanggal diundur " << shiftCount + 1 << " hari setelah tanggal baru!!.\n";
        return RecursionDate(AddOneDay(date), shiftCount + 1, skipService);
    }
    
    return date;
}

void CinClean() {
    cin.clear();
    cin.ignore(10000,'\n');
}

bool IsValidInt(int &input) {
    if (cin.fail()) {
        cout << "Input tidak valid! Input harus berupa angka." << endl;
        CinClean();
        return false;
    }
    return true;
}

bool IsValidChar(char &input) {
    if (cin.fail()) {
        cout << "Input tidak valid! Input harus berupa huruf." << endl;
        CinClean();
        return false;
    }
    return true;
}

