#include <iostream>
#include <string>
using namespace std;


class Example6 {
	private:

	string* ptr;

	public:

	Example6 () {};

	Example6 (const string& str)
	{
		// resource allocating constructor 
		this -> ptr = new string(str);
	}

	~Example6 ()
	{
		delete this -> ptr;
	}

	Example6 (Example6&& e)
	{
		// move constructor
		this -> ptr = e.ptr;
		e.ptr = nullptr;
	}

	Example6& operator= (Example6&& e)
	{
		// move assignment
		delete this -> ptr;
		this -> ptr = e.ptr;
		e.ptr = nullptr;
		return *this;
	}

	const string& content () const
	{
		return *(this -> ptr);
	}

	Example6 operator+ (const Example6& rhs)
	{
		return Example6(this -> content() + rhs.content());
	}
};


int main ()
{
	Example6 foo ("Exam");
	Example6 bar = Example6("ple");
	Example6 baz;
	baz = foo + bar;
	
	cout << "baz " << baz.content() << "\n";
	return 0;
}

// CONTINUE at: {special members}.{Implicit members}
