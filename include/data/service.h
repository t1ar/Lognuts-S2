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
    bool isCompleted;
    bool isCancelled;
};

extern Service* headQueue;
extern Service* headDone;