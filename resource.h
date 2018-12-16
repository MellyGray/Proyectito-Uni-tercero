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
    string degree;
    int num_users;
    string *lirray;

public:
    Resource();
    Resource(string _name, string _status, string _ID, int _num_users);
   virtual ~Resource();
    //Getters & Setters
   string GetName(){ return (name);}
   void SetName(string _name){name=_name;}
   string Getstatus(){return(status);}
   void SetStatus(string _status){status=_status;}
   string GetID(){return (ID);}
   void SetID(string _ID){ID=_ID;}
   virtual string GetDegree()=0;

   //Return element x on lirray
   string getlirrayvalue(int x);
   void Setlirrayvalue(int x, string s);

   //Introduce Id en la lista
   virtual void IntroduceUserinResource(string _id)=0;//Necesito hacerla virtual
//Borra usario de lista
   virtual void DeleteUserinResource(string _id)=0;

   //CHeck if it is possible to enroll
   virtual bool checking(string)=0;

   //Search in the list associated of users
   virtual void searchinlist(string _user, int x)=0;

   //To print the atributes of the resource
   virtual string toString()=0;

   //To print the atributes of the resource list
   virtual string toStringList()=0;

   //To print the marks of the courses
   virtual string ToStringMark(string _IDCode)=0;

   virtual string AllMarks(string _IDCode)=0;

   //To save the atributes of the resource on a text file
   virtual void datasaving( ofstream &)=0;


   //Modify the attributes of the resource
   virtual void ModifyResource()=0;

   //Modify the marks of the course
   virtual void ModifyMarks()=0;

};

#endif // RESOURCE_H
