#include <iostream>
#include "virtualcampus.h"


using namespace std;

int main()
{
    Administrator *admin= new Administrator;
               admin->administrate();
               delete admin;

    return 0;
}
