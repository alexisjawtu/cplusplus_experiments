#include "listaInt.h"
#include <cstdlib>

struct NodoBi
{
    int valor;
    NodoBi* siguiente;
    NodoBi* anterior;
};

int listaInt::tam()const
{
    return this->cantidad;
}

int listaInt::iesimo(int i)const
{
    if(this->primero != NULL)
    {
        NodoBi* _iterador_ = this->primero;
        for(int j=0; j<i; j++)
        {
            _iterador_ = _iterador_->siguiente;
        }
        return _iterador_->valor;
    }
    return 0;
}

listaInt::listaInt()
{
    this->cantidad = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void listaInt::ag_adelante(int x)
{
    NodoBi* n = new NodoBi;
    n->valor = x;
    n->siguiente = this->primero;
    n->anterior = NULL;
    (this->primero)->anterior = n;
    this->primero = n;
    (this->cantidad)++;
}

void listaInt::ag_atras(int x)
{
    NodoBi* m = new NodoBi;
    m->valor = x;
    m->siguiente = NULL;
    m->anterior = this->ultimo;
    this->ultimo->siguiente = m;
    this->ultimo = m;
    (this->cantidad)++;
}

void listaInt::sin_primero()
{
    NodoBi* segundo = this->primero->siguiente;
    delete this->primero;
    this->primero = segundo;
    (this->cantidad)--;
}

void listaInt::sin_ultimo()
{
    NodoBi* anteultimo = this->ultimo->anterior;
    delete this->ultimo;
    this->ultimo = anteultimo;
    (this->cantidad)--;
}

void listaInt::agregarle(const listaInt l2)
{
    this->cantidad = this->cantidad + l2.cantidad;
    NodoBi* iterador_ = l2.primero;
    while(iterador_ != NULL)
    {
        (*this).ag_atras(iterador_->valor);
    }
}

listaInt listaInt::copiar()const
{
    listaInt l = *this;
    return l;
}

bool listaInt::iguales(const listaInt l2)
{
    if(this->tam() == l2.tam())
    {
        NodoBi* _this_ = this->primero;
        NodoBi* _l2_ = l2.primero;
        for(int j=0; j<this->tam(); j++)
        {
            if(_this_->valor != _l2_->valor)
            {
                return false;
            }
            _this_ = _this_->siguiente;
            _l2_ = _l2_->siguiente;
        }
        return true;
    }
    return false;
}

void listaInt::borrar_Lista()
{
    NodoBi* l = this -> primero;
    while(l != NULL)
    {
        NodoBi* sig = l->siguiente;
        delete l;
        l = sig;
    }
}

listaInt& listaInt::operator=(const listaInt& l)
{
    (*this).borrar_Lista();

    listaInt copia_al_reves;

	NodoBi* indicador_ = l.primero;

	while(indicador_ != NULL)
	{
		copia_al_reves.ag_adelante(indicador_ -> valor);
		indicador_ = indicador_ -> siguiente;
	}

	NodoBi* indicador = copia_al_reves.primero;
	while(indicador != NULL)
	{
		(*this).ag_adelante(indicador -> valor);
		indicador = indicador -> siguiente;
	}

	return *this;
}

listaInt::listaInt(const listaInt& l)
{
    this->cantidad = 0;
    this->primero = NULL;
    this->ultimo = NULL;
    *this = l;
}

listaInt::~listaInt()
{
    (*this).borrar_Lista();
}
