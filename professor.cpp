#include "professor.h"
#include <iostream>
using namespace std;

Professor::Professor():User(){
}
Professor::~Professor(){}

string Professor::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "SIN______________"<<IDCode<<endl;
    return s.str();
};
void Professor::datasaving( ofstream &write){
    write<<password<<"\n";
   write<<IDCode<<"\n";
   write<<name<<"\n";


};
Professor *Professor::readTxt(ifstream &read){
    string _name, _IDCode,_password;
    read>>_password;
    read>>_IDCode;
    read>>_name;
    return (new Professor(_IDCode, _password,_name));
};

void Professor::ModifyUser(){
    cout<<"Please, enter the new name for the professor: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new ID for the professor: ";
    cin>>IDCode;
    cout<<"\n";
}

int Professor::UserMenu(){
    system("cls");
    cout<<"------------------WELCOME "<<name<<" --------------------"<<endl;
    return 0;
}
