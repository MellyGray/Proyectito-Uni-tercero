#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
}
Student::Student(string _IDCode, string _password, string _name) : User(IDCode, password, name)
{
}

Student::~Student(){

}
