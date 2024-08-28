#include <iostream>
#include <string>
#include "_tools_.h"


using namespace std;


class Example {
  public:
  	int total;
  	void accumulate (int x) { total += x; }
};

class Example3 {
	string data;
  public:
  	Example3 () {}
  	Example3 (const string& str) {
  		this -> data = str;
  	}

  	// getters use to be const ... () const
  	const string& content () const {
  		return data;
  	}
};

class Example4 {
  public:
    string* ptr;

    Example4 () {
        this -> ptr = new string ("");
    }

    Example4 (const string& str) {
        this -> ptr = new string (str);
    }

    Example4 (const Example4& e) {
        this -> ptr = new string(e.content());
    }
    
    ~Example4 () {
        delete this -> ptr;
        cout << "DELETED " << this << "\n";
    }
    
    Example4& operator= (const Example4& e)
    {
        print("running operator= overload");
        delete this -> ptr;  // delete the current object pointed to.
        this -> ptr = new string (e.content());  // copy and allocate
        return *this;
    }

    // /*
    //     Optional: the data string is not constant so we 
    //     could modify it in place.
    // */
    // Example4& operator= (const Example4& e)
    // {
    //     *(this -> ptr) = e.content();
    //     return *this;
    // }
    
    const string& content () const {
        return *ptr;
    }
};

int main () {

    print("line 1");
    Example4 ex4 = Example4();
    print("line 2");
    Example4 ex5 = Example4("alo");
    print("line 3");
    Example4 ex6 = Example4("sha");
    print("line 4");
    Example4 ex7 = ex5;  // this line is merely a construction by copy. 

    print("line 5");
    ex4 = ex5;  // Hadn't we written an operator=, this line would lead us to a segmentation fault because of the assignment issue.
                // maybe this performs a shallow copy, which is not suitable for classes
                // that use dynamic memory.

    // the copy assignment is an overload of the operator=

    cout << &ex4 << " " << ex4.ptr << " " << ex4.content() << "\n";
    cout << &ex5 << " " << ex5.ptr << " " << ex5.content() << "\n";
    cout << &ex6 << " " << ex6.ptr << " " << ex6.content() << "\n";

	return 0;
}


// CONTINUE at: {special members}.{Move constructor and Move assignment}
