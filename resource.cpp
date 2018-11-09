#include "resource.h"
#include <iostream>

using namespace std;

Resource::Resource()
{
    name="";
    status="";
    ID="";
};
Resource::Resource(string _name, string _status, string _ID)
{
    name=_name;
    status=_status;
    ID=_ID;
};

Resource::~Resource(){}
void datasaving(){

}

string Resource::GetID(){
    return (ID);
};
string Resource::GetName(){
    return (name);
};
string Resource::Getstatus(){
    return(status);
};
void Resource::SetID(string _ID){
    ID=_ID;
};
void Resource::SetName(string _name){
    name=_name;
};
void Resource::SetStatus(string _status){
    status=_status;
};

string Resource::toString(){
    stringstream s;
    s<< "Name_______"<<name<<endl;
    s<< "Status_____"<< status<<endl;
    s<< "ID_________"<<ID<<endl;
    return s.str();
};
void Resource::datasaving( ofstream &write){
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";

};
Resource *Resource::readTxt(ifstream &read){
    string _name, _status,_ID;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new Resource(_name,_status,_ID));
};
