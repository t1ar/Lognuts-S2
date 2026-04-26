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

void BookingServis();
std::string SelectMechanic();
void SwapServiceData(Service* a, Service* b);
void QueueSort(Service* head, char mode);
void PrintServiceData(Service* service);

extern Service* headQueue;
extern Service* headDone;