#include "readDb.h"
#include "../util/messages.h"

void readFromDatabase(AddressBook *bookAddr,std::string filename){
    std::ifstream read;
    std::string line;
    Contact c;
    std::string fname, lname, phone, email;

    read.open(filename, std::ios::in);

    if(read.is_open()){
        while(read >> fname >> lname >> phone >> email){
            c.setAllData(fname, lname, phone, email);
            bookAddr->insertContact(c);
        }
        read.close();
    }
    else{
        std::cout << ERROR_OPEN << filename << std::endl;
    }
}
