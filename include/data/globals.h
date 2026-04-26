#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Service; //forward declaration

void CleanScreen();
void CinClean();
bool IsValidInt(int &input);
bool IsValidChar(char &input);
void ChooseMechanic();
std::string RecursionDate(std::string date, int shiftCount = 0, Service* skipService = nullptr);
bool IsDateTaken(std::string date, Service* skip_service = nullptr);
std::string AddOneDay(std::string date_str);
struct tm ParseDateString(std::string date_str);
time_t ParseDate(std::string date_str);
std::string AddOneDay(std::string date_str);