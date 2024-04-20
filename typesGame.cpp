#include <iostream>
#include <limits>
//#include <unordered_set>
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector
#include <list>
#include <map>
#include <string>


using namespace std;


typedef pair<vector<float>, vector<float>> brick;
typedef tuple<float, float, int> Brick2;

struct Persona {
	int edad;
  char inicial;
};


int main() {

	bool b = true;

	bool c = false;
	bool g = (c || b);

	char e;
	char d;

	int _ = 3;

	cout << "nombre _: " << _ << "\n\n";

	cout << "alexis" << "\b " << "\n\n";

	int current[4] = {0, 0, 0, 0};

	current[3] = -8;

	for (int i = 0; i < 4; i++) cout << "current_i: " << current[i] << endl;
	/*
	cout << "One character: " << endl;
	cin >> e;
	
	cout << "One character: " << endl;
	cin >> d;

	cout << "'" << e << "'" << " + " << "'" << d << "' == " << e + d << endl;
	*/

	cout << 1.4 << "\n\n\n";

	const int w = 3;
	const int arr[] = {0, -4, 7};

	void* pv;

	cout << "pointer to void " << pv << endl << endl;

	enum words {ASM, AUTO, BREAK};

	words u = BREAK;

	enum bandera {x = 1, y = 2, z = 4, q = 8};

	bandera b2 = bandera(5);

	cout << y << ", " << b2 << endl;
	cout << sizeof(bandera) << endl;

	bandera b3 = bandera(176);
	cout << sizeof(bandera) << endl;
	cout << b3 << endl << endl;

	/*unordered_set<int> uset({3,5,5,7});

	for (auto& x: uset) {
		cout << x << " ";
	}
	cout << endl;
*/


	int first[] = {5,10,15,20,25};
	int second[] = {50,40,30,20,10};
	std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
	std::vector<int>::iterator it;

	std::sort (first,first+5);     //  5 10 15 20 25
	std::sort (second,second+5);   // 10 20 30 40 50

	it=std::set_intersection (first, first+5, second, second+5, v.begin());
	                                           // 10 20 0  0  0  0  0  0  0  0
	v.resize(it-v.begin());                      // 10 20

	std::cout << "The intersection has " << (v.size()) << " elements:\n";
	for (it=v.begin(); it!=v.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	list<int> alexis = list<int>();

	alexis.push_back(9);
	alexis.push_back(2);
	alexis.push_back(-1);
	alexis.push_back(0);
	alexis.push_back(-3);
	alexis.push_back(7);

	list<int> otra = list<int>();

	otra.push_back(91);
	otra.push_back(0);
	otra.push_back(-1);
	otra.push_back(10);
	otra.push_back(-3);

	for (auto& i: otra)
	std::cout << i << ' ';
	std::cout << '\n';

	for (auto& i: alexis)
	std::cout << i << ' ';
	std::cout << '\n';

	alexis.sort();
	otra.sort();

	for (auto& i: otra)
	std::cout << i << ' ';
	std::cout << '\n';

	for (auto& i: alexis)
	std::cout << i << ' ';
	std::cout << '\n';

	vector<int>::iterator a;
	vector<int> intersection(max(alexis.size(), otra.size()));

	a = set_intersection(alexis.begin(), alexis.end(), otra.begin(), otra.end(), intersection.begin());
	intersection.resize(a - intersection.begin());

	for (auto& i: intersection)
	std::cout << i << ' ';
	std::cout << '\n';

	cout << "inter size " << intersection.size() << endl; 

	float minimum = 1.17549e-38;
	cout << "limits: " << numeric_limits<float>::min() << " " << numeric_limits<float>::max() << " " << minimum << endl;

    int std_tetrahedra_inside_a_cube[5][4] = {{0, 1, 3, 4}, 
                                              {2, 3, 1, 6}, 
                                              {7, 3, 4, 6}, 
                                              {5, 4, 1, 6}, 
                                              {6, 1, 3, 4}};

    cout << "std_tetrahedra_inside_a_cube: " << std_tetrahedra_inside_a_cube[2][1] << endl;

    vector<float> qq = {0., 1.2};
    cout << qq[0] << " " << qq[1] << endl;

    /*
    map<int, pair<vector<float>, vector<float>>> boris;
    boris.emplace(0, pair<vector<float>, vector<float>>({0.3, 4.2}, {0.9, 3.2}));

    cout << boris.size() << " " << boris[0].first[1] << endl;

    boris.emplace(1, brick({4.4, 2.3, 4.2}, {0., 7.2, 3333444.2}));

    cout << boris.size() << " " << boris[1].second[2] << endl;
    */

    int prisma_kind_table[2][2] = {{2, 3}, {0, 1}};

    cout << "prisma_kind_table " << prisma_kind_table[1][0] << " " << prisma_kind_table[1][1] << endl;

    Brick2 jawtu(3.2, -0.4, 5);
    cout << get<1>(jawtu) << endl;
		
		Persona one;
		Persona other = Persona();

		one.edad = 2;
		other.inicial = 'f';

		cout << one.edad << " " << one.inicial << endl;
		cout << other.edad << " " << other.inicial << endl;

		float number = 4.7;
		
		printf("%f\n", number);

		char separator = ' ';
		cout << to_string(number * 1.2) + separator + to_string(number) << endl;

		vector<bool> boolean_vector = {true, true, false};
		cout << endl << "boolean_vector" << endl;
		for (int i = 0; i < 3; i++) cout << boolean_vector[i] << endl;

		boolean_vector = vector<bool>(4);
		cout << endl << "boolean_vector" << endl;
		for (int i = 0; i < 5; i++) cout << boolean_vector[i] << endl;

		map<int, vector<int>> example0;

	  example0.emplace(0, {2, -3, 4, -5});

	  example0.emplace(1, vector<int>({11, 13, 17, 19}));
	  example0.emplace(2, vector<int>({-1, 0, 7}));


		map<int, vector<int>> example1;
		example1 = map<int, vector<int>>(example0);

		map<int, vector<int>> example2;
		example2 = example0;

		example0[1][2] = 31;
		cout << example1[1][2] << " es 17" << endl;
		cout << example2[1][2] << " es 17?" << endl;
		cout << example0[1][2] << " es 31?" << endl;
	return 0;
}
