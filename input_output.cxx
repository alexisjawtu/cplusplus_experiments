/*
	file input_output.cxx

*/
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main ()
{
	ofstream o;

	o.open("example.txt");
	o << "Insertion of text\n"; 
	o.close();

	o.open("example.txt", ios::app);  // app for append
									  // because o is an ofstream, ios::out is implied
									  // same thing with the ifstreams
									  // so my ios::app is combined resulting in --> 
									  //     o.open( ... , ios::out | ios::app);
	o << "Insertion of more text\n";
	o.close();

	// constructor notation

	o = ofstream("__file__.txt");  // once closed, the stream object is available again.
	ofstream outfile2 = ofstream("example.txt", ios::app);

	cout << boolalpha << "__file__.txt open? " << o.is_open() << '\n';
	cout << boolalpha << "example.txt open? " << outfile2.is_open() << '\n';

	o.close();
	outfile2.close();

	cout << boolalpha << "__file__.txt open? " << o.is_open() << '\n';
	cout << boolalpha << "example.txt open? " << outfile2.is_open() << '\n';

	ofstream myfile ("__file__.txt");
	myfile << "words\n";

	myfile.close();


	string line;
	ifstream afile ("_tools_.h");

	getline(afile, line);
	cout << line << '\n';

	afile.close();


	afile = ifstream("_tools_.h");
	while (getline(afile, line)) {
		cout << line << '\n';
	}
	afile.close();

	cout << line << '\n';

	return 0;
}

	CONTINUE HERE: Input/output with files::get and put stream positioning