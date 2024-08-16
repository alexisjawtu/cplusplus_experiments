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
    string* ptr;
  public:
    Example4 () {
        ptr = new string ("");
    }
    Example4 (const string& str) {
        ptr = new string (str);
    }
    Example4 (const Example4& e) {}
    ~Example4 () {
        delete ptr;
        cout << "HEY" << "\n";
    }
    const string& content () const {
        return *ptr;
    }
};

int main () {

    Example4 ex4 = Example4();
    Example4 ex5 = Example4("alo");

    cout << ex5.content() << "\n";
	return 0;
}


//CONTINUE at: special members.copy constructor