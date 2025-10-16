#include "complejo.h"

Complejo::Complejo(int a, int b){
    this->re = a;
    this->im = b;
}

int Complejo::real()const{
    return this->re;
}

int Complejo::imag()const{
    return this->im;
}

Complejo Complejo::suma(Complejo z, Complejo w){
    return Complejo(z.real() + w.real(), z.imag() + w.imag());
}

Complejo Complejo::producto(Complejo z, Complejo w){
    return Complejo(z.real()*w.real() - z.imag()*w.imag(), z.real()*w.imag() + z.imag()*w.real());
}
