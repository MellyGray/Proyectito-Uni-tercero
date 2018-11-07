#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include <iostream>
#include "listares.h"
#include <cstdlib> //To clean console
using namespace std;

class Administrator : public User
{
private:
    Listares *list;
public:
    Administrator();
    Administrator(string _IDCode, string _password, string _name);
    ~Administrator();
    int  menu();
    void administrate();
};

#endif // ADMINISTRATOR_H
