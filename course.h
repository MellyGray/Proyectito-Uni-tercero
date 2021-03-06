#ifndef COURSE_H
#define COURSE_H
#include "resource.h"
#include <iostream>
using namespace std;

class Course : public Resource
{
private:
    int credits;
    string professor1id;
    string professor2id;
    string *marks;

public:
    //Constructors
    Course();
    Course(string _name, string _status, string _ID, int _num_users,int _credits,string _professor1id,string _professor2id,string _degree);
    ~Course();
    //Getters & setters
    int Getcredits(){return(credits);}
    void Setcredits(int _credits){credits=_credits;}
    string Getprofessor1id(){return(professor1id); }
    void Setprofessor1id(string _professor1id){professor1id=_professor1id;}
    string Getprofessor2id(){return(professor2id);}
    void Setprofessor2id(string _professor2id){professor2id=_professor2id;}
    string GetDegree(){return degree;}

    //To print the atributes of the resource
    string toString();

    string toStringList();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);

    //Display the mark of an specific student
        string ToStringMark(string _IDCode);

        string AllMarks(string _IDCode);


    //To read the data on a text file that corresponds to one resource
    Course *readTxt(ifstream &);

    //Modify the attributes of the course
    void ModifyResource();

    //Modify the marks of the course
    void ModifyMarks();

    //CHecks if in the list is the name of a user and if it is print the name of the course
    void searchinlist(string _id, int x);

   //Checks if it is posible to enroll
    int checking(string);
    //To introduce a user in the course
    void IntroduceUserinResource(string _id);
    //To clean a user form course
    void DeleteUserinResource(string _id);

    int onlyonefdp(string){return 0;}
};

#endif // COURSE_H
