#ifndef COURSE_H
#define COURSE_H
#include "resource.h"
#include "professor.h"
#include "lecture.h"
#include "listofstudents.h"
#include "listofmarks.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Course : public Resource
{
private:
    int credits;
    string profesorid;  //relation between objects with no objects
    string profesor2id;
    //ListOfLectures *ll; //List of objects
   // ListOfIDs *listofidstudents;///MIrar si se hace con clases o simples listas
   // ListOfMarks *listofmarks;


public:
    Course();
    Course(string _name, string _status, string _ID,int _credits,string _profesorid,string _profesor2id /*,ListOfLectures *_ll,ListOfIds *_listofidstudents,ListOfMarks *_listofmarks*/);
//Basic parameters to create a course. Can be completed between object interactions
    ~Course();
    int Getcredits();
    void Setcredits(int _creedits);
    string Getprofesorid();
    void Setprofesorid(string _profesorid);
    string Getprofesorid2();
    void Setprofesorid2(string _profesorid2);
    //ListOfLectures Getll();
    //void Setll(ListOfLectures *_ll);
    //ListOfIDs Getlistofidstudents();
    //void Setlistofidstudents(ListOfIDs *_listofidstudents);
    //ListOfMarks Getlistofmarks();
    //void Setlistofmarks(ListOfMarks *_listofmarks);
};

#endif // COURSE_H
