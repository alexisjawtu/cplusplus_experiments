/**
 *       31                                   3210      
 * [53] = 0 000 0000 0000 0000 0000 0000 0011 0101     POSITIVE
 *        s
 * [~53]= 1 111 1111 1111 1111 1111 1111 1100 1010     NEGATIVE
 * classes2.cpp
*/
#include <iostream>
#include <string>
#include "_tools_.h"


using namespace std;

/*
template <class T> void print(T data)
{
    std::cout << std::boolalpha << data << "\n";
}
*/


class CVector {
  public:    
    float x;
    float y;

    CVector () {};
    CVector (float a, float b) : x(a), y(b) {};

    CVector& operator= (const CVector&);
    CVector  operator+ (const CVector&);

    bool isitme (CVector& v);

    friend ostream& operator<< (ostream& o, const CVector& v);
};

CVector& CVector::operator= (const CVector& v) {
    this -> x = v.x;
    this -> y = v.y;
    return *this;
}

CVector CVector::operator+ (const CVector& v) {
    return CVector (this -> x + v.x, this -> y + v.y);
}

bool CVector::isitme (CVector& v) {
    return (this == &v);
}

ostream& operator<< (ostream& o, const CVector& v) {
    return o << "(" << v.x << ", " << v.y << ")";
}


/*
    static used to count class objects allocated
*/
class Dummy {
  public:
    static int n;
    Dummy () {
        n++;
    }
};

int Dummy::n = 0;

template <class T>
class Pair {
    T values [2];
  public:
    Pair (T a, T b) {
        this -> values[0] = a;
        this -> values[1] = b;
    }

    friend ostream& operator << (ostream& o, Pair<T>& p) {
        return o << p.values[0] << " " << p.values[1];
    }
};

int main(int argc, char const *argv[])
{
    CVector u, v, w;
    
    u.x = 1.3;
    u.y = -2;

    v.x = 6;
    v.y = 0.7;

    w = u + v;

    print(w);

    print(w.operator+(u));

    print(u.isitme(w));
    print(u.isitme(u));

    CVector * p = &v;

    print(p -> isitme(v));

    print("==========================================");
    
    print(Dummy::n);
    Dummy a;
    print(Dummy::n);
    Dummy b[5];
    print(a.n);
    Dummy * c;
    print(Dummy::n);
    c = new Dummy;
    print(b[2].n);

    print("==========================================");

    Pair<string> phrase ("alexis", "boris jawtu");

    print(phrase);

    return 0;
}
