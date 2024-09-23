#include <iostream>
#include <typeinfo>


using namespace std;


int main ()
{
	int * a, b;
	a = 0;
	b = 0;

	cout << typeid(a).name() << " "
		 << typeid(b).name() << "\n";

	cout << boolalpha << (typeid(a) == typeid(b)) << "\n";

	return 0;	
};

