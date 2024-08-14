#include <iostream>
#include <string>


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

int main () {
	Example ex;
	cout << "success" << endl;

	Example3 ex3 ("boris");

	cout << ex3.content() << endl;

	return 0;
}


//CONTINUE at: special members.Destructor