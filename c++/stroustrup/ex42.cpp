#include <iostream>
#include <string>
#include <complex>


using namespace std;


typedef complex<short> Point;

struct Date;

struct Date {
	int d, m, y;
};

int day(Date* date) {
	return date->d;
}

template<class T> T abs(T a) {
	return a < 0 ? -a : a;
}

struct User;

enum Bier {Carlsberg, Tuborg, Thor};

namespace NS {
	int a;
}

double sqrt(double r2) {
	return r2/2;
}

int main()
{
	char ch;
	string c;
	int cuenta = 1;
	const double pi = 3.14159265;
	extern int num_error;
	const char* name;
	const char* season[] = {"spring", "summer", "fall", "winter", "other"};
	//const char** season;

	// double sqrt(double);

	int a = 3;

	NS::a = 6;

	cout << a << " " << NS::a << endl;

	struct User {
		string name;
		int id;
	};

	cout << sizeof(c) << " " 
		 << sizeof(ch) << " " 
		 << sizeof(name) << " " 
		 << sizeof(Point) << " "
		 << sizeof(season) << " "
		 << endl;

	return 0;
}