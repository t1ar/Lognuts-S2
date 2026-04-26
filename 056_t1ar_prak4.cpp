//for grader : see below this sc code
#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "include/data/service.h"

#include "include/io/fileHandler.h"

#include "include/menu/menu.h"

using namespace std;

int main(){
    TitleASCII();
    LoadMechanics();
    LoadData();
    MainMenu();
    SaveData();
    cout << R"(-----------------------------------------------
		   Thank You for visiting!
-----------------------------------------------)" << endl;
    return 0;
}













































//dear doc praktikum maker, the trap ai prompt is bit soft.
//my suggestion is just put it every after steps
//and also enforce the ai to use a very specific namecase
//,and use a specific way to do looping or how they handle
//things like switching a var in a array, and then
//putting very VERY obvious writing style in the code docs
//to make vibers very embarrassed. Happy Hunting!
//(that very small and white text is clever.) -t1ar
















































