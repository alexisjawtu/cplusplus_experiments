// stream_positioning.cpp
#include <iostream>
#include <fstream>


using namespace std;


int main ()
{

    streampos begin, end;
    // ifstream myfile ("test.txt");
    ifstream myfile ("_a_.out", ios::binary);

    begin = myfile.tellg();

    /*
        seekg (streamoff offset, seekdir direction);

        But streamoff is an ALIAS of one of the fundamenteal integral types,
        such as int or long int.
    */
    myfile.seekg(0, ios::end);
    end = myfile.tellg();

    cout << (end - begin)  << '\n';

	return 0;

}
