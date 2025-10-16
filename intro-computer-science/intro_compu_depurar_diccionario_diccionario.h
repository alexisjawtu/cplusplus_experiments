#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

struct NodoabB;
typedef int clave;
typedef int valor;


class diccionario
{
    public:

    diccionario();
    bool contieneclave_aux(NodoabB* raiz,clave k)const;
    bool contieneclave(clave k)const;//listo
    valor buscarvalor_aux(NodoabB* raiz,clave k)const;
    valor buscarvalor(clave k)const;//listo
    void definir_aux(NodoabB* raiz,clave k, valor v);
    void definir(clave k, valor v);//listo
    void indefinir_aux(NodoabB* raiz,clave k)const;
    void indefinir(clave k);//listo
    void unircon_aux(NodoabB* raiz1, const NodoabB* raiz2);
    void unircon(const diccionario& d2);
   // bool intersecarCon( const Diccionario d2);
    int cantclaves()const;
    //ListaInt claves()const;
    //ListaInt valores()const;

    private:

    int cantidad;
    NodoabB* arbol;
    //listaInt Inorder;
};

#endif
