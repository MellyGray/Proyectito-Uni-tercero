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

