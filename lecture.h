#ifndef LECTURE_H
#define LECTURE_H
#include "date.h"
#include <iostream>
using namespace std;



class Lecture
{
private:
   string name;
   Date date;
public:
    Lecture();
    Lecture(string _name,Date _date);
};

#endif // LECTURE_H
