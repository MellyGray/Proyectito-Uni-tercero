#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

#include <iostream>
using namespace std;

class Student : public User
{
   private:

public:
    Student();
    Student(string _IDCode, string _password, string _name);
    ~Student();
};

#endif // STUDENT_H
