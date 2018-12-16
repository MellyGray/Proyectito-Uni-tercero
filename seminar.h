#ifndef SEMINAR_H
#define SEMINAR_H
#include "resource.h"
#include <iostream>
using namespace std;

class Seminar : public Resource
{
private:
    int maxSeats;
    string date;
    string SpeakerID;
    string coordinator;

public:
    //Constructors
    Seminar();
    //NUEVO
    Seminar(string _name, string _status, string _ID,int _num_users, int _maxSeats, string _SpeakerID, string _coordinator, string _date);

    ~Seminar();
    //Getters and setters
    int GetmaxSeats(){return(maxSeats);}
    void SetmaxSeats(int _maxSeats){maxSeats=_maxSeats;}
    string Getdate(){return(date);}
    void Setdate(string _date){date=_date;}
    string GetSpeaker(){return(SpeakerID);}
    void SetSpeaker(string _SpeakerID){SpeakerID=_SpeakerID;}
    string GetDegree(){return ("NONE");}

    //To display the date all together
    void DisplayDate();
    //To print the atributes of the resource
    string toString();

    //To print atributes list
    string toStringList();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one resource
    Seminar *readTxt(ifstream &);

    //Modify the attributes of the seminar
    void ModifyResource();

    void searchinlist(string _id, int x);

    bool checking(string);//Cheack if it is posible to enroll in seminar

};

#endif // SEMINAR_H
