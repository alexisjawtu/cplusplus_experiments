#ifndef _LISTAINT_H_
#define _LISTAINT_H_

#include <iostream>
//#include <fstream>
#include <vector>
using namespace std;

struct NodoBi
{
    vector < pair <int, int> > lugares_vacios;
    int ** sudoku_actual;
    int *** matriz_de_factibilidad;
    NodoBi* siguiente;
    NodoBi* anterior;
};

class listaInt
{
    public:

    int tam()const;
    NodoBi* nodo_ultimo()const;
    listaInt();
    //void ag_adelante(int x);
    void ag_atras(vector< pair<int, int> > x, int ** s, int *** m);
    //void sin_primero();
    void sin_ultimo();
    //void agregarle(const listaInt& l2);
    //listaInt copiar()const;
    //bool iguales(const listaInt& l2);
    //void borrar_Lista();
    //listaInt& operator=(const listaInt& l);
    //listaInt(const listaInt& l);
    //~listaInt();
    //friend ostream& operator<<(ostream& f,const listaInt& l);
    //friend istream& operator>>(istream& is, listaInt& l);

    private:

    int cantidad;
    NodoBi* primero;
    NodoBi* ultimo;

};

#endif
