#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
}
Student::Student(string _IDCode, string _password, string _name): User(_IDCode,_password,_name)
{
}

Student::~Student(){

}
