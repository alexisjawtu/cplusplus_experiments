#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int main () {
	unordered_map<string, int> m;
	for (string line; getline(cin, line); )
	{
		cout << m[line] << '\n';
		// if (++m[line] == 0)  // first increase, then evaluate equality.
		if (m[line]++ == 0)  // first evaluate equality, then increase.
		{
			cout << m[line] << '\n';
			cout << line << '\n';
		}
	}
}

