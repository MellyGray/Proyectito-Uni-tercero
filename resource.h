#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Resource
{
    protected:
    string name;
    string status;
    string ID;

public:
    Resource();
    Resource(string _name, string _status, string _ID);
    ~Resource();
   string GetName();
   void SetName(string _name);
   string Getstatus();
   void SetStatus(string _status);
   string GetID();
   void SetID(string _ID);
   string toString();
   void datasaving( ofstream &);
   Resource *readTxt(istream &);
};

#endif // RESOURCE_H
