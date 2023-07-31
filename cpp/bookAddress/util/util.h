#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>

enum OPTIONS{
    EXIT,
    ADD_CONTACT,
    VIEW_ALL_CONTACTS,
    SEARCH_CONTACT,
    EDIT_CONTACT,
    DELETE_CONTACT,
    TOTAL_CONTACT
};

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define RESET_COLOR "\033[0m"

void newLine();

void greenColor();
void redColor();
void yellowColor();
void blueColor();
void resetColor();

void showMessageSuccess(std::string msg);
void showMessageError(std::string msg);
#endif