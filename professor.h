#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "user.h"
#include "listofcourses.h"
#include "listofseminars.h"
#include "listoffdps.h"
#include <iostream>
using namespace std;

class Professor : public User
{
private:
    ListOfCourses *LC;//Only tutors and speakers can modify their resources, cotutors and coordinators do nothing, they are only showed as info
    ListOfSeminars *LS;
    ListOfFDPs *LF;

public:
    Professor();
    Professor(string _IDCode, string _password, string _name, ListOfCourses *_LC,ListOfSeminars *_LS, ListOfFDPs *_LF);
    Professor (string _IDCode, string _password, string _name);
    ~Professor();

};

#endif // PROFESSOR_H
