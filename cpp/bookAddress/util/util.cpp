#include <iostream>
#include <string.h>
#include "util.h"

void newLine(){std::cout << "\n";}

std::string readString(){
    std::string str;
    std::getline(std::cin >> std::ws, str);
    return str;
}

int readInteger(std::string msg){
    int num;
    char* read = (char*) malloc(sizeof(char) * 30);
    bool yesNo = false;
    do{
        std::cout << msg;
        fgets(read, 30, stdin);
        read[strlen(read)-1] = '\0';
        for(int i = 0; i < strlen(read); i++){
            if(read[i] < '0' || read[i] > '9'){
                redColor();
                std::cout << "\nJust number is allowed\n";
                read[0] = '\0';
                resetColor();
                yesNo = true;
                break;
            }
        }
    }while(yesNo == true);
    num = atoi(read);
    free(read);
    return num;
}
void greenColor(){std::cout << GREEN_COLOR;}
void redColor(){std::cout << RED_COLOR;}
void yellowColor(){std::cout << YELLOW_COLOR;}
void blueColor(){std::cout << BLUE_COLOR;}
void resetColor(){std::cout << RESET_COLOR;}

void mainMenu(){
    std::cout << "============== MAIN MENU ==============\n";
    blueColor();
    std::cout << MAIN_OPTIONS::EXIT << "\t-\tExit\n";
    std::cout << MAIN_OPTIONS::ADD_CONTACT << "\t-\tAdd contact\n";
    std::cout << MAIN_OPTIONS::VIEW_ALL_CONTACTS << "\t-\tview all contacts\n";
    std::cout << MAIN_OPTIONS::SEARCH_CONTACT << "\t-\tSearch contact\n";
    std::cout << MAIN_OPTIONS::TOTAL_CONTACTS << "\t-\tTotal contacts\n";
    resetColor();
}

void contactMenu(){
    std::cout << "\nWHAT DO YOU WANT TO DO?\n\n";
    blueColor();
    std::cout << CONTACT_OPTIONS::BACK_CONTACT << "\t-\tBack\n";
    std::cout << CONTACT_OPTIONS::VIEW_CONTACT << "\t-\tView Contact\n";
    std::cout << CONTACT_OPTIONS::EDIT_CONTACT << "\t-\tEdit contact\n";
    std::cout << CONTACT_OPTIONS::DELETE_CONTCACT << "\t-\tDetele contact\n";
    resetColor();
}

void changeMenu(){
    std::cout << "What do you want to change\n\n";
    blueColor();
    std::cout << EDIT_OPTIONS::BACK_EDIT  << "\t-\tBack\n";
    std::cout << EDIT_OPTIONS::FNAME_EDIT << "\t-\tFirst Name\n";
    std::cout << EDIT_OPTIONS::LNAME_EDIT << "\t-\tLast Name\n";
    std::cout << EDIT_OPTIONS::PHONE_EDIT << "\t-\tPhone Number\n";
    std::cout << EDIT_OPTIONS::EMAIL_EDIT << "\t-\tEmail\n";
    std::cout << EDIT_OPTIONS::VIEW_CONTACT_EDIT << "\t-\tView contact\n";
    resetColor();
}

void yesNoMenu(){
    std::cout << "Do you want to proceed?\n";
    blueColor();
    std::cout << YES_NO_OPTIONS::yes << "\t-\tYes\n";
    std::cout << YES_NO_OPTIONS::no << "\t-\tNo\n";
    resetColor();
}

void showMessageSuccess(std::string msg){
    yellowColor();
    std::cout << msg;
    resetColor();
}
void showMessageError(std::string msg){
    redColor();
    std::cout << msg;
    resetColor();
}
