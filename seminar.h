#ifndef SEMINAR_H
#define SEMINAR_H
#include "resource.h"
#include "date.h"
#include <iostream>
using namespace std;

class Seminar : public Resource
{
private:
    int maxSeats;
    Date date;

public:
    Seminar();
    Seminar(string _name, string _status, string _ID, int _maxSeats, Date _date);
    ~Seminar();
    int GetmaxSeats();
    void SetmaxSeats(int _maxSeats);
    Date Getdate();
    void Setdate(Date _date);
};

#endif // SEMINAR_H
