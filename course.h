#ifndef COURSE_H
#define COURSE_H
#include "resource.h"
#include <iostream>
using namespace std;

class Course : public Resource
{
private:
    int credits;
    string professor1id;  //relation between objects with no objects
    string professor2id;

public:
    Course();
    Course(string _name, string _status, string _ID,int _credits,string _professor1id,string _professor2id);
    ~Course();
    int Getcredits();
    void Setcredits(int _creedits);
    string Getprofessor1id();
    void Setprofessor1id(string _professor1id);
    string Getprofessor2id();
    void Setprofessor2id(string _professor2id);
};

#endif // COURSE_H
