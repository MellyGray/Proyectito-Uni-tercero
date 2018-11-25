#ifndef VIRTUALCAMPUS_H
#define VIRTUALCAMPUS_H
#include "listusers.h"
#include "user.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class VirtualCampus{
private:
    ListUsers *list;
public:
    VirtualCampus();
    ~VirtualCampus();
    int start();

};

#endif // VIRTUALCAMPUS_H
