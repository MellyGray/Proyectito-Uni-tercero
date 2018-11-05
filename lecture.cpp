#include "lecture.h"

Lecture::Lecture()
{
name="";
};
Lecture::Lecture(string _name/*,ReadTxtString *_knowledge*/)
{
    name=_name;
    /*knowledge=*_knowledge;*/
};
Lecture::~Lecture(){};
string Lecture::Getname(){
    return(name);
};
void Lecture::Setname(string _name){
    name=_name;
};
