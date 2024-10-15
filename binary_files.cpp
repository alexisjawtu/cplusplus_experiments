// binary_files.cpp
/*

	Cplusplus includes two functions that are specifically designed
	to insert and extract binary data sequentially:

			* write()

			* read()

*/


// reading an entire binary file
#include <iostream>
#include <fstream>


using namespace std;


int main ()
{

	streampos size;
	char* memblock;

	ifstream file ("art.wma", ios::in | ios::binary | ios::ate);

	if (file.is_open())
	{
		size = file.tellg();  // because we opened it ios::ate :)
		memblock = new char [size];

		file.seekg(0, ios::beg);
		file.read(memblock, size);
		file.close();

		cout << "file content in memory" << '\n'
			 << "file size is " << size << '\n'
			 << "memblock has " << memblock << '\n';

		delete[] memblock;
	}
	else cout << "not open" << '\n';

	return 0;

}
