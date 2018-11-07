#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
}
Student::Student(string _IDCode, string _password, string _name)
{
    IDCode=_IDCode;
    password=_password;
    name=_name;
}

Student::~Student(){

}
