#ifndef LISTARES_H
#define LISTARES_H
#include "nodores.h"
#include "course.h"
#include "fdp.h"
#include "seminar.h"
#include <iostream>
using namespace std;

//Class for the list of resources
class Listares
{
public:
    //Constructor and destructor
    Listares();
    ~Listares();
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
    void DeleteNodores(Nodores *,Nodores *);
    //Method to incrent the number of Courses on list
    void IncrementCour(){num_cour++;}
    //Method to incrent the number of FDPs on list
    void IncrementFDP(){num_fdp++;}
    //Method to incrent the number of Seminars on list
    void IncrementSeminar(){num_sem++;}
private:
    Nodores *actual;
    int num_cour; //Number of courses on list
    int num_fdp; //Number of fdps on list
    int num_sem; //Number of seminars on list
};

#endif // LISTARES_H
