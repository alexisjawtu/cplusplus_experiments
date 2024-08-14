#include <iostream>


using namespace std;


class Example {
  public:
  	int total;
  	void accumulate (int x) { total += x; }
};

int main () {
	Example ex;
	
	return 0;
}
