
#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

struct NodoABBD;
typedef int clave;
typedef int valor;


class diccionario
{
    public:

    diccionario();
   // bool contieneclave_aux( NodoABBD* raiz,clave k)const;
    bool contieneclave(clave k)const;//listo
    //valor buscarvalor_aux(NodoABBD* raiz,clave k)const;
    valor buscarvalor(clave k)const;//listo
   // void definir_aux(NodoABBD* raiz,clave k, valor v);
    void definir(clave k, valor v);//listo
    //void indefinir_aux(NodoABBD* raiz,clave k);
    void indefinir(clave k);//listo
    //void unircon_aux(NodoABBD* raiz1, const NodoABBD* raiz2);
    void unircon(const diccionario& d2);
   // bool intersecarCon( const Diccionario d2);
    int cantclaves()const;
    //ListaInt claves()const;
    //ListaInt valores()const;




    private:

    int cantidad;
    NodoABBD* arbol;
    //listaInt Inorder;
    bool contieneclave_aux( NodoABBD* raiz,clave k)const;
    valor buscarvalor_aux(NodoABBD* raiz,clave k)const;
    NodoABBD* definir_aux(NodoABBD* raiz,clave k, valor v);
    NodoABBD* indefinir_aux(NodoABBD* raiz,clave k);
    NodoABBD* unircon_aux(NodoABBD* raiz1, const NodoABBD* raiz2);

};



#endif

