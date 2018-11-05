#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include <iostream>
#include "listares.h"
#include <cstdlib> //To clean console


using namespace std;

class Administrator : public User
{
public:
    Administrator();
    int  menu();
    void administrate();
private:
    Listares *list;
};

#endif // ADMINISTRATOR_H
