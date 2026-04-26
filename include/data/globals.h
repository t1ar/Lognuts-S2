#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../../include/data/globals.h"

void cleanScreen();
void cinClean();
bool isValidInt(int &input);
bool isValidChar(char &input);
void chooseMechanic();
struct tm parseDateString(std::string dateStr);
time_t parseDate(std::string dateStr);
std::string addOneDay(std::string dateStr);