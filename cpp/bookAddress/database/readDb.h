#ifndef READDB_H_
#define READDB_H_

#include <iostream>
#include <fstream>

#include "../classes/addressbook.h"
#include "../classes/contact.h"

void readFromDatabase(AddressBook *bookAddr, std::string filename);


#endif