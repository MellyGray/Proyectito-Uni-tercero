#include "lecture.h"

Lecture::Lecture()
{
name="";
}
Lecture::Lecture(string _name,Date _date){
    name=_name;
    date=_date;
}

Lecture::~Lecture(){};
string Lecture::Getname(){
    return(name);
};
void Lecture::Setname(string _name){
    name=_name;
};

Date Lecture::Getdate(){
    return(date);
};
void Lecture::Setdate(Date _date){
    date=_date;
};
