#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "user.h"

#include <iostream>
using namespace std;

class Professor : public User
{
private:


public:
    Professor();
    Professor (string _IDCode, string _password, string _name);
    ~Professor();


};

#endif // PROFESSOR_H
