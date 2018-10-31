#ifndef COURSE_H
#define COURSE_H
#include "resource.h"
#include <iostream>
using namespace std;

class Course : public Resource
{
private:
    int credits;

public:
    Course();
    Course(string _name, string _status, string _ID,int _credits);
    ~Course();
};

#endif // COURSE_H
