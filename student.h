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
    string degree;
    Listares *list;//Needed to modify users.

public:
    Student();
    Student(string _name, string _IDCode,string _degree): User(_name,_IDCode){degree=_degree;}
    Student(string _IDCode, string _password, string _name,string _degree): User(_IDCode,_password,_name){list=new Listares;degree=_degree;}
    ~Student();
    //To print the atributes of the student
    string toString();

    //To save the atributes of the student on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one student
    Student *readTxt(ifstream &);

    //Creates the acces to resources in order to modify courses
    int MainMenu();

    //Modify the attributes of the student
    void ModifyUser();

    //Student Menu
    int UserMenu();

};

#endif // STUDENT_H
