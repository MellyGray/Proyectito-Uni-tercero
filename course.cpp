#include "course.h"
#include <iostream>
using namespace std;

Course::Course(){}

Course::Course(string _name, string _status, string _ID,int _credits,string _professor1id,string _professor2id):Resource (_name,_status,_ID)
{
    credits=_credits;
    professor1id=_professor1id;
    professor2id=_professor2id;
};

Course::~Course()
{
    name="";
    status="";
    credits=0;
    professor1id="";
    professor2id="";
   }
int Course::Getcredits(){
    return(credits);
};
string Course::Getprofessor1id(){
    return(professor1id);
};
string Course::Getprofessor2id(){
    return(professor2id);
};
void Course::Setcredits(int _credits){
    credits=_credits;
};
void Course::Setprofessor1id(string _professor1id){
    professor1id=_professor1id;
};
void Course::Setprofessor2id(string _professor2id){
    professor2id=_professor2id;
};
string Course::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Credits_________"<<credits<<endl;
    s<< "Professor 1 ID__"<<professor1id<<endl;
    s<< "Professor 2 ID__"<<professor2id<<endl;
    return s.str();
};
void Course::datasaving( ofstream &write){
    write<<professor2id<<"\n";
    write<<professor1id<<"\n";
    write<<credits<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";


};
Course *Course::readTxt(ifstream &read){
    string _name, _status,_ID,_professor1id,_professor2id;
    int _credits;
    read>>_professor2id;
    read>>_professor1id;
    read>>_credits;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new Course(_name, _status,_ID,_credits,_professor1id,_professor2id));
};

void Course::ModifyResource(){
    cout<<"Please, enter the new name for the course: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new status for the course: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the course: ";
    cin>>ID;
    cout<<"\n";
    cout<<"Please, enter the new number of credits for the course: ";
    cin>>credits;
    cout<<"\n";
    cout<<"Please, enter the new proffesor 1 for the course: ";
    cin>>professor1id;
    cout<<"\n";
    cout<<"Please, enter the new proffesor 2 for the course: ";
    cin>>professor2id;
    cout<<"\n";
}
