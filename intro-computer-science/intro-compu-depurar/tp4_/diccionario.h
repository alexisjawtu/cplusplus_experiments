
#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

struct NodoABBD;
typedef int clave;
typedef int valor;


class diccionario
{
    public:

    diccionario();
    bool contieneclave_aux( NodoABBD* raiz,clave k)const;
    bool contieneclave(clave k)const;//listo
    valor buscarvalor_aux(NodoABBD* raiz,clave k)const;
    valor buscarvalor(clave k)const;//listo
    void definir_aux(NodoABBD* raiz,clave k, valor v)const;
    void definir(clave k, valor v);//listo
    void indefinir_aux(NodoABBD* raiz,clave k)const;
    void indefinir(clave k);//listo
    void unircon_aux(NodoABBD* raiz1, const NodoABBD* raiz2)const;
    void unircon(const diccionario d2);
   // bool intersecarCon( const Diccionario d2);
    int cantclaves()const;
    //ListaInt claves()const;
    //ListaInt valores()const;




    private:

    int cantidad;
    NodoABBD* arbol;
    //listaInt Inorder;

};

#endif

