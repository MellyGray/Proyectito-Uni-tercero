#ifndef VIRTUALCAMPUS_H
#define VIRTUALCAMPUS_H
#include "resource.h"
#include "listofresources.h"
#include "listofusers.h"
#include "user.h"
#include <iostream>
using namespace std;


class VirtualCampus
{
private:
    ListOfResources * LR;
    ListOfUsers * LU;
public:
    VirtualCampus();
    VirtualCampus(ListOfResources *_LR, ListOfUsers *_LU);
    ~VirtualCampus();
    void start();
};

#endif // VIRTUALCAMPUS_H
