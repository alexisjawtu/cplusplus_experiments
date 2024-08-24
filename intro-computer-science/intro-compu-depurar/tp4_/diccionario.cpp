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
        return contieneclave_aux(raiz->derecho,k);
    }
    else
    {
        return contieneclave_aux(raiz->izquierdo,k);
    }
}

bool diccionario::contieneclave(clave k)const
{
    return contieneclave_aux(this->arbol,k);

}

valor diccionario::buscarvalor_aux(NodoABBD* raiz,clave k)const
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

valor diccionario::buscarvalor(clave k)const
{
   return buscarvalor_aux(this->arbol,k);
}

void diccionario::definir_aux(NodoABBD* raiz,clave k, valor v)const
{
     if(raiz == NULL)
    {
        NodoABBD* nodoaux=new NodoABBD ;
        nodoaux->clave=k;
        nodoaux->valor=v;
        nodoaux->izquierdo=NULL;
        nodoaux->derecho=NULL;
        raiz=nodoaux;
    }
    else if( (raiz->clave)< k )
    {
        definir_aux(raiz->derecho,k,v);
    }
    else if( (raiz->clave) > k)
    {
        definir_aux(raiz->izquierdo,k,v);
    }
    else
    {
        raiz->valor=v;
    }
    return ;
}

void diccionario::definir(clave k, valor v)
{
   if( ~(this->contieneclave(k)) )
   {
       (this->cantidad)++;
   }
   definir_aux(this->arbol,k,v);
   return;
}

void diccionario::indefinir_aux(NodoABBD* raiz,clave k)const
{
    if( this->contieneclave(k) )
    {
        if( raiz != NULL)
        {
            if( (raiz->clave) < k )
            {
                indefinir_aux(raiz->derecho,k);
            }
            else if( (raiz->clave) > k )
            {
                indefinir_aux(raiz->izquierdo,k);
            }
            else
            {
                if( raiz->derecho==NULL)
                {
                    raiz=raiz->izquierdo;//faltaria borrar la raiz anterior
                }
                else
                {
                    NodoABBD* nodominimo=raiz->derecho;
                    while( nodominimo->izquierdo!=NULL)
                    {
                        nodominimo=nodominimo->izquierdo;
                    }

                    NodoABBD* derecha=raiz->derecho;
                    NodoABBD* izquierda=raiz->izquierdo;// aca habria q borrar tambien
                    raiz=nodominimo;
                    indefinir_aux(derecha,nodominimo->clave);
                    raiz->derecho=derecha;
                    raiz->izquierdo=izquierda;
                }
            }
        }
    }
}



void diccionario::indefinir(clave k)
{
    indefinir_aux(this->arbol,k);
    if( this->contieneclave(k) )
    {
        (this->cantidad)--;
    }
}

void diccionario::unircon_aux(NodoABBD* raiz1, const NodoABBD* raiz2)const
{
    if( raiz2 != NULL)
    {
        //if(raiz1 == NULL)
        //{
           // NodoABBD* raiz2aux=raiz2;
            //raiz1=raiz2aux;
        //}

        //{
            if(~( contieneclave_aux(raiz1,raiz2->clave) ) )
            {
                 definir_aux(raiz1,raiz2->clave,raiz2->valor);
            }
            unircon_aux(raiz1,raiz2->derecho);
            unircon_aux(raiz1,raiz2->izquierdo);

        //}

    }
}

void diccionario::unircon(const diccionario d2)
{
    unircon_aux(this->arbol,d2.arbol);
}

//bool diccionario::intersecarCon( const Diccionario d2)
//{
//}


int diccionario::cantclaves()const
{
    return this->cantidad;
}

//ListaInt diccionario::claves()const
//{
  //  if(this->raiz==NULL)
    //{
     //   return listaInt();
    //}
    //else
    //{
      //  this->raiz->clave

        //return (((this->raiz->izquierdo).claves).ag_atras(this->raiz->clave)).agregarle((this->raiz->derecho).claves)
    //}

//}


//ListaInt valores()const
//{
//}




















