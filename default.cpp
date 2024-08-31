// default and implicit put as explicit indications
#include <iostream>
using namespace std;


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
};


int main () {
	Rectangle bar (10, 20);
	
	/*
		this would not be allowed:

		Rectangle foo (bar); 

	*/

	cout << foo.area() << " area of bar: " << bar.area() << "\n";

	return 0;
}