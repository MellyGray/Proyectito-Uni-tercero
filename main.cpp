#include <iostream>
#include "virtualcampus.h"



using namespace std;

int main()
{

          VirtualCampus *vc=new VirtualCampus;
          vc->start();
          delete vc;


    return 0;
}
