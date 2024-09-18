#include <iostream>
#include <typeinfo>
#include <exception>


#include "_tools_.h"


using namespace std;


/*
	We have four specific casting operators

		dynamic_cast:                   dynamic_cast <new type> (expression)

		reinterpret_cast:				reinterpret_cast <new type> (expression)

		const_cast:						***_cast <new type> (expression)	

		static_cast:					***_cast <new type> (expression)	
*/


class A {};


class B {};


class Base {

	virtual void dummy() {};

};


class Derived: public Base {

	int a;

};


class Derived2: public Base {

	void dummy() {
		cout << "Dummy call\n";
	}

};


class C {

};


class D: public C {

};


void write_to_screen (char* str)
{
	cout << str << "\n";
} 


int main ()
{
	cout << typeid(B).name() << " " << typeid(A).name() << "\n";


	cout << "\n**************** dynamic cast ********************\n";

	try {

		Base* pba = new Derived;
		Base* pbb = new Base;

		Derived* pd;
		Derived2* pd2;

		/*
			dynamic_cast < new_type > (expression)

			we are trying to store something significant into pd,
			so we need to "transform" (cast) things to the type of pd
		*/

		pd = dynamic_cast<Derived*>(pba);
		cout << boolalpha << "cast(Derived*) pba leaves null pointer: " << (pd == 0) << "\n";

		pd = dynamic_cast<Derived*>(pbb);
		cout << boolalpha << "cast(Derived*) pbb leaves null pointer: " << (pd == 0) << "\n";

		pd2 = dynamic_cast<Derived2*>(pbb);
		cout << boolalpha << "cast(Derived2*) pbb leaves null pointer: " << (pd2 == 0) << "\n";

	} catch (exception& e) {

		cout << "Exception: " << e.what() << "\n";

	}


	cout << "\n**************** static  cast ********************\n";

	/*
		a little faster, a little unsafer
	*/


	C* c = new C;
	D* d = static_cast<D*>(c);

	float pi = 3.14;
	float* ppi = &pi;

	cout << typeid(c).name() << " " << typeid(d).name() << " "
		 << typeid(pi).name() << " " << typeid(ppi).name() << "\n";


	cout << "\n**************** const   cast ********************\n";
	const char* text = "sample text";

	write_to_screen(const_cast<char*>(text));



	return 0;
}
