#include <iostream>
#include "virtualcampus.h"



using namespace std;

int main()
{         /*MILESTON 2. Please, when you run the application, if you want to end it, press every "EXIT" or "BACK" posible,
            otherwise the modifications performed during the program would not be saved in the txts. Thank you.*/

          VirtualCampus *vc=new VirtualCampus;
          vc->start();
          delete vc;


    return 0;
}
