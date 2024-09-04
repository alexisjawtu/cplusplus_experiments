#include <iostream>
#include "_tools_.h"


using namespace std;


class Output {

public:

    /*
        static is something that is member of the class itself
        we don't need any instance to call and use a static member
    */
    static void show_on_screen (int i); 

};

void Output::show_on_screen (int i)
{
    cout << i << "\n";
}

class Polygon {

protected:

	int height;
	int width;

public:

	Polygon ()
	{
		print("default constr: I am being executed");
	}

    Polygon (int h, int w)
    {
        print("parameter constr: redirection of the constructor");
        this -> height = h;
        this -> width  = w;
    }

	void set_values (int h, int w) 
	{
		this -> height = h;
		this -> width  = w;
	}

};

class Rectangle: public Polygon, public Output {

public:

    Rectangle () {};

    Rectangle (int h, int w) : Polygon (h, w) {};

	int area ()
	{
		return (this -> height) * (this -> width);
	}

};

class Triangle: public Polygon, public Output {

public:
    
    Triangle () {};

    Triangle (int h, int w) : Polygon (h, w) {};

	float area ()
	{
		return (this -> height) * (this -> width)/2;
	}

};

int main ()
{
	/*
        unless otherwise written the derived object is built
        by the default constructor of the base class

        Se puede redireccionar el llamado del constructor antepasado
        usando la signatura del contructor que queramos llamar
        de la base_class

        ej:

            Triangle (int height, int width) : Polygon (height, width) { ... };

	*/
	Triangle t0;
	Rectangle r0;

	t0.set_values(3,4);
	r0.set_values(3,4);

	printf("areas %f and %d\n", t0.area(), r0.area());

    Triangle t1 (8, 7);

    printf("area t1 %f\n", t1.area());

    Rectangle rect (5, 5);
    Triangle  trgl (5, 5);

    rect.show_on_screen(rect.area());
    // static call:
    Triangle::show_on_screen(trgl.area());

	return 0;
    
}