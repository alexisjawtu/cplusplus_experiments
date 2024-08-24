#include <iostream>
#include "listaInt.h"

using namespace std;

int main()
{
    listaInt prueba;
    cout<<prueba.tam()<<endl;
    prueba.ag_adelante(1);
    cout<<prueba.tam()<<endl;
    prueba.ag_atras(3);
    cout<<prueba.tam()<<endl;
    listaInt prueba2;
    prueba2.ag_adelante(5);
    prueba.agregarle(prueba2);
    cout<<prueba.tam()<<endl<<prueba2.tam()<<endl;
    cout<<prueba.iesimo(1)<<endl;

    return 0;
}
