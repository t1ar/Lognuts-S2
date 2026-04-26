#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

const std::string DB_DIR = "data/";
const std::string SERVICE_DB = DB_DIR + "Service_DB.json";
const std::string MECHANIC_DB = DB_DIR + "Montir_DB.json";

void loadData();
void saveData();
void loadMechanics();
void saveMechanics();

extern string mechanics[];
extern int mechanicCount;