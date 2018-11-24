#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
}

Student::~Student(){

}
string Student::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "SIN_____________"<<IDCode<<endl;
    return s.str();
}
void Student::datasaving( ofstream &write){
   write<<name<<"\n";
   write<<IDCode<<"\n";
}

Student *Student::readTxt(ifstream &read){
    string _name,_IDCode;
    read>>_IDCode;
    read>>_name;
    return (new Student(_name, _IDCode));
}

void Student::ModifyUser(){}
