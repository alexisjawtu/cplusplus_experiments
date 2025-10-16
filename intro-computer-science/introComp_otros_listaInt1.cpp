#include "listaInt.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


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
    NodoBi* _iterador_ = this->primero;
    for(int j=0; j<i; j++)
    {
        _iterador_ = _iterador_->siguiente;
    }
    return _iterador_->valor;
}

listaInt::listaInt()
{
    this->cantidad = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void listaInt::ag_adelante(int x)
{
     NodoBi* _n = new NodoBi;
     _n->valor = x;
     _n->anterior = NULL;
     _n->siguiente = this->primero;
     if(this->cantidad == 0)
     {
          this->ultimo = _n;
     }
     else
     {
          (this->primero)->anterior = _n;
     }
     this->primero = _n;
     (this->cantidad)++;
}

void listaInt::ag_atras(int x)
{
    NodoBi* _n = new NodoBi;
    _n->valor = x;
    _n->siguiente = NULL;
    _n->anterior = this->ultimo;
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

void listaInt::sin_primero()
{
    if(this->cantidad == 1)
    {
        this->primero = NULL;
        this->ultimo = NULL;
        this->cantidad = 0;
    }
    else
    {
        NodoBi* segundo = this->primero->siguiente;
        delete this->primero;
        this->primero = segundo;
        (this->cantidad)--;
    }
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
        delete this->ultimo;
        this->ultimo = anteultimo;
        (this->cantidad)--;
    }
}

void listaInt::agregarle(const listaInt& l2)
{
    NodoBi* iterador_ = l2.primero;
    while(iterador_ != NULL)
    {
        this->ag_atras(iterador_->valor);
        iterador_ = iterador_->siguiente;
    }
}

bool listaInt::iguales(const listaInt& l2)
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

	NodoBi* indicador = l.primero;

	while(indicador != NULL)
	{
		(*this).ag_atras(indicador -> valor);
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

ostream & operator<<(ostream & f, const listaInt & l)
{
    NodoBi * indicador=l.primero;

    if(indicador!=NULL)
    {
        f << "["<<indicador->valor;
        indicador = indicador->siguiente;
    }

    while( indicador!=NULL )
    {
        f <<","<< indicador->valor;
        indicador=indicador->siguiente;
    }
    f<<"]";

    return f;
}


void f() {
  ofstream f("fonola.txt");//esto es como usarlo
  listaInt l;
  .....

  f << l << l2;

  ofstream f("fonola.txt");
  f << l;
  f.close();

  f << l2;


  operator<<(operator<<(f, l), ", ") << l << 5;
  (cout << l) << "hola";

  int i;
  (cin >> l) >> i;

}

[1,4,23]
75

istream & operator>>(istream & is, listaInt & l)//esta seria la otra sintaxis es parecido al<<

listaInt listaInt::leer()const
{
    ifstream infile;//con la otra sintaxis esta es la variable q is y hay q poner la funcion como friend
    infile.open("lista.txt");
    infile.get();
    char c=infile.peek();
    listaInt l;
    while( c!=']')
    {
        if((c >= '0') && (c <= '9'))
        {
            int valor=0;
            infile >> valor;//esto es lo que cambio

            while( (c >= '0') && (c <= '9'))//el while se puede sacar
            {
                int a=infile.get();
                valor=valor*10+a;
                c=infile.peek();
            }

            l.ag_atras(valor);
        }

        if(c==',')
        {
            infile.get();
        }
        c=infile.peek();

    }
    return l;
}


listaint l;
listaint l2 = listaint::leer()


int i =58;
cin >> i;  i = j;


[189,45,67,82]
>>
