#ifndef LISTOFMARKS_H
#define LISTOFMARKS_H
#include "list.h"
#include <iostream>
using namespace std;

class ListOfMarks : public List
{
public:
    ListOfMarks();
    void EnrollList();
    void DisplayList();
};

#endif // LISTOFMARKS_H
