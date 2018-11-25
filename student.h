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
    Student(string _name, string _IDCode): User(_name,_IDCode){}
    Student(string _IDCode, string _password, string _name): User(_IDCode,_password,_name){}
    ~Student();
    //To print the atributes of the student
    string toString();

    //To save the atributes of the student on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one student
    Student *readTxt(ifstream &);

    //Modify the attributes of the student
    void ModifyUser();

    //Student Menu
    int UserMenu();
};

#endif // STUDENT_H
