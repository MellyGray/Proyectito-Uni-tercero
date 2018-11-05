#ifndef LISTOFSTUDENTS_H
#define LISTOFSTUDENTS_H
#include "list.h"
#include <iostream>
using namespace std;
//This function gets the relation betwwen and object student and an object resources by saving 1 atribute exclusive of 1 object student
class ListOfStudents : public List
{
public:
    ListOfStudents();
    void EnrollList();
    void DisplayList();
};

#endif // LISTOFSTUDENTS_H
