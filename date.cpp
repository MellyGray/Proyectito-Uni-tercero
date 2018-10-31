#include "date.h"

Date::Date()
{
    day=0;
    month=0;
    year=0;

}

Date::Date(int _day, int _month, int _year){
    day=_day;
    month=_month;
    year=_year;
}
Date::~Date(){

}

void Date::SetDay(int _day){
    day=_day;
}
void Date::SetMonth(int _month){
    month=_month;
}
void Date::SetYear(int _year){
    year=_year;
}
int Date::GetDay(){
    return (day);
}
int Date::GetMonth(){
    return (month);
}
int Date::GetYear(){
    return (year);
}
