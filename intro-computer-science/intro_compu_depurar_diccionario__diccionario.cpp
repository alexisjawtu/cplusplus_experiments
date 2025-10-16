#include "F:\listaInt.h"
#include "diccionario.h"
#include <cstdlib>


/*void diccionarios::operator<<(ostream & stream) {
    stream << .-...
    for int i ... stream << ...
}

void f () {
    diccionario d;
    ...
    cout << d;

    ofstream arch1("hola.txt");
    arch1 << d; (d.mostrar(arch1);)
    arch1.close();

    cin istream ifstream



}

[(4,3), (2,24)*/

struct NodoABBD
{
    int clave;
    int valor;
    NodoABBD* derecho;
    NodoABBD* izquierdo;
};

diccionario::diccionario()
{
    this->cantidad=0;
    this->arbol=NULL;
}
bool diccionario::contieneclave_aux(const NodoABBD* raiz,clave k)const
{
    if ( raiz==NULL)
    {
        return false;
    }
    else if( (raiz->clave) == k)
    {
        return true;
    }
    else if( (raiz->clave) < k)
    {
        return this->contieneclave_aux(raiz->derecho,k);
    }
    else
    {
        return this->contieneclave_aux(raiz->izquierdo,k);
    }
}

bool diccionario::contieneclave(clave k)const
{
    return this->contieneclave_aux( this->arbol , k );

}

valor diccionario::buscarvalor_aux(const NodoABBD* raiz,clave k)const
{
     if(raiz!=NULL)
     {
        if ( (raiz->clave) == k)
        {
            return raiz->valor;
        }
        else
        {
            if( (raiz->clave) < k)
            {
                return buscarvalor_aux(raiz->derecho,k);
            }
            else
            {
                return buscarvalor_aux(raiz->izquierdo,k);
            }
        }
     }
}

valor diccionario::buscarvalor(clave k)const
{
   return buscarvalor_aux(this->arbol,k);
}

NodoABBD* diccionario::definir_aux(NodoABBD* raiz,clave k, valor v)
{
     if(raiz == NULL)
    {
        raiz=new NodoABBD ;
        raiz->clave = k;
        raiz->valor = v;
        raiz->izquierdo = NULL;
        raiz->derecho = NULL;
        (this->cantidad)++;
    }
    else if( (raiz->clave)< k )
    {
       raiz->derecho=definir_aux(raiz->derecho,k,v);
    }
    else if( (raiz->clave) > k)
    {
        raiz->izquierdo=definir_aux(raiz->izquierdo,k,v);
    }
    else
    {
        raiz->valor=v;
    }
    return raiz;
}

void diccionario::definir(clave k, valor v)
{
  /* if( (this->contieneclave(k)) == 0 )
   {
       (this->cantidad)++;
   }*/
   this->arbol=definir_aux(this->arbol,k,v);
   return;
}

NodoABBD* diccionario::indefinir_aux(NodoABBD* raiz,clave k)
{
    if( raiz!=NULL )
    {
        if(contieneclave_aux(raiz,k) == 1 )
        {
            if( raiz->clave < k )
            {
               raiz->derecho=indefinir_aux(raiz->derecho,k);
            }
            else if( raiz->clave > k )
            {
                raiz->izquierdo=indefinir_aux(raiz->izquierdo,k);
            }
            else
            {
                if( raiz->derecho==NULL)
                {
                    NodoABBD* nodo_a_extraer = raiz;
                    raiz = raiz->izquierdo;
                    nodo_a_extraer->izquierdo = NULL;
                    delete nodo_a_extraer;
                    (this->cantidad)--;
                }

                else
                {
                    NodoABBD* nodominimo=raiz->derecho;
                    while( nodominimo->izquierdo!=NULL)
                    {
                        nodominimo=nodominimo->izquierdo;
                    }
                    NodoABBD* nodo_aux=raiz;
                    NodoABBD* derecha=raiz->derecho;
                    NodoABBD* izquierda=raiz->izquierdo;
                    raiz=nodominimo;

                    nodo_aux->derecho = NULL;
                    nodo_aux->izquierdo = NULL;
                    delete nodo_aux;

                    raiz->derecho=indefinir_aux(derecha,nodominimo->clave);
                    raiz->izquierdo=izquierda;

                }
            }
        }
    }

    return raiz;
}



void diccionario::indefinir(clave k)
{
    /*if( this->contieneclave(k) == 1 )
    {
        (this->cantidad)--;
    }*/
    this->arbol=indefinir_aux(this->arbol,k);
}

NodoABBD* diccionario::unircon_aux(NodoABBD* raiz1, const NodoABBD* raiz2)
{
    if( raiz2 != NULL)
    {
            if( contieneclave_aux(raiz1,raiz2->clave) == 0 )
            {
                 raiz1=definir_aux(raiz1,raiz2->clave,raiz2->valor);
                 //(this->cantidad)++;
            }

            raiz1=unircon_aux(raiz1,raiz2->derecho);
            raiz1=unircon_aux(raiz1,raiz2->izquierdo);



    }
    return raiz1;
}

void diccionario::unircon(const diccionario& d2)
{
    this->arbol=unircon_aux(this->arbol,d2.arbol);
}

int diccionario::cantclaves()const
{
    return this->cantidad;
}




NodoABBD* diccionario::intersecarcon_aux(NodoABBD* raiz1, const NodoABBD* raiz2)
{
    /*if( raiz1==NULL || raiz2==NULL) return NULL;

    else
    {
        while(raiz1 != NULL && !contieneclave_aux(raiz2, raiz1->clave))
        {
           raiz1 = indefinir_aux(raiz1, raiz1->clave);
        }
        while(raiz1->derecho != NULL && !contieneclave_aux(raiz2, raiz1->derecho->clave))
        {
            raiz1->derecho = indefinir_aux(raiz1->derecho, raiz1->derecho->clave);
        }
        while(raiz1->izquierdo != NULL && !contieneclave_aux(raiz2, raiz1->izquierdo->clave))
        {
            raiz1->izquierdo = indefinir_aux(raiz1->izquierdo, raiz1->*/
   if(raiz1 != NULL && raiz2 != NULL)
    {
        if(contieneclave_aux(raiz2,raiz1->clave)==0 )
            {
                 raiz1=indefinir_aux(raiz1,raiz1->clave);
                 (this->cantidad)--;
            }
            raiz1=intersecarcon_aux(raiz1->derecho,raiz2);
            raiz1=intersecarcon_aux(raiz1->izquierdo,raiz2);
    }
    return raiz1;
}


void diccionario::intersecarcon( const diccionario& d2)
{
    this->arbol=intersecarcon_aux(this->arbol,d2.arbol);
}


void diccionario::claves_aux(NodoABBD* raiz, listaInt& _claves)const
{

    if(raiz==NULL)
    {
        return;
    }
    else
    {
        claves_aux(raiz->izquierdo,_claves);
        _claves.ag_atras(raiz->clave);
        claves_aux(raiz->derecho,_claves);
        return;
    }

}

listaInt diccionario::claves()const
{
    listaInt lista_claves;
    claves_aux(this->arbol,lista_claves);
    return lista_claves;
}



void diccionario::valores_aux(NodoABBD* raiz,listaInt& _valores)const
{
     if(raiz==NULL)
    {
        return;
    }
    else
    {
        valores_aux(raiz->izquierdo,_valores);
        _valores.ag_atras(raiz->valor);
        valores_aux(raiz->derecho,_valores);
        return;
    }
}

listaInt diccionario::valores()const
{
    listaInt lista_valores;
    valores_aux(this->arbol,lista_valores);
    return lista_valores;
    /*listaInt lista_valores;
    for(int i=0;i<(this->cantidad);i++)
    {
        lista_valores.ag_atras(this->buscarvalor((claves_aux(this->arbol)).iesimo(i)));
    }
    return lista_valores;*/
}

bool iguales_arbol(NodoABBD* raiz1,NodoABBD* raiz2)
{
    if( raiz1==NULL && raiz2==NULL) return true;
    else
    {
        if( raiz1->clave == raiz2->clave)
        {
            if(raiz1->valor == raiz2->valor)
            {
                if( iguales_arbol( raiz1->derecho , raiz2->derecho))
                {
                    return iguales_arbol( raiz1->izquierdo , raiz2->izquierdo);
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }



}

/*bool diccionario::iguales(diccionario& d2)const
{
    if( this->cantidad==d2.cantidad)
    {
         if( claves_aux(this->arbol)==claves_aux(d2.arbol))
         {
             if( d2.valores()==this->valores())
             {
                 return true;
             }
             else return false;
         }
         else return false;
    }
    else
    {
        return false;
    }

}*/

NodoABBD* diccionario::borrar_diccionario_aux(NodoABBD* raiz)
{
    while ( raiz != NULL)
    {
        raiz = indefinir_aux(raiz, raiz->clave);
    }
    return raiz;
}

void diccionario::borrar_diccionario()
{
    this->arbol = borrar_diccionario_aux(this->arbol);
    return;
}


/*diccionario diccionario::copiar(diccionario& d)
{
    (*this).borrar_diccionario();

    listaInt claves_d=d.claves();
    listaInt valores_d=d.valores();
    NodoABBD* nodo_;
    NodoABBD* nodo_aux = new NodoABBD;
    nodo_aux->clave = claves_d.iesimo(0);
    nodo_aux->valor = valores_d.iesimo(0);
    nodo_aux->izquierdo = NULL;
    nodo_aux->derecho = NULL;
    nodo_ = nodo_aux;
    for ( int i = 1; i < d.cantidad; i++ )
    {
        nodo_aux->derecho = new NodoABBD;
        nodo_aux = nodo_aux->derecho;
        nodo_aux->clave = (claves_d).iesimo(i);
        nodo_aux->valor = (valores_d).iesimo(i);
        nodo_aux->izquierdo=NULL;
        nodo_aux->derecho=NULL;
    }

}*/


NodoABBD* copiar_arbol(const NodoABBD* raiz)
{
    if(raiz == NULL)
    {
        return NULL;
    }
    else
    {
        NodoABBD* copia = new NodoABBD;
        copia->clave = raiz->clave;
        copia->valor = raiz->valor;
        copia->derecho = copiar_arbol(raiz->derecho);
        copia->izquierdo = copiar_arbol(raiz->izquierdo);
        return copia;
    }
}

diccionario& diccionario::operator=(const diccionario& d)
{
    (*this).borrar_diccionario();
    this->arbol = copiar_arbol(d.arbol);
    this->cantidad = d.cantidad;
    return *this;
}

diccionario::diccionario(const diccionario& d)
{
    this->cantidad = 0;
    this->arbol = NULL;
    *this = d;
}














