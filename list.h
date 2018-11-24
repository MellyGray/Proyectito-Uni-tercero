#ifndef LIST_H
#define LIST_H
#include "nodo.h"
#include "course.h"
#include "fdp.h"
#include "seminar.h"
#include <iostream>
using namespace std;

//Class for the list of resources
class List
{
public:
    //Constructor and destructor
    List();
    ~List();
    //Method to add a new object resource to the list
    void selectresource(Resource *);
    //Method to display the list
    string toString();
    //Method to keep a resource on the text file
    void keepresource();
    //Method to charge the resources on the text file
    void chargeresource();
    //Method to search for a resource on a list, typing the ID
    Resource *ResourcesOnList(string);
    //Method to delete an object from the list
    Resource *DeleteResource(string);
    //Method to delete a node from the list
    void DeleteNodores(Nodo *,Nodo *);
    //Method to insert a new element to the list on a selected position
    void InsertNodeSelPosition(Resource *,int position);
    //Gettes & Setters
    int GetNum_cour(){return(num_cour);}
    int GetNum_fdp(){return(num_fdp);}
    int GetNum_sem(){return(num_sem);}
    void SetNum_cour(int _num_cour){num_cour=_num_cour;}
    void SetNum_fdp(int _num_fdp){num_fdp=_num_fdp;}
    void SetNum_sem(int _num_sem){num_sem=_num_sem;}

private:
    Nodo *actual;
    int num_cour; //Number of courses on list
    int num_fdp; //Number of fdps on list
    int num_sem; //Number of seminars on list
};

#endif // LIST_H
