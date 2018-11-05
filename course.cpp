#include "course.h"
#include <iostream>
using namespace std;

Course::Course(string _name, string _status, string _ID,int _credits,string _profesorid,string _profesor2id,/*ListOfLectures *_ll,ListOfIds *_listofidstudents,ListOfMarks  *_listofmarks*/)
{
    name=_name;
    status=_status;
    credits=_credits;
    profesorid=_profesorid;
    profesor2id=_profesor2id;
   /* *ll=*_ll;
    *listofidstudents=*_listofidstudents;
    *listofmarks= *_listofmarks;*/
};
Course::~Course()
{
    name="";
    status="";
    credits=0;
    profesorid="";
    profesor2id="":
   }
int Course::Getcredits(){
    return(credits);
};
string Course::Getprofesorid(){
    return(profesorid);
};
string Course::Getprofesorid2(){
    return(profesor2id);
};
void Course::Setcredits(int _credits){
    credits=_credits;
};
void Course::Setprofesorid(string _profesorid){
    profesorid=_profesorid;
};
void Course::Setprofesorid2(string _profesor2id){
    profesor2id=_profesor2id;
};
