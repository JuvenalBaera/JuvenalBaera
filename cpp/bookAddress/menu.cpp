#include "menu.h"
#include "util\util.h"

void mainMenu(){
    std::cout << "============== MAIN MENU ==============\n\n";
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
    std::cout << "WHAT DO YOU WANT TO CHANGE\n\n";
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
    std::cout << "DO YOU WANT TO PROCEED THIS OPERATION?\n";
    blueColor();
    std::cout << YES_NO_OPTIONS::yes << "\t-\tYes\n";
    std::cout << YES_NO_OPTIONS::no << "\t-\tNo\n";
    resetColor();
}