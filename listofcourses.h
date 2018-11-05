#ifndef LISTOFCOURSES_H
#define LISTOFCOURSES_H
#include "list.h"
#include <iostream>
using namespace std;

class ListOfCourses : public List
{
public:
    ListOfCourses();
    void EnrollList();
    void DisplayList();
};

#endif // LISTOFCOURSES_H
