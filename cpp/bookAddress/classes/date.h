#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <time.h>

#include "../util/util.h"

class Date{
    private:
        int day, month, year;
    public:
        Date();
        Date(int day, int moth, int year);
        int getDay();
        int getMonth();
        int getYear();
        bool setDay(int day);
        bool setMonth(int month);
        bool setYear(int year);
        bool setDate(int day, int month, int year);
        bool checkDate(int day, int month, int year);
        char* getFullDate();
        static std::string getAtualDate();
        static std::string getAtualTime();
        static bool isLeapYear(int year);
};

#endif