#include "listaInt.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int listaInt::tam()const
{
    return this->cantidad;
}

NodoBi* listaInt::nodo_ultimo()const
{
    return this->ultimo;
}

listaInt::listaInt()
{
    this->cantidad = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void listaInt::ag_atras(vector < pair<int, int> > x, int ** s, int *** m)
{
    NodoBi* _n = new NodoBi;
    _n->lugares_vacios = x;  // (_n->lugares_vacios).push_back(make_pair(0, 0));
    _n->siguiente = NULL;
    _n->anterior = this->ultimo;
    int i,j,k;
	for(i=0 ; i<9 ; i++ )
    {
        for(j=0 ; j<9 ; j++ )
        {
            _n->sudoku_actual[i][j] = s[i][j];
        }
    }
    for(i=0 ; i<9 ; i++ )
    {
        for(j=0 ; j<9 ; j++ )
        {
            for(k=0 ; k<9 ; k++ )
            {
                _n->matriz_de_factibilidad[i][j][k] = m[i][j][k];
            }
        }
    }
    if(this->cantidad == 0)
    {
        this->primero = _n;
    }
    else
    {
        (this->ultimo)->siguiente = _n;
    }
    this->ultimo = _n;
    (this->cantidad)++;
}

void listaInt::sin_ultimo()
{
     if(this->cantidad == 1)
    {
        this->primero = NULL;
        this->ultimo = NULL;
        this->cantidad = 0;
    }
    else
    {
        NodoBi* anteultimo = this->ultimo->anterior;
		anteultimo->siguiente = NULL;
        delete this->ultimo;
        this->ultimo = anteultimo;
        (this->cantidad)--;
    }
}

/*void listaInt::borrar_Lista()
{
    NodoBi* l = this -> primero;
    while(l != NULL)
    {
        NodoBi* sig = l->siguiente;
        delete l;
        l = sig;
    }
}

listaInt::~listaInt()
{
    (*this).borrar_Lista();
}*/
