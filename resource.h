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
    //Getters & Setters
   string GetName();
   void SetName(string _name);
   string Getstatus();
   void SetStatus(string _status);
   string GetID();
   void SetID(string _ID);

   //To print the atributes of the resource
   string toString();

   //To save the atributes of the resource on a text file
   void datasaving( ofstream &);

   //To read the data on a text file that corresponds to one resource
   Resource *readTxt(ifstream &);
};

#endif // RESOURCE_H
