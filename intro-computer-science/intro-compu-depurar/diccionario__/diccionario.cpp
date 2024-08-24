//#include "listaInt.h"
#include "diccionario.h"
#include <cstdlib>



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
bool diccionario::contieneclave_aux( NodoABBD* raiz,clave k)const
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

valor diccionario::buscarvalor_aux(NodoABBD* raiz,clave k)const
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
   if( (this->contieneclave(k)) == 0 )
   {
       (this->cantidad)++;
   }
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
               raiz=indefinir_aux(raiz->derecho,k);
            }
            else if( raiz->clave > k )
            {
                raiz=indefinir_aux(raiz->izquierdo,k);
            }
            else
            {
                if( raiz->derecho==NULL)
                {
                    //NodoABBD* nodo_aux=raiz;
                    raiz=raiz->izquierdo;//faltaria borrar la raiz anterior
                    //delete nodo_aux;
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
                    NodoABBD* izquierda=raiz->izquierdo;// aca habria q borrar tambien
                    raiz=nodominimo;
                    //delete nodominimo;
                    //delete nodo_aux;
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
    if( this->contieneclave(k) == 1 )
    {
        (this->cantidad)--;
    }
    this->arbol=indefinir_aux(this->arbol,k);
}

NodoABBD* diccionario::unircon_aux(NodoABBD* raiz1, const NodoABBD* raiz2)
{
    if( raiz2 != NULL)
    {
            if( contieneclave_aux(raiz1,raiz2->clave) == 0 )
            {
                 raiz1=definir_aux(raiz1,raiz2->clave,raiz2->valor);
                 (this->cantidad)++;
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




/*bool diccionario::intersecarCon( const Diccionario d2)
{
}


ListaInt diccionario::claves()const

    if(this->raiz==NULL)
    {
        return listaInt();
    }
    else
    {
        this->raiz->clave

        return (((this->raiz->izquierdo).claves).ag_atras(this->raiz->clave)).agregarle((this->raiz->derecho).claves)
    }

}


//ListaInt valores()const
//{
//}
*/



















