#include "fdp.h"
#include <iostream>
using namespace std;

FDP::FDP()
{
    name="";
    status="";
    ID="_ID";
    idstudent="_idstudent";
};
FDP::~FDP(){};
string FDP::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Student_________"<<idstudent<<endl;
    return s.str();
};
void FDP::datasaving( ofstream &write){
    write<<idstudent<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";


};
FDP *FDP::readTxt(ifstream &read){
    string _name, _status,_ID,_idstudent;
    read>>_idstudent;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new FDP(_name, _status,_ID,_idstudent));
};
void FDP::ModifyResource(){
    cout<<"Please, enter the new name for the FDP: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new status for the FDP: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the FDP: ";
    cin>>ID;
    cout<<"\n";
    cout<<"Please, enter the new student for the FDP: ";
    cin>>idstudent;
    cout<<"\n";
}
