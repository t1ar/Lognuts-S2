#pragma once
#include <string>
using namespace std;

const string DB_DIR = "data/";
const string SERVICE_DB = DB_DIR + "Service_DB.json";
const string MECHANIC_DB = DB_DIR + "Montir_DB.json";

void loadData();
void saveData();
void loadMechanics();
void saveMechanics();

extern string mechanics[];
extern int mechanicCount;