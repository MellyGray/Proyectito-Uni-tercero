#ifndef STUDENT_H
#define STUDENT_H
#include "listares.h"
#include <cstdlib> //To clean console
#include "user.h"

#include <iostream>
using namespace std;

class Student : public User
{
private:
    Listares *list;//Needed to modify users.


public:
    Student();
    Student(string _name, string _IDCode): User(_name,_IDCode){}
    Student(string _IDCode, string _password, string _name): User(_IDCode,_password,_name){}
    ~Student();
    void menu();
    void studentate();//Creates the acces to resources in order to modify courses
    //To print the atributes of the student
    string toString();

    //To save the atributes of the student on a text file
    void datasaving( ofstream &);


};

#endif // STUDENT_H
