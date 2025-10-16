#include <iostream>
#include "listaInt.h"
#include "diccionario.h"
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    diccionario cv;
    cv.definir(0,0);
    ifstream h("cv.txt");
    h>>cv;
    diccionario ta;
    ta.definir(0,0);
    ifstream i("ta.txt");
    i>>ta;
    diccionario tc;
    tc.definir(0,0);
    ifstream j("tc.txt");
    j>>tc;
    diccionario ip;
    ip.definir(0,0);
    ifstream k("ip.txt");
    k>>ip;
    diccionario mt;
    mt.definir(0,0);
    ifstream l("mt.txt");
    l>>mt;
    diccionario tmx;
    tmx.definir(0,0);
    ifstream m("tmx.txt");
    m>>tmx;*/
    diccionario reg;
    for (int i = 1; i < 709; i++)
    {
        int etiqueta_i = 32*(cv.contieneclave(i)) + 16*(ta.contieneclave(i)) + 8*(ip.contieneclave(i)) + 4*(mt.contieneclave(i)) + 2*(tc.contieneclave(i)) + 1*(tmx.contieneclave(i));
        reg.definir(i, etiqueta_i);
    }

    vector < pair<int , int > > A;
    int long_ = (reg.claves()).tam();
    for(int i=0; i < long_; i++)
    {
        A.push_back(make_pair((reg.valores()).iesimo(i),(reg.claves()).iesimo(i)));
    }
    sort(A.begin(),A.end());
    ofstream regiones;
    regiones.open("regiones.txt");
    //cout<<endl<<reg<<endl;
    for(int i=0; i < long_; i++)
    {
        cout<<A[i].first<<", ";
        cout<<A[i].second<<"; ";
        regiones<<A[i].first<<", ";
        regiones<<A[i].second<<endl;
    }
    regiones.close();
    cout<<endl;
    /*for (int i = 2; i < 709; i++)
    {
        cv.definir(i,1);
    }
    ofstream h;
    h.open("cv.txt");
    h<<cv;
    h.close();*/

    return 0;

}
