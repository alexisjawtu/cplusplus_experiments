#include <iostream>


using namespace std;


enum Names {First, Second, Surname};
enum MusicalInstruments {
	Synthesizer, 
	Piano, 
	Organ, 
	ElectricPiano, 
	Flute,
	Guitar,
	Drums
};

int main() {

	cout << endl
		 << "bool "  << sizeof(bool) << endl
		 << "char "  << sizeof(char) << endl
		 << "short "  << sizeof(short) << endl
		 << "ushort "  << sizeof(ushort) << endl
		 << "int "  << sizeof(int) << endl
		 << "uint "  << sizeof(uint) << endl
		 << "long "  << sizeof(long) << endl
		 << "unsigned long "  << sizeof(unsigned long) << endl
		 << "float "  << sizeof(float) << endl
		 << "double "  << sizeof(double) << endl
		 << "bool* "  << sizeof(bool*) << endl
		 << "int* "  << sizeof(int*) << endl
		 << "float* "  << sizeof(float*) << endl
		 << "enum Names "  << sizeof(Names) << endl
		 << "enum MusicalInstruments "  << sizeof(MusicalInstruments) << endl
		 << endl;

	return 0;
}