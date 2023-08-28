#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>

#define DB_NAME "data/addressbook.txt"

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define RESET_COLOR "\033[0m"

enum MAIN_OPTIONS{
    EXIT,
    ADD_CONTACT,
    VIEW_ALL_CONTACTS,
    SEARCH_CONTACT,
    TOTAL_CONTACTS
};

enum CONTACT_OPTIONS{
    BACK_CONTACT,
    VIEW_CONTACT,
    EDIT_CONTACT,
    DELETE_CONTCACT
};

enum EDIT_OPTIONS{
    BACK_EDIT,
    FNAME_EDIT,
    LNAME_EDIT,
    PHONE_EDIT,
    EMAIL_EDIT,
    VIEW_CONTACT_EDIT
};

enum YES_NO_OPTIONS{
    yes = 1,
    no
};

void newLine();
std::string readString();
int readInteger(std::string msg);
void greenColor();
void redColor();
void yellowColor();
void blueColor();
void resetColor();

void showMessageSuccess(std::string msg);
void showMessageError(std::string msg);
bool isInRange(int num, int min, int max);

#endif