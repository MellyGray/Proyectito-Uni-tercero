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
    Seminar(string _name, string _status, string _ID, int _maxSeats):Resource (_name,_status,_ID) {maxSeats=_maxSeats;}
    ~Seminar();
    //Getters and setters
    int GetmaxSeats(){return(maxSeats);}
    void SetmaxSeats(int _maxSeats){maxSeats=_maxSeats;}
    Date Getdate(){return(*date);}
    void Setdate(Date *_date){date=_date;}

    //To display the date all together
    void DisplayDate();
    //To print the atributes of the resource
    string toString();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one resource
    Seminar *readTxt(ifstream &);

    //Modify the attributes of the seminar
    void ModifyResource();

};

#endif // SEMINAR_H
