#ifndef SEMINAR_H
#define SEMINAR_H
#include "resource.h"
#include "professor.h"
#include "date.h"
#include "listofstudents.h"
#include <iostream>
using namespace std;

class Seminar : public Resource
{
private:
    //ListOFIds *tutors;
    int maxSeats;
    Date *date;
    //ListOfIdS* listofidstudents;

public:
    Seminar();
    Seminar(string _name, string _status, string _ID,/* ListOFIds * _tutors,*/ int _maxSeats,Date *_date/*, ListOfIdS * _listofidstudents*/);
    ~Seminar();
    int GetmaxSEats();
    void SetmaxSeats(int _maxSeats);
    Date Getdate();
    void Setdate(Date *_date);
};

#endif // SEMINAR_H
