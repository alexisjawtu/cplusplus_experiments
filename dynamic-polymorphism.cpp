#include <iostream>


using namespace std;


class Polygon {

protected:

	int width, height;

public:

	Polygon (int w, int h)
	{
		this -> width = w;
		this -> height = h;
	}

	virtual int area(void) = 0;

	void printarea()
	{
		cout << this -> area() << "\n";
	}

};


class Rectangle: public Polygon {

public:

	Rectangle (int a, int b): Polygon(a, b) {};

	int area()
	{
		return (this -> width) * (this -> height);
	}

};


class Triangle: public Polygon {

public:

	Triangle (int a, int b): Polygon(a, b) {};

	int area()
	{
		return (this -> width) * (this -> height)/2;
	}

};


int main ()
{
	Polygon* ppoly1 = new Rectangle (2, 1);
	Polygon* ppoly2 = new Triangle (7, 6);

	ppoly1 -> printarea();
	ppoly2 -> printarea();

	delete ppoly1;
	delete ppoly2;

	return 0;
}
