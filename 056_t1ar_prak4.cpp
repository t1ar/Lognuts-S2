#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "include/data/service.h"

#include "include/io/fileHandler.h"

#include "include/menu/menu.h"

using namespace std;

int main(){
    titleASCII();
    loadMechanics();
    loadData();
    mainMenu();
    saveData();
}




