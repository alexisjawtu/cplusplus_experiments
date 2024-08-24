#include <iostream>
#include "diccionario.h"
using namespace std;

int main()
{
    diccionario prueba;
    cout<<prueba.cantclaves()<<endl;
    prueba.definir(1,1);
    prueba.definir(2,2);
    cout<<prueba.cantclaves()<<endl;
    cout<<prueba.contieneclave(2)+prueba.contieneclave(1)<<endl;


    return 0;
}
