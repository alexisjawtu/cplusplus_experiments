#include <iostream>


using namespace std;


int main ()
{

	try {

		// we throw the first one and ignore the others, and jump
		// directly to the handlers
		throw "alexis";
		cout << "Reach test line.\n";  // not executed
		throw 17;
		throw 17.3;

	} catch (double e) {

		cout << "Exception double " << e << "\n";

	} catch (int e) {

		cout << "Exception int " << e << "\n";

	} catch (...) {

		cout << "Default exception handler\n";

	}

	cout << "Flow continuation\n";

	return 0;

}
