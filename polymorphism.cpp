#include <iostream>
#include "_tools_.h"


using namespace std;


/*

	pointers to base class
	======================

	a pointer to a derived class is type-compatible with a pointer
	to its base class

	polymorphism is the art of taking advantage of this mere and yet
	profound fact


	virtual members
	===============

	a virtual member is a member function that can be redefined in derived classes

	The redefinition preserves the calling from the base class through 
	references, that is, if we did not write the virtual specifier then
	to get a Rectangle area we would need a specific pointer to Rectangle

	It would not suffice to have all pointers to Polygon

	Non-virtual members of derived classes cannot be acccesed though a reference
	of the base class

	A class that declares or inherits a virtual function is called a
	__polymorphic class__


	abstract base classes
	=====================

	any class with a "pure virtual" function

	they ought to be used to initialize pointers to it and to benefit from the
	polymorphism

*/


class Polyhedron {

protected:

	int width;
	int height;

public:

	virtual int area(void) = 0;

	/*
		using the construction 'this -> ' it is possible to call a pure virtual
		member function from each derived class, even though the current class
		itself did not implement the aforementioned funtion
	*/
	int volume(void)
	{
		return (this -> area()) * (this -> height);
	}

	void set_values(int w, int h)
	{
		this -> width = w;
		this -> height = h;
	}

};


class Pyramid: public Polyhedron {

public:

	int area(void)
	{
		return 45;
	}

};


class Polygon {

protected:

	int height;
	int width;

public:

	void set_values(int w, int h)
	{
		this -> height = h;
		this -> width  = w;
	}

	virtual int area() 
	{ 
		return 0; 
	}

};


class Rectangle: public Polygon {

public:

	int area()
	{
		return (this -> width) * (this -> height);
	}

};


class Triangle: public Polygon {

public:

	int area()
	{
		return (this -> width) * (this -> height)/2;
	}

};


int main ()
{
	Rectangle rect;
	Triangle trgl;
	Polygon poly;  // <- not an abstract base class!

	// polymorphic pointers
	Polygon* ppoly1 = &rect;
	Polygon* ppoly2 = &trgl;
	Polygon* ppoly3 = &poly;

	ppoly1 -> set_values(4, 5);
	ppoly2 -> set_values(4, 5);
	ppoly3 -> set_values(4, 5);

	// if did not have area as a virtual member
	printf("areas %d %d\n", rect.area(), trgl.area());

	// using the virtual member area
	printf("virtual areas %d %d %d\n", ppoly1 -> area(), ppoly2 -> area(),
		ppoly3 -> area());

	Pyramid p;
	Polyhedron* ppolyh = &p;  // <- Polyhedron is, in fact, an ABS
	ppolyh -> set_values(-7, 3);


	printf("pyramid area and volume %d %d\n", ppolyh -> area(), ppolyh -> volume());

	return 0;
}
