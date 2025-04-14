#include <iostream>
#include <string>
using namespace std;

SEGUIR ACA: test y debug del drill 3 [7] :)

double to_mtrs (string u)
{
    if (u == "cm")
        return 1/100;
    else if (u == "ft")
        return 12 * 0.0254;
    else if (u == "in")
        return 0.0254;
    return 1;
}

int main ()
{ 
    string unit;
    double num;

    cin >> num;
    cin >> unit;

    num *= to_mtrs(unit);

    /*
    if (unit == "cm")
        num /= 100;
    else if (unit == "ft")
        num *= 12 * 0.0254;
    else if (unit == "in")
        num =* 0.0254;
    */

    double min_so_far {num};
    double max_so_far {num};

    cout << num << "mtrs. max so far" << '\n';
    cout << num << "mtrs. min so far" << '\n';

    while (cin >> num && cin >> unit)
    {
        if (true)
        {
            num *= to_mtrs(unit);

            if (num > max_so_far)
            {
                max_so_far = num;
                cout << "mtrs. max so far" << '\n';
            }
            else if (num < min_so_far)
            {
                min_so_far = num;
                cout << "mtrs. min so far" << '\n';
            }
        }
    }
}
