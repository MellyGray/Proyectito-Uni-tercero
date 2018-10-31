#include "administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator(): User(){

}
Administrator::Administrator(string _IDCode, string _password, string _name) : User (IDCode,password,name)
{

}
