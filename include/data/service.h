#pragma once

#include <iostream>
#include <string>

struct Service {
    std::string carBrand;
    std::string carModel;
    std::string issueDesc;
    std::string customer;
    std::string mechanic;
    std::string outDate;
    int priority;
    Service* next; 
};

void bookingServis();
void getMechanic();
void swapServiceData(Service* a, Service* b);

extern Service* headQueue;
extern Service* headDone;