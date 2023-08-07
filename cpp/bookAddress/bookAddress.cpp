#include <iostream>
#include <vector>
#include <unordered_map>

#include "util/messages.h"
#include "util/util.h"

#include "classes/contact.h"
#include "classes/addressbook.h"

#include "readWrite/readcmd.h"
#include "readWrite/writecmd.h"

#include "database/readDb.h"
#include "database/writeDb.h"

#include "menu.h"

int main(){
    AddressBook phoneBook;
    std::vector<Contact> allcontacts;
    Contact *c = nullptr;
    int option, optionInside;
    std::string phone, name;

    system("cls");

    readFromDatabase(&phoneBook, DB_NAME);

    do{
        newLine();
        mainMenu();
        option = readOption();
        switch(option){
            case MAIN_OPTIONS::EXIT:
                std::cout << EXIT_MSG;
                exit(EXIT_SUCCESS);
            break;
            case MAIN_OPTIONS::ADD_CONTACT:
                if(phoneBook.insertContact(readContact()) == true)
                    showMessageSuccess(CONTACT_SUCESS_MSG);
                else
                    showMessageError(CONTACT_FAIL_MSG);
            break;
            case MAIN_OPTIONS::VIEW_ALL_CONTACTS:
                allcontacts = phoneBook.getAllContacts();
                if(allcontacts.size() > 0){
                    newLine();
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
                    phone = readPhoneNumber();
                    c = phoneBook.searchContactByPhone(phone);
                    newLine();
                    if(c == NULL)
                        showMessageError(PHONE_NOT_EXIST_MSG);
                    else{
                        printContact(*c);
                        do{
                            contactMenu();
                            optionInside = readOption();

                            switch(optionInside){
                                case CONTACT_OPTIONS::BACK_CONTACT: break;
                                case CONTACT_OPTIONS::VIEW_CONTACT:
                                    newLine();
                                    printContact(*c);
                                break;
                                case CONTACT_OPTIONS::EDIT_CONTACT:
                                    newLine();
                                    do{
                                        changeMenu();
                                        option =  readOption();

                                        switch(option){
                                            case EDIT_OPTIONS::BACK_EDIT: break;
                                            case EDIT_OPTIONS::FNAME_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                name = readFname();
                                                c->setFirstName(name);
                                                showMessageSuccess(FNAME_UPDATE_MSG);
                                            break;
                                            case EDIT_OPTIONS::LNAME_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                name = readLname();
                                                c->setLastName(name);
                                                showMessageSuccess(LNAME_UPDATE_MSG);
                                            break;
                                            case EDIT_OPTIONS::PHONE_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                phone = readPhoneNumber();
                                                if(phoneBook.searchContactByPhone(phone) == NULL){
                                                    c->setPhone(phone);
                                                    showMessageSuccess(PHONE_UPDATE_MSG);
                                                }
                                                else
                                                    showMessageError(PHONE_EXIST_MSG);
                                            break;
                                            case EDIT_OPTIONS::EMAIL_EDIT:
                                                std::cout << FOLLOWING_INFO_MSG;
                                                name = readEmail();
                                                c->setEmail(name);
                                                showMessageSuccess(EMAIL_UPDATE_MSG);
                                            break;
                                            case EDIT_OPTIONS::VIEW_CONTACT_EDIT:
                                                newLine();
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
                                    newLine();
                                    do{
                                        yesNoMenu();
                                        optionInside = readOption();
                                    }while(optionInside < 1 || optionInside > 2);
                                    if(optionInside == 1){
                                        phoneBook.deleteContact(phone);
                                        showMessageSuccess(CONTACT_DELETE_MSG);
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
                printf("%s: %ld\n", TOTAL_CONTACT_MSG, AddressBook::getTotalContact());
                resetColor();
            break;
            default:
                showMessageError(INVALID_OPTION_MSG);
        }
    }while(option != 0);
    return 0;
}
