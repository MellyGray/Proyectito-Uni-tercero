#include "fdp.h"
#include <iostream>
using namespace std;

FDP::FDP()
{
    name="-";
    status="-";
    ID="_ID";
    idstudent="_idstudent";
    degree="_";
    nametutor="-";
    idcotutor="-";
}
FDP::~FDP(){};
string FDP::toString(){
    stringstream s;
    s<< "FDP_____________"<<name<<endl;
    s<< "Degree__________"<<degree<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "Student ID______"<<idstudent<<endl;
    s<< "Tutor ID________"<<nametutor<<endl;
    s<< "Co-tutor ID_____"<<idcotutor<<endl;
    return s.str();
}
string FDP::toStringList(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Degree__________"<<degree<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Student ID______"<<idstudent<<endl;
    s<< "Tutor ID________"<<nametutor<<endl;
    s<< "Co-tutor ID_____"<<idcotutor<<endl;
    return s.str();
}
void FDP::datasaving( ofstream &write){
   write<<degree<<"\n";
   write<<idcotutor<<"\n";
   write<<nametutor<<"\n";
   write<<idstudent<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";

}

FDP *FDP::readTxt(ifstream &read){
    string _name, _status,_ID,_idstudent,_nametutor,_degree,_idcotutor;
    int _num_users=0;
    read>>_degree;
    read>>_idcotutor;
    read>>_nametutor;
    read>>_idstudent;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new FDP(_name, _status,_ID,_num_users,_idstudent,_nametutor,_degree,_idcotutor));
}

void FDP::ModifyResource(){
    char a;
    cout<<"Please, enter the new name for the FDP: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new degree for the FDP: ";
    cin>>degree;
    cout<<"\n";
    cout<<"Please, enter the new status for the FDP: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the tutor of the FDP: ";
    cin>>ID;
    cout<<"\n";
    cout<<"Do you want to assig a cotutor to this FDP? (Y/N)"<<endl;
    cin>>a;
    if(a==('y'|'Y')){
        cout<<"Please, enter the new cotutor ID for the FDP: ";
        cin>>idcotutor;
        cout<<"\n";
        }
    cout<<"Do you want to assig a new student to this FDP? (Y/N)"<<endl;
    cin>>a;
    if(a==('y'|'Y')){
        cout<<"Please, enter the new student ID for the FDP: ";
        cin>>idstudent;
        cout<<"\n";
        }
}
void FDP::searchinlist(string _id){
        if ((idstudent==_id)||(nametutor==_id)){
            cout<<"FDP__________"<<name<<endl;
            cout<<"ID___________"<<ID<<endl;
            cout<<"\n";
        }
    }
bool FDP::checking(){
    if(idstudent=="NONE"){
        return true;
    }else
        cout<<"This FDP is assigned to another student"<<endl;
        return false;
}
