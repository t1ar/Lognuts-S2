#pragma once
#include <string>
using namespace std;

struct Service {
    string carBrand;
    string carModel;
    string issueDesc;
    string customer;
    string mechanic;
    string outDate;
    int priority;
    Service* next; 
};

void bookingServis();

extern Service* headQueue;
extern Service* headDone;