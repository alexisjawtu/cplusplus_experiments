#include <iostream>
#include <cmath>


using namespace std;


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

	return 0;
}