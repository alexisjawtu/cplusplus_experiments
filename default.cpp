// default and implicit put as explicit indications
// friendship-inheritance

#include <iostream>
using namespace std;


// class friendship
class Square;  // necessary empty declaration because of the mutual referencing

class Rectangle {
	int width;
	int height;

	public:

		Rectangle (int x, int y) {
			this -> width = x;
			this -> height = y;
		}

		Rectangle () = default;

		/*
			here we forbid a copy-construction
		*/
		Rectangle (const Rectangle& other) = delete;
		
		int area() {
			return (this -> width) * (this -> height);
		}

		void convert (Square& sq);

		friend Rectangle duplicate (const Rectangle& original);
};

class Square {
	friend class Rectangle;  // means that Rectangle is considered a friend by Square.
	                         // Square is not considered a friend class by Rectangle.

	private:

		int side;

	public:

		Square (int s) { this -> side = s; }
};

Rectangle duplicate (const Rectangle& original) {
	return Rectangle (original.width * 2, original.height * 2);
}

void Rectangle::convert (Square& sq) {

	this -> width  = sq.side;
	this -> height = sq.side;

}

int main () {
	Rectangle bar (10, 20);
	
	/*
		this would not be allowed:

		Rectangle foo (bar); 

	*/

	Rectangle foo = duplicate (bar);
	Rectangle rect;
	Square sqr (4);
	rect.convert(sqr);

	cout << rect.area() << " " << foo.area() << " area of bar: " << bar.area() << "\n";

	return 0;
}
