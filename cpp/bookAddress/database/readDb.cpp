#include "readDb.h"
#include "../util/messages.h"
#include "../readWrite/writeCmd.h"

void readFromDatabase(AddressBook *bookAddr,std::string filename){
    std::ifstream read;
    std::string line;
    Contact contact;
    Person p;
    Date date;
    std::string fname, lname, phone, email, dateStr, phone_code, country;
    char gender;

    int count = 0;

    read.open(filename, std::ios::in);

    if(read.is_open()){
        while(read >> fname >> lname >> gender >> dateStr >> phone_code >> phone >> email){
            std::getline(read >> std::ws, country);

            // std::cout << "Fname: " << fname << std::endl;
            // std::cout << "Lname: " << lname << std::endl;
            // std::cout << "Gende: " << gender << std::endl;
            // std::cout << "Date:  " << dateStr << std::endl;
            // std::cout << "Code:  " << phone_code << std::endl;
            // std::cout << "Phone: " << phone << std::endl;
            // std::cout << "Email: " << email << std::endl;
            // std::cout << "Count: " << country << std::endl << std::endl << std::endl;

            date.setDate(dateStr);
            printDate(date);
            p.setAllData(fname, lname, gender, date);
            printPerson(p);
            contact.setAllData(p, phone_code, phone, email, country);
            bookAddr->insertContact(contact);

            // printContact(contact);
            std::cout << std::endl;
            // if(count++ == 9)
            //     exit(EXIT_SUCCESS);

        }
        read.close();
    }
    else{
        std::cout << ERROR_OPEN << filename << std::endl;
    }
}
