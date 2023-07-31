#include <iostream>
#include <vector>
#include <unordered_map>

#include "util/messages.h"
#include "util/util.h"
#include "classes/contact.h"
#include "classes/addressbook.h"


// ############### PROTOYPES ###############
void mainMenu();
std::string readPhoneNumber();
Contact readContact();
void printContact(Contact c);


int main(){
    AddressBook phoneBook;
    std::vector<Contact> allcontacts;
    Contact *c = nullptr;
    int option, optionInside;
    std::string phone, name;

    system("cls");

    do{
        newLine();
        mainMenu();
        std::cout << OPT_CHOOSE_IN_MSG;
        std::cin >> option;
        newLine();

        switch(option){
            case MAIN_OPTIONS::EXIT:
                std::cout << EXIT_MSG;
                exit(EXIT_SUCCESS);
            break;
            case MAIN_OPTIONS::ADD_CONTACT:
                if(phoneBook.insertContact(readContact()) == true){
                    newLine();
                    showMessageSuccess(CONTACT_SUCESS_MSG);
                }
                else{
                    newLine();
                    showMessageError(CONTACT_FAIL_MSG);
                }
            break;
            case MAIN_OPTIONS::VIEW_ALL_CONTACTS:
                allcontacts = phoneBook.getAllContacts();
                if(allcontacts.size() > 0){
                    for(Contact c : allcontacts){
                        printContact(c);
                        newLine();
                    }
                }
                else
                    showMessageSuccess(LISTBOOK_EMPTY_MSG);
            break;
            case MAIN_OPTIONS::SEARCH_CONTACT:
                if(AddressBook::getTotalContact() > 0){
                    std::cout << FOLLOWING_INFO_MSG;
                    std::cout << PHONE_INPUT_MSG;
                    phone = readPhoneNumber();
                    c = phoneBook.searchContactByPhone(phone);
                    newLine();
                    if(c == NULL)
                        showMessageError(PHONE_NOT_EXIST);
                    else{
                        printContact(*c);
                        do{
                            std::cout << "\nWHAT DO YOU WANT TO DO?\n\n";
                            blueColor();
                            std::cout << CONTACT_OPTIONS::BACK_CONTACT << "\t-\tBack\n";
                            std::cout << CONTACT_OPTIONS::VIEW_CONTACT << "\t-\tView Contact\n";
                            std::cout << CONTACT_OPTIONS::EDIT_CONTACT << "\t-\tEdit contact\n";
                            std::cout << CONTACT_OPTIONS::DELETE_CONTCACT << "\t-\tDetele contact\n";
                            resetColor();

                            std::cout << "\nChoose an option: ";
                            std::cin >> optionInside;
                            newLine();

                            switch(optionInside){
                                case CONTACT_OPTIONS::BACK_CONTACT: break;
                                case CONTACT_OPTIONS::VIEW_CONTACT: printContact(*c); break;
                                case CONTACT_OPTIONS::EDIT_CONTACT:
                                    do{
                                        std::cout << "What do you want to change\n\n";
                                        blueColor();
                                        std::cout << EDIT_OPTIONS::BACK_EDIT  << "\t-\tBack\n";
                                        std::cout << EDIT_OPTIONS::FNAME_EDIT << "\t-\tFirst Name\n";
                                        std::cout << EDIT_OPTIONS::LNAME_EDIT << "\t-\tLast Name\n";
                                        std::cout << EDIT_OPTIONS::PHONE_EDIT << "\t-\tPhone Number\n";
                                        std::cout << EDIT_OPTIONS::EMAIL_EDIT << "\t-\tEmail\n";
                                        std::cout << EDIT_OPTIONS::VIEW_CONTACT_EDIT << "\t-\tView contact\n";
                                        resetColor();

                                        std::cout << "\nChoose an option: ";
                                        std::cin >> option;
                                        newLine();

                                        switch(option){
                                            case EDIT_OPTIONS::BACK_EDIT: break;
                                            case EDIT_OPTIONS::FNAME_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                std::cout << FNAME_INPUT_MSG;
                                                std::getline(std::cin >> std::ws, name);
                                                c->setFirstName(name);
                                                showMessageSuccess("\nFirst name successfully updated\n");
                                            break;
                                            case EDIT_OPTIONS::LNAME_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                std::cout << LNAME_INPUT_MSG;
                                                std::getline(std::cin >> std::ws, name);
                                                c->setLastName(name);
                                                showMessageSuccess("\nLast name successfully updated\n");
                                            break;
                                            case EDIT_OPTIONS::PHONE_EDIT:
                                            std::cout << FOLLOWING_INFO_MSG;
                                                std::cout << PHONE_INPUT_MSG;
                                                phone = readPhoneNumber();
                                                if(phoneBook.searchContactByPhone(phone) == NULL){
                                                    c->setPhone(phone);
                                                    showMessageSuccess("\nPhone number successfully updated\n");
                                                }
                                                else
                                                    showMessageError("\nPhone number already exist\n");
                                            break;
                                            case EDIT_OPTIONS::EMAIL_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                std::cout << EMAIL_INPUT_MSG;
                                                std::getline(std::cin >> std::ws, name);
                                                c->setEmail(name);
                                                showMessageSuccess("\nEmail successfully updated\n");
                                            break;
                                            case EDIT_OPTIONS::VIEW_CONTACT_EDIT:
                                                printContact(*c);
                                                break;
                                            default:
                                                showMessageError(INVALID_OPTION_MSG);
                                        }
                                        newLine();
                                    }while(option != 0);
                                    option = -1;
                                break;
                                case CONTACT_OPTIONS::DELETE_CONTCACT:
                                    do{
                                        std::cout << "Do you want to proceed?\n\n";
                                        std::cout << "1\t-\tYes\n";
                                        std::cout << "2\t-\tNo\n\n";
                                        std::cout << "Choose an option: ";
                                        std::cin >> optionInside;
                                    }while(optionInside < 1 || optionInside > 2);
                                    if(optionInside == 1){
                                        phoneBook.deleteContact(phone);
                                        showMessageSuccess("\nPhone number successfully deleted\n");
                                        optionInside = 0;
                                    }
                                break;
                                default:
                                    showMessageError(INVALID_OPTION_MSG);
                            }   
                        }while(optionInside != 0);
                    }
                }
                else
                    showMessageSuccess(LISTBOOK_EMPTY_MSG);
            break;
            case MAIN_OPTIONS::TOTAL_CONTACTS:
                yellowColor();
                printf("TOTAL OF CONTACTS: %ld\n", AddressBook::getTotalContact());
                resetColor();
                newLine();
            break;
            default:
                showMessageError(INVALID_OPTION_MSG);
        }
    }while(option != 0);
    return 0;
}


// ############### DEFINITION ###############
void mainMenu(){
    blueColor();
    std::cout << MAIN_OPTIONS::EXIT << "\t-\tExit\n";
    std::cout << MAIN_OPTIONS::ADD_CONTACT << "\t-\tAdd contact\n";
    std::cout << MAIN_OPTIONS::VIEW_ALL_CONTACTS << "\t-\tview all contacts\n";
    std::cout << MAIN_OPTIONS::SEARCH_CONTACT << "\t-\tSearch contact\n";
    std::cout << MAIN_OPTIONS::TOTAL_CONTACTS << "\t-\tTotal contacts\n";
    resetColor();
}

std::string readPhoneNumber(){
    std::string phone;
    int sizeLen;

    std::getline(std::cin >> std::ws, phone);

    sizeLen = phone.length();
    if(sizeLen != 9){
        for(int i = 0; i < 9 - sizeLen; i++)
            phone.insert(0, "0");
    }
    return phone;
}

Contact readContact(){
    Contact c;
    std::string fname, lname, phone, email;

    std::cout << FOLLOWING_INFO_MSG;

    std::cout << FNAME_INPUT_MSG;
    std::getline(std::cin >> std::ws, fname);

    std::cout << LNAME_INPUT_MSG;
    std::getline(std::cin >> std::ws, lname);

    std::cout << PHONE_INPUT_MSG;
    phone = readPhoneNumber();

    std::cout << EMAIL_INPUT_MSG;
    std::getline(std::cin >> std::ws, email);

    c.setFullName(fname, lname);
    c.setPhone(phone);
    c.setEmail(email);

    return c;
}

void printContact(Contact c){
    greenColor();
    std::cout << NAME_OUTPUT_MSG << c.getFullName() << std::endl;
    std::cout << PHONE_OUTPUT_MSG << c.getPhoneFormated() << std::endl;
    std::cout << EMAIL_OUTPUT_MSG << c.getEmail() << std::endl;
    resetColor();
}
