#include <iostream>
#include <cmath>
#include "_tools_.h"


using namespace std;


class A {};

class B {

public:
	// conversion from A with a constructor with one parameter
	explicit B (const A& a)
    {
        print("__single argument constructor__");
    };

	// conversion from A through assignment
	B& operator= (const A& a)
    {
        print("__assignment operator__");
        return *this;
	};

    // conversion to A (type-cast)
    explicit operator A ()
    {
        print("__type-cast operator__");
        return A();
    }

};

void fn (B x)
{
    print("__call to fn__");
}


/*
	promotion (smaller type to bigger type) comes with the guarantee of producing the same value. 
*/


int main ()
{
	short a = 2000;
	int b;
	float c = 0.03205;
	double d;

	b = a;  // compatible --> implicit promotion
	d = c;  // compatible --> implicit promotion

	cout << b << " " << d << "\n";


	int e = -1;
	uint f = e;

	long int g = 4294967296;

	int i = - pow (2, 31);
	uint j = i;

	cout << log2l (g) << "\n";
	cout << j << " " << log2l (j) << " " << i << "\n";

	float* pf = &c;
	bool k = pf;

	cout << boolalpha << k << "\n";


	/*
		implicit conversions with classes
	*/

    A foo;
    A alo;

    print("__2__");
    fn(B(alo));  // keyword explicit!

    print("__3__");
    B boris = B(foo);
    print("__4__");
    boris = alo;
    print("__5__");

    foo = A(boris);  // type-casting with explicit keyword!

	return 0;
}
