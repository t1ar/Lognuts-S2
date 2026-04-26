#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

const std::string DB_DIR = "data/";
const std::string SERVICE_DB = DB_DIR + "Service_DB.json";
const std::string MECHANIC_DB = DB_DIR + "Montir_DB.json";

void LoadData();
void SaveData();
void LoadMechanics();
void SaveMechanics();

extern std::string mechanics[];
extern int mechanic_count;