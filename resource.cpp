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
void datasaving(){

}
void Resource::datasaving( ofstream &writte){//Aqui hay que defeinfir un txt en donde se llame esta función
   writte<<ID<<"\n";
   writte<<status<<"\n";
   writte<<name<<"\n";

};
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
    s<< "ID_______"<< ID<<endl;
    s<< "Status---"<< status<<endl;
    s<<"Name------"<< name<<endl;
    return s.str();
};
Resource *Resource::readTxt(istream &read){
    string _name, _status,_ID;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new Resource(_name,_status,_ID));//CAMBIAR ORDEN PARAMETROS DE STATUS ID Y TAL
};

