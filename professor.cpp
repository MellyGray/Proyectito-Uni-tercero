#include "professor.h"
#include <iostream>
using namespace std;

Professor::Professor():User(){
}

Professor::Professor(string _IDCode, string _password, string _name) : User (IDCode, password, name)
{

}
Professor::~Professor(){}

