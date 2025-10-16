#include <iostream>
#include "listaInt.h"
#include "diccionario.h"
using namespace std;
#include <fstream>

int main()
{
    diccionario d;
    //d.definir(2,3);
    //d.definir(34,2);
    //d.definir(99,4);
    ifstream f;
    f.open("diccionario.txt");
    diccionario d2;
    f>>d;
    //cin>>d;
    cout<<d.contieneclave(7)<<endl;
    cout<<d.buscarvalor(7)<<endl;
    //cout<<d;
    //f<<d;
    listaInt l;
    l.ag_atras(8);
    l.ag_atras(89);
    //cout<<l;
    ofstream r("hola.txt");
    ifstream j;
    j.open("lista.txt");
    j>>l;
    //r<<d<<l;
    cout<<l.iesimo(3)<<endl;
    f.close();
    r.close();

}
