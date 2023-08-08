#ifndef WRITEDB_H_
#define WRITEDB_H_

#include <iostream>
#include <fstream>

#include "../classes/addressbook.h"
#include "../classes/contact.h"

void writeToDatabase(std::vector<Contact> contacts, std::string filename);

#endif