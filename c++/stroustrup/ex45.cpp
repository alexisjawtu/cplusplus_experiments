#include <iostream>
#include <limits>


using namespace std;


int main() {

	cout << "min " << numeric_limits<char>::min() << " " << int(numeric_limits<char>::min()) << endl;
	cout << "max " << numeric_limits<char>::max() << " " << int(numeric_limits<char>::max()) << endl;

	cout << "short " << numeric_limits<short>::min() << " " << numeric_limits<short>::max() << endl;

	cout << "int " << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
	cout << "long " << numeric_limits<long>::min() << " " << numeric_limits<long>::max() << endl;
	cout << "float " << numeric_limits<float>::min() << " " << numeric_limits<float>::max() << endl;
	cout << "double " << numeric_limits<double>::min() << " " << numeric_limits<double>::max() << endl;
	cout << "long double " << numeric_limits<long double>::min() << " " << numeric_limits<long double>::max() << endl;
	cout << "unsigned " << numeric_limits<unsigned>::min() << " " << numeric_limits<unsigned>::max() << endl;


	return 0;
}