
#ifndef _PILAENT_H_
#define _PILAENT_H_

struct Nodo;

class pilaEnt
{
    public:

    int tam()const;
    pilaEnt();
    int tope()const;
    void apilar(int x);
    void desapilar();
    pilaEnt(const pilaEnt& p);
    pilaEnt copiarPila()const;

    private:
    Nodo* primero;
    int cantidad;
};

#endif
