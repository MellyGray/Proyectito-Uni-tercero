#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include <iostream>
using namespace std;

class Administrator : public User
{
private:
public:
    Administrator();
    Administrator(string _IDCode, string _password, string _name);
    ~Administrator();
};

#endif // ADMINISTRATOR_H
