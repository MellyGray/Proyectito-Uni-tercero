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
    s<< "SIN______________"<<IDCode<<endl;
    return s.str();
};
void Student::datasaving( ofstream &write){
    write<<password<<"\n";
   write<<IDCode<<"\n";
   write<<name<<"\n";


};
Student *Student::readTxt(ifstream &read){
    string _name, _IDCode,_password;
    read>>_password;
    read>>_IDCode;
    read>>_name;
    return (new Student(_IDCode, _password,_name));
};

void Student::ModifyUser(){
    cout<<"Please, enter the new name for the student: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new SIN for the student: ";
    cin>>IDCode;
    cout<<"\n";
}

int Student::UserMenu(){
    system("cls");
    cout<<"------------------WELCOME "<<name<<" --------------------"<<endl;
    return 0;
}
