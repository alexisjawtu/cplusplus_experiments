#include <iostream>


using namespace std;


int main() {
	cout 
		 << '0' << " " << int('0') << endl
		 << '1' << " " << int('1') << endl
		 << '7' << " " << int('7') << endl
		 << '8' << " " << int('8') << endl;

	char c;
	int k = int('9');

	while (k < 97) {
		c = char(k);
		cout << c << " " << hex << k << endl;
		k++;
	}

	char a = 'a';
	for (int j = 0; j < 50; j++) {
		cout << char('a' + j) << " " << 'a' + j << endl;
	}

	cout << "qu'e interesante! :D "
		 << "word" << char(127) << "word" << endl;

	return 0;
}
