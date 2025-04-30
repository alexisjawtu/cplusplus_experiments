#include <string>
#include <iostream>

#include "PPPheaders.h"


using namespace std;


                      //  seed
                      //     |
                      //     |
                      //     v
default_random_engine engine2;

string random_words (int n, int m)
{
    string s(random_int(n, m), 'x');
    for (char& c: s)
        c = narrow<char>(random_int('a', 'z'));
    return s;       
}

vector<pair<string, int>> generate(int n)
    // n random (name, value) pairs
{
    engine2.seed();
    vector<pair<string, int>> res;
    for (int i = 0; i < n; ++i)
        res.push_back({random_words(4, 24), random_int(500)});

    return res;
}


int main ()
{

    vector<pair<string, int>> vec;
    vec = generate(17);
    for (auto& p: vec)
        cout << p.second << ' ' << p.first << '\n';

    cout << string(80,'-') << '\n';
    
    vec = generate(17);
    for (auto& p: vec)
        cout << p.second << ' ' << p.first << '\n';



    return 0;
}
