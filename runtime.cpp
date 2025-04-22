#include <iostream>
#include <string>

using namespace std;

void error (string s)
{
    throw runtime_error(s);
}

void some_fn ()
{
    double d {0};
    cin >> d;
    if (!cin)
        error("Could't read a double in some_fn()");
    cout << "d ---> " << d << '\n';
}

int main ()
{
    try
    {
        some_fn();
        return 0;
    }
    catch (runtime_error& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
}
