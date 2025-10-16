#ifndef _COMPLEJO_H_
#define _COMPLEJO_H_

class Complejo{
    public:
    Complejo(int a, int b);
    int real()const;
    int imag()const;

    Complejo suma(Complejo z, Complejo w);
    Complejo producto(Complejo z, Complejo w);

    private:
    int re;
    int im;
};



#endif
