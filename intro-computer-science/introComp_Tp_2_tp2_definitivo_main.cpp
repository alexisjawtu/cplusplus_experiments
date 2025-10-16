#include <iostream>
#include "D:\tp2\estadistica.h"

using namespace std;


int main()
{
    int m=1;
    int reg[1000];
    for(int i=0;i<1000;i++)
    {
        reg[i]=0;
    }
    cout<<"¿cuantos registros va a ingresar? (como mucho puede ingresar 1000)"<<endl;
    cin>>m;
    cout<<"vaya ingresando los registros de a uno: "<<endl;
    for (int i=0; i<m; i=i+1)
    {
     cout<<"ingrese registro "<<i+1<<":"<<endl;
     cin>>reg[i];
    }
    cout<<"media = "<<media(m, reg)<<endl;
    cout<<"máximo = "<<fmax(m, reg)<<endl;
    cout<<"mínimo = "<<fmin(m, reg)<<endl;
    cout<<"mediana = "<<mediana(m, reg)<<endl;
    cout<<"moda = "<<moda(m, reg)<<endl;

    return 0;
}
