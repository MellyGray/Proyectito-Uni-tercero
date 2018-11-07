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
    //ReadTxtString *knowledge;(Future upgrades)
public:
   Lecture();
   Lecture(string _name, Date _date/*,ReadTxtString *_knowledge*/);
      ~Lecture();
      void Setname(string _name);
      string Getname();
      void Setdate(Date _date);
      Date Getdate();
};

#endif // LECTURE_H
