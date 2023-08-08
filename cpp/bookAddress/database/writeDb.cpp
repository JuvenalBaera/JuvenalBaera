#include "writeDb.h"

#include "../util/messages.h"

void writeToDatabase(std::vector<Contact> contacts, std::string filename){
    std::fstream writer;

    writer.open(filename, std::ios::out);

    if(writer.is_open()){
        for(Contact c: contacts){
            writer << c.getFirstName() << " " << c.getLastName() << " " 
                   << c.getPhone() << " " << c.getEmail() << "\n";
        }
        writer.close();
    }
    else{
        std::cout << ERROR_OPEN << filename << std::endl;
    }
}