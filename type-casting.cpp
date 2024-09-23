// type-casting
// class type-casting


#include <iostream>
#include "_tools_.h"


using namespace std;


class Dummy {
	double i;
	double j;

public:

	Dummy () {};

	Dummy (double k, double l)
	{
		this -> i = k;
		this ->	j = l;
	}

};


class Addition {

	int x;
	int y;

public:

	Addition (int a, int b)
	{
		this -> x = a;
		this -> y = b;
	}

	int result ()
	{
		return this -> x + this -> y;
	}

};


int main ()
{
	double x = 10.3;
	int y;

	y = (int) x;
	cout << y << "\n";
	y = int (x);
	cout << y << "\n";

	Dummy d;
	Addition* padd;
	padd = (Addition*) &d;

	print(padd -> result());  // yields unexpected result

	Dummy d2 = Dummy(4.01, -7.8);

	Addition* padd2 = (Addition*) &d2;

	print(padd2 -> result());  // yields unexpected result

	return 0;
}
