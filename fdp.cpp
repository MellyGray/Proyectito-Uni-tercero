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
FDP::FDP(string _name, string _status, string _ID, string _idstudent):Resource (_name,_status,_ID)
{
    idstudent=_idstudent;
};
FDP::~FDP(){};
string FDP::Getidstudent(){
    return(idstudent);
};
void FDP::Setidstudent(string _idstudent){
    idstudent=_idstudent;
};
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
