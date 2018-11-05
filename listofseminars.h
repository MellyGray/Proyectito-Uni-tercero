#ifndef LISTOFSEMINARS_H
#define LISTOFSEMINARS_H
#include "list.h"
#include <iostream>
using namespace std;

class ListOfSeminars : public List
{
public:
    ListOfSeminars();
    void EnrollList();
    void DisplayList();
};

#endif // LISTOFSEMINARS_H
