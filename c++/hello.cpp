#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include "the_map.h"


using namespace std;


int main() {
	int a;
	float b;
	char c;
	bool d;

	string s = "alexis";
	string t = "boris";
	char u = t[3];

	c = '3';
	b = 'a';
	cout << c << endl;
	cout << b << endl;
	cout << u << endl;

	vector<string> example = { "alexis", "boris" };

	for (string n : example) {
		cout << n << ", ";
	}

	cout << endl;

	double th  = atan2(1, 0);  // y, x
	double th2 = atan2(0, 1);
	double th3 = atan2(-1, 0);
	double th4 = atan2(0, -1);

	cout << th << " " << th2 << " " << th3 << " " << th4 << " " << 2 * th << endl;

	map<int, string> names;

	names.emplace(0, "alo");
	names.emplace(1, "maya");

	cout << names[0] << " " << names[1] << endl;

	

	the_map tm;
	tm[4] = "nord";

	cout << tm;
};
