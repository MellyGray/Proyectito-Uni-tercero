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
    Date *date;

public:
    //Constructors
    Seminar();
    Seminar(string _name, string _status, string _ID, int _maxSeats, Date *_date);
    ~Seminar();
    //Getters and setters
    int GetmaxSeats();
    void SetmaxSeats(int _maxSeats);
    Date Getdate();
    void Setdate(Date *_date);
    //To display the date all together
    void DisplayDate();
};

#endif // SEMINAR_H
