#include <cstdlib>
#include <iostream>

using namespace std;



double media(int v[], int n)
{
       int i=0;
       int suma=0;
       while (i<n)
       {
             suma=suma+v[i];
             i++;
             }
       double p= (double)p/n;
       return p;
}

int fmax(int n, int v[])
{
       int i=0;
       int maximo=v[0];
       while (i<n)
       {
       if (maximo<v[i]){
                        maximo=v[i];
                        }
       i++;
       }
       return maximo;
       }

int fmin(int n, int v[])
{
       int k=1;
       int minimo=v[0];
       while (k<n)
       {
             if (minimo>v[k])
             {
                             minimo=v[k];
             }
             k++;
       }
       return minimo;
       }

int main()
{
    int m=1;
    int reg[1000];
    for(int i=0;i<1000;i++)
    {
        reg[i]=0;
    }
    cout<<"¿cuantos registros va a ingresar?(como mucho puede ingresar 1000"<<endl;
    cin>>m;
    cout<<"vaya ingresando los registros de a uno: "<<endl;
    for (int i=0; i<m; i=i+1)
    {
     cout<<"ingrese registro "<<i+1<<":"<<endl;
     cin>>reg[i];
    }
    cout<<"media = "<<media(reg, m)<<endl;
    cout<<"máximo = "<<fmax(m, reg)<<endl;
    cout<<"mínimo = "<<fmin(m, reg)<<endl;
    system("PAUSE");
    return 0;
}
