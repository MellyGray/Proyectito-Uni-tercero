#ifndef FDP_H
#define FDP_H
#include "resource.h"
#include <iostream>

using namespace std;

class FDP : public Resource
{
private:

public:
    FDP();
    FDP(string _name, string _status, string _ID);
    ~FDP();
};

#endif // FDP_H
