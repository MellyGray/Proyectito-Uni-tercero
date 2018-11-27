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
    Seminar(string _name, string _status, string _ID,int _maxSeats):Resource (_name,_status,_ID){maxSeats=_maxSeats;}//Separar maxseats de constructor de info
    Seminar(string _name, int _num_users):Resource ( _name,_num_users){}
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

    //To print atributes list
    string toStringList();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);

    void datasavinglist( ofstream &);

    //To read the data on a text file that corresponds to one resource
    Seminar *readTxt(ifstream &);

    Seminar *readTXTlist(ifstream &);//Para lista

    //Modify the attributes of the seminar
    void ModifyResource();

    void searchinlist(string _id);

    bool checking();//Cheack if it is posible to enroll in seminar

};

#endif // SEMINAR_H
