#ifndef READCMD_H_
#define READCMD_H_

#include <iostream>
#include "./../classes/contact.h"
#include "./../util/util.h"
#include "./../util/messages.h"

int readOption();
std::string readFname();
std::string readLname();
std::string readPhoneNumber();
std::string readEmail();
Contact readContact();

#endif