#include "writeDb.h"

#include "../util/messages.h"

void writeToDatabase(std::vector<Contact> contacts, std::string filename){
    std::fstream writer;

    writer.open(filename, std::ios::out);

    if(writer.is_open()){
        for(Contact c: contacts){
            writer << c.getPerson().getFirstName() << "\t" << c.getPerson().getLastName() << "\t" 
                   << c.getPhoneNumber() << "\t" << c.getEmail() << "\n";
        }
        writer.close();
    }
    else{
        std::cout << ERROR_OPEN << filename << std::endl;
    }
}