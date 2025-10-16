#include <iostream>
#include "pilaEnt.h"

using namespace std;



int main()
{
    pilaEnt prueba;
    prueba.apilar(3);
    cout<<prueba.tope();
    prueba.desapilar();


    return 0;
}
