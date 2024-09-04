#include <iostream>
#include "_tools_.h"


using namespace std;


class Polygon {

protected:

	int height;
	int width;

public:

	void set_values (int h, int w) 
	{
		this -> height = h;
		this -> width  = w;
	}

	//area()
};

class Rectangle: public Polygon {

public:

	int area ()
	{
		return (this -> height) * (this -> width);
	}

};

class Triangle: public Polygon {

public:

	int area ()
	{
		return (this -> height) * (this -> width)/2;
	}

};

int main ()
{
	Triangle t0;
	Rectangle r0;

	t0.set_values(3,4);
	r0.set_values(3,4);

	printf("areas %d and %d\n", t0.area(), r0.area());

	return 0;
}