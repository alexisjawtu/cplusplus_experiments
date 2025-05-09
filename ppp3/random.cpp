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
        res.push_back({random_words(4, 24), random_int(25)});

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


    /***************************************************************************************************
        [13] The program is a bit tedious because the answer is hard-coded into the program. Make a ver-
        sion where the user can play repeatedly (without stopping and restarting the program) and
        each game has a new set of four digits. You can get four random digits by calling the random
        number generator random_int(0,9) from PPP_support (and 4.7.5) four times. You will note
        that if you run that program repeatedly, it will pick the same sequence of four digits each
        time you start the program. To avoid that, ask the user to enter a number (any number) and
        call seed(n), also from PPP_support, where n is the number the user entered before calling
        random_int(0,10). Such an n is called a seed, and different seeds give different sequences of
        random numbers.
    */

    int seed {0};
    cout << "Seed " << '\n';
    while (cin >> seed)
    {
        engine2.seed(seed);
        cout << random_int(0, 17) << ' '
             << random_int(0, 17) << ' ' 
             << random_int(0, 17) << ' '
             << random_int(0, 17) << '\n'; 
        cout << "Seed " << '\n';
    }

    return 0;
}
