#include <iostream>
#include <typeinfo>
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


int main ()
{
	cout << typeid(B).name() << " " << typeid(A).name() << "\n";
	return 0;
}

CONTINUE HERE type conversions :: dynamic_cast
