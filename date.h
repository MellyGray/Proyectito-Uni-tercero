#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;


class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int _day, int _month, int _year);
    void SetDay(int _day);
    void SetMonth(int _month);
    void SetYear(int _year);
    int GetDay();
    int GetMonth();
    int GetYear();
    void DisplayDate();
    ~Date();
};

#endif // DATE_H
