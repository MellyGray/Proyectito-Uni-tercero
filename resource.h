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
   virtual ~Resource();
    //Getters & Setters
   string GetName(){ return (name);}
   void SetName(string _name){name=_name;}
   string Getstatus(){return(status);}
   void SetStatus(string _status){status=_status;}
   string GetID(){return (ID);}
   void SetID(string _ID){ID=_ID;}


   //To print the atributes of the resource
   virtual string toString()=0;

   //To save the atributes of the resource on a text file
   virtual void datasaving( ofstream &)=0;
   //Modify the attributes of the resource
   virtual void ModifyResource()=0;

};

#endif // RESOURCE_H
