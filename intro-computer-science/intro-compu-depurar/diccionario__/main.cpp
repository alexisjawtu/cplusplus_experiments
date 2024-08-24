#include <iostream>
#include "diccionario.h"
using namespace std;

int main()
{
    diccionario prueba;
    //cout<<prueba.cantclaves()<<endl;
    prueba.definir(1,2);
    //cout<<prueba.buscarvalor(1)<<endl;
    diccionario prueba2;
    prueba.definir(1,3);
    prueba2.definir(3,4);
    prueba.definir(2,4);
    prueba.definir(5,4);
    prueba.definir(7,8);
    //prueba.indefinir(1);
    prueba.unircon(prueba2);
    //out<<prueba.buscarvalor(1)<<endl;
    //cout<<prueba.buscarvalor(1)<<endl;
    //prueba.definir(2,2);
    //prueba.indefinir(2);
    //if((prueba.contieneclave(2))==0)
    //{
      //  cout<<"si"<<endl;
    //}
   //prueba.indefinir(1);
    cout<<prueba.cantclaves()<<endl;
    cout<<prueba.cantclaves()<<endl;
    cout<<prueba.contieneclave(3)<<endl;
    cout<<prueba.buscarvalor(2)<<endl;
    cout<<prueba.buscarvalor(5)<<endl;
    cout<<prueba.buscarvalor(7)<<endl;
    cout<<prueba.buscarvalor(3)<<endl;
    cout<<prueba.buscarvalor(1)<<endl;
    cout<<prueba.contieneclave(1)<<endl;
    //prueba.indefinir(2);
    /*cout<<prueba.cantclaves()<<endl;
    cout<<prueba.cantclaves()<<endl;
    cout<<prueba.contieneclave(3)<<endl;
    cout<<prueba.buscarvalor(2)<<endl;
    cout<<prueba.buscarvalor(5)<<endl;
    cout<<prueba.buscarvalor(7)<<endl;
    cout<<prueba.buscarvalor(3)<<endl;
    cout<<prueba.buscarvalor(1)<<endl;
*/
    //diccionario prueba;
    //cout<<prueba.cantclaves()<<endl;
    //prueba.definir(1,1);
    //prueba.definir(2,2);
    //cout<<prueba.cantclaves()<<endl;
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
