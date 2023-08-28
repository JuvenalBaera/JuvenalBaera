#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <time.h>

#include "../util/util.h"

class Date{
    private:
        int day, month, year;
        std::string dateStr;
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
        bool setDate(std::string date);
        char* getFullDate();
        std::string getFullDate(bool);
        static bool checkDate(int day, int month, int year);
        static std::string getAtualDate();
        static std::string getAtualTime();
        static bool isLeapYear(int year);
};

#endif