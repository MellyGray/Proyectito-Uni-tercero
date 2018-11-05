#ifndef LECTURE_H
#define LECTURE_H
#include <iostream>
using namespace std;

class Lecture
{
private:
    string name;
    //ReadTxtString *knowledge;(Future upgrades)
public:
    Lecture();
    Lecture(string _name/*,ReadTxtString *_knowledge*/);
    ~Lecture();
    void Setname(string _name);
    string Getname();
};

#endif // LECTURE_H
