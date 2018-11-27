#include "resource.h"
#include <iostream>

using namespace std;

Resource::Resource()
{
    name="";
    status="";
    ID="";
};
Resource::Resource(string _name, string _status, string _ID)
{
    name=_name;
    status=_status;
    ID=_ID;
};

Resource::~Resource(){}


