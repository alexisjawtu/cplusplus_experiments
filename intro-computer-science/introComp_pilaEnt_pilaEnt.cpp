#include "pilaEnt.h"
#include <cstdlib>

struct Nodo
{
    int valor;
    Nodo* siguiente;
};

int pilaEnt::tam()const
{
    return this->cantidad;
}

pilaEnt::pilaEnt()
{
    this->cantidad = 0;
    this->primero = NULL;
}

int pilaEnt::tope()const
{
    return(*(this->primero)).valor;
}

void pilaEnt::apilar(int x)
{
    Nodo* n = new Nodo;
    n->valor = x;
    n->siguiente = this->primero;
    this->primero = n;
    (this->cantidad)++;
}

void pilaEnt::desapilar()
{
    Nodo* segundo = this->primero->siguiente;
    delete this->primero;
    this->primero = segundo;
    this->cantidad--;
}

pilaEnt pilaEnt::copiarPila()const
{
    pilaEnt copia;
	pilaEnt copia_al_reves;

	Nodo* indicador_ = this -> primero;

	while(indicador_ != NULL)
	{
		copia_al_reves.apilar(indicador_ -> valor);
		indicador_ = indicador_ -> siguiente;
	}

	Nodo* indicador = copia_al_reves.primero;
	while(indicador != NULL)
	{
		copia.apilar(indicador -> valor);
		indicador = indicador -> siguiente;
	}

	return copia;

}

pilaEnt::pilaEnt(const pilaEnt& p)
{
	*this = p.copiarPila();
}
