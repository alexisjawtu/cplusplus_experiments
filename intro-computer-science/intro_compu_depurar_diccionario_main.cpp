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
    //if(prueba.contieneclave(2) == true) {cout<<"cont 2"<<endl;}
    //if(prueba.contieneclave(1) == true) {cout<<"cont 1"<<endl;}
    //diccionario sigte;
    //sigte.definir(3,3);
    /*sigte.definir(4,4);
    prueba.unircon(sigte);
    cout<<prueba.cantclaves()<<endl;
    //if(prueba.contieneclave(4) == true) {cout<<"contiene 4"<<endl;}*/

    return 0;
}
