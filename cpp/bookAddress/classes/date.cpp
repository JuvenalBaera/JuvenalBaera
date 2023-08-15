#include "date.h"

Date::Date(){}

Date::Date(int day, int month, int year){
    if(setDate(day, month, year) == false){
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
}

bool Date::isLeapYear(int year){
    if((year % 4 == 0 || year % 400 == 0) && year % 100 != 0)
        return true;
    return false;
}

int Date::getDay(){return this->day;}

int Date::getMonth(){return this->month;}

int Date::getYear(){return this->year;}

bool Date::setDay(int day){
    if(isInRange(day, 1, 31) == true){
        this->day = day;
        return true;
    }
    return false;
}

bool Date::setMonth(int month){
    if(isInRange(month, 1, 12)){
        this->month = month;
        return true;
    }
    return false;
}

bool Date::setYear(int year){
    if(isInRange(year, 2023 - 50, 2023)){
        this->year = year;
        return true;
    }
    return false;
}

bool Date::setDate(int day, int month, int year){
    if(isInRange(year, 2023-50, 2023)){
        if(checkDate(day, month, year)){
            this->setDay(day);
            this->setMonth(month);
            this->setYear(year);
            return true;
        }
        return false;
    }
    return false;
}

bool Date::checkDate(int day, int month, int year){
    if(isInRange(month, 1, 12)){
        switch(month){
            case 1: case 3: case 5: case 7:
            case 8: case 10: case 12:
                if(isInRange(day, 1, 31)) return true;
                return false;
            case 4: case 6: case 9: case 11:
                if(isInRange(day, 1, 30)) return true;
                return false;
            case 2:
                if(Date::isLeapYear(year)){
                    if(isInRange(day, 1, 29)) return true;
                    return false;
                }
                else if(isInRange(day, 1, 28)) return true;
                return false;
            default: return false;
        }
    }
    return false;
}

std::string Date::getAtualDate(){return __DATE__;}

std::string Date::getAtualTime(){return __TIME__;}
