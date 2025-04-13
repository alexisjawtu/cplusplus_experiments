#include <iostream>
#include <string>

#include <vector>
#include <algorithm>


using namespace std;


int main1 () {

    int n = 0;

    string previous;
    string current;

    while (cin >> current) {
        ++n;
        if (previous == current)
            cout << "word " << n << " repeated: " << current << '\n';
        previous = current;
    }

	return 0;
}


int main3 () 
{
    char unit = ' ';
    int val {0};
    cin >> val >> unit;
    cout << val << '\t' << unit << '\n';
    return 0;
}


int main ()
{
    vector <double> temps;

    for (double temp; cin >> temp; )
        temps.push_back(temp);
    ranges::sort(temps);

    for (double d: temps)
        cout << d << '\n';

    return 0;
}
