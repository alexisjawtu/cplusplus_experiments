#include <iostream>
#include <string>
#include "estadistica.h"

using namespace std;

struct lluvia
    {
        string nombre;
        int cantidad;
        int* registros;
    };

int main()
{
    lluvia lluvias[100];
    int cant_registros = 0;
    int opcion = 0;

    while (opcion!=4)
    {
        cout<<"elija opción: "<<endl<<"1- Agregar registro de precipitaciones"<<endl<<"2- Borrar registro de precipitaciones"<<endl<<"3- Elegir registro de precipitaciones"<<endl<<"4- Salir"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            if (cant_registros == 100)
            {
                cout<<"Capacidad colmada. Elimine algún registro si quiere poner otro.";
            }
            if (cant_registros < 100)
            {

                cout<<"ingrese la cantidad de entradas"<<endl;

                cin>>lluvias[cant_registros].cantidad;

                cout<<"ingrese el nombre del registro"<<endl;

                getline(cin, lluvias[cant_registros].nombre);



                lluvias[cant_registros].registros=new int [lluvias[cant_registros].cantidad];

                for(int i=0;i<lluvias[cant_registros].cantidad;i++)
                {
                    cout<<"ingrese el dato "<<i+1<<":"<<endl;

                    cin>>(lluvias[cant_registros].registros)[i];
                }
                cant_registros++;
            }
        }
        if(opcion == 2)
        {
            int continuar=1;
            while(continuar==1)
                {
                    if(cant_registros < 1)
                    {
                        cout<<"no hay registros";
                    }
                    else
                    {
                        cout<<"elija alguno de los siguientes registros"<<endl;
                        int borrar;
                        for(int i=0;i<cant_registros;i++)
                        {
                            cout<<i+1<<"-"<<lluvias[i].nombre<<endl;
                        }
                        cout<<cant_registros<<" - cancelar"<<endl;

                        cin>>borrar;

                        if(borrar < cant_registros)
                        {
                    		for(int j=borrar-1; j<99; j++)
                            {
                                lluvias[j] = lluvias[j+1];
                    		}

                            cant_registros--;

                        }

                    }
                    cout<<endl<<"si desea borrar mas registros presione 1, si no presione 2"<<endl;
                    cin>>continuar;
                }
        }
        if(opcion == 3)
        {
            if(cant_registros < 1)
            {
                cout<<"no hay registros";
            }
            else
            {
                cout<<"elija alguno de los siguientes registros"<<endl;
                for(int i=0;i<cant_registros;i++)
                {
                    cout<<i+1<<" - "<<lluvias[i].nombre<<endl;
                }
                cout<<cant_registros + 1<<" - cancelar"<<endl;
                int elegir;
                cin>>elegir;
                if(elegir < cant_registros + 1)
                {
                    int funcion=0;
                    while(funcion<6)
                    {
                        cout<<"elegir alguna de las siguientes opciones:"<<endl;
                        cout<<"1 - Calcular media"<<endl;
                        cout<<"2 - Calcular mediana"<<endl;
                        cout<<"3 - Calcular moda"<<endl;
                        cout<<"4 - Calcular maximo"<<endl;
                        cout<<"5 - Calcular minimo"<<endl;
                        cout<<"6 - Salir"<<endl;
                        cin>>funcion;
                        if(funcion==1)
                        {
                            cout<<"media = "<<media(lluvias[elegir - 1].cantidad, lluvias[elegir - 1].registros)<<endl;
                        }
                        if(funcion==2)
                        {
                            cout<<"mediana = "<<mediana(lluvias[elegir - 1].cantidad, lluvias[elegir - 1].registros)<<endl;
                        }
                        if(funcion==3)
                        {
                            cout<<"moda = "<<moda(lluvias[elegir - 1].cantidad, lluvias[elegir - 1].registros)<<endl;
                        }
                        if(funcion==4)
                        {
                            cout<<"máximo = "<<fmax(lluvias[elegir-1].cantidad, lluvias[elegir-1].registros)<<endl;
                        }
                        if(funcion==5)
                        {
                            cout<<"mínimo = "<<fmin(lluvias[elegir-1].cantidad, lluvias[elegir-1].registros)<<endl;
		                }

                    }
                }


            }
        }
    }


    return 0;
}
