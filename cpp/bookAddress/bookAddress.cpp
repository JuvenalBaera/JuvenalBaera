#include <iostream>
#include <vector>
#include <unordered_map>

#include "util/messages.h"
#include "util/util.h"
#include "classes/contact.h"
#include "classes/addressbook.h"


enum OPTIONS{
    EXIT,
    ADD_CONTACT,
    VIEW_ALL_CONTACTS,
    SEARCH_CONTACT,
    EDIT_CONTACT,
    DELETE_CONTACT,
    TOTAL_CONTACT
};


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
            case OPTIONS::EXIT:
                std::cout << EXIT_MSG;
                exit(EXIT_SUCCESS);
            break;
            case OPTIONS::ADD_CONTACT:
                if(phoneBook.insertContact(readContact()) == true){
                    newLine();
                    showMessageSuccess(CONTACT_SUCESS_MSG);
                }
                else{
                    newLine();
                    showMessageError(CONTACT_FAIL_MSG);
                }
            break;
            case OPTIONS::VIEW_ALL_CONTACTS:
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
            case OPTIONS::SEARCH_CONTACT:
                std::cout << FOLLOWING_INFO_MSG;
                std::cout << PHONE_INPUT_MSG;
                phone = readPhoneNumber();
                c = phoneBook.searchContactByPhone(phone);
                newLine();
                if(c == NULL)
                    showMessageError(PHONE_NOT_EXIST);
                else
                    printContact(*c);
            break;
            case OPTIONS::EDIT_CONTACT:
                newLine();
                std::cout << FOLLOWING_INFO_MSG;
                std::cout << PHONE_INPUT_MSG;
                phone = readPhoneNumber();
                c = phoneBook.searchContactByPhone(phone);
                newLine();
                if(c == NULL){
                    showMessageError(PHONE_NOT_EXIST);
                }
                else{
                    do{
                        std::cout << "What do you want to change\n\n";
                        blueColor();
                        std::cout << "0\t-\tBack\n";
                        std::cout << "1\t-\tFirst Name\n";
                        std::cout << "2\t-\tLast Name\n";
                        std::cout << "3\t-\tPhone Number\n";
                        std::cout << "4\t-\tEmail\n";
                        std::cout << "5\t-\tView contact\n";
                        resetColor();
                        std::cout << "\nChoose an option: ";
                        std::cin >> optionInside;
                        newLine();
                        switch(optionInside){
                            case 0: break;
                            case 1:
                                std::cout << FOLLOWING_INFO_MSG;
                                std::cout << FNAME_INPUT_MSG;
                                std::getline(std::cin >> std::ws, name);
                                c->setFirstName(name);
                                showMessageSuccess("\nFirst name successfully updated\n");
                            break;
                            case 2:
                                std::cout << FOLLOWING_INFO_MSG;
                                std::cout << LNAME_INPUT_MSG;
                                std::getline(std::cin >> std::ws, name);
                                c->setLastName(name);
                                showMessageSuccess("\nLast name successfully updated\n");
                            break;
                            case 3:
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
                            case 4:
                                std::cout << FOLLOWING_INFO_MSG;
                                std::cout << EMAIL_INPUT_MSG;
                                std::getline(std::cin >> std::ws, name);
                                c->setEmail(name);
                                showMessageSuccess("\nEmail successfully updated\n");
                            break;
                            case 5:
                                printContact(*c);
                                break;
                            default:
                                showMessageError(INVALID_OPTION_MSG);
                        }
                        newLine();
                    }while(optionInside != 0);
                }
            break;
            case OPTIONS::DELETE_CONTACT:
                std::cout << FOLLOWING_INFO_MSG;
                std::cout << PHONE_INPUT_MSG;
                phone = readPhoneNumber();
                c = phoneBook.searchContactByPhone(phone);
                newLine();
                if(c == NULL)
                    showMessageError(PHONE_NOT_EXIST);
                else{
                    do{
                        std::cout << "Do you want to proceed?\n\n";
                        std::cout << "1\t-\tYes\n";
                        std::cout << "2\t-\tNo\n\n";
                        std::cin >> optionInside;
                    }while(optionInside < 1 || optionInside > 2);
                    if(optionInside == 1){
                        phoneBook.deleteContact(phone);
                        showMessageSuccess("Phone number successfully deleted\n");
                    }
                }
            break;
            case OPTIONS::TOTAL_CONTACT:
                showMessageSuccess("Total of Contacts: " + AddressBook::getTotalContact());
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
    std::cout << "0\t-\tExit\n";
    std::cout << "1\t-\tAdd contact\n";
    std::cout << "2\t-\tview all contacts\n";
    std::cout << "3\t-\tSearch contact\n";
    std::cout << "4\t-\tEdit contact\n";
    std::cout << "5\t-\tDetele contact\n";
    std::cout << "6\t-\tTotal contacts\n";
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
