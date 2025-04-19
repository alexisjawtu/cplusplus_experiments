#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


double to_mtrs (string u)
{
    if (u == "cm")
        return 1.0/100;
    else if (u == "ft")
        return 12 * 0.0254;
    else if (u == "in")
        return 0.0254;
    return 1;
}

bool illegal(string u)
{
    return (u != "cm") && (u != "ft") && (u != "in") && (u != "m");
}

int main ()
{ 
    int count {0};
    double num {0};
    double sum {0};
    string unit;

    vector <double> vd;

    cout << "cm ft in m\n";

    cin >> num;
    cin >> unit;

    while (illegal(unit))
    {
        cout << "illegal unit. try again\n";
        cin >> num;
        cin >> unit;
    }

    num *= to_mtrs(unit);
    ++count;
    sum += num;
    vd.push_back(num);

    double min_so_far {num};
    double max_so_far {num};

    cout << num << " mtrs. max so far" << '\n';
    cout << num << " mtrs. min so far" << '\n';

    while (cin >> num && cin >> unit)
    {
        while (illegal(unit))
        {
            cout << "illegal unit. try again\n";
            cin >> num;
            cin >> unit;
        }

        num *= to_mtrs(unit);
        ++count;
        sum += num;
        vd.push_back(num);

        if (num > max_so_far)
        {
            max_so_far = num;
            cout << num << " mtrs. max so far" << '\n';
        }
        else if (num < min_so_far)
        {
            min_so_far = num;
            cout << num << " mtrs. min so far" << '\n';
        }
    }
    cout << "sum " << sum << ". count " << count << "\n";
    ranges::sort(vd);

    for (auto v: vd)
        cout << '\t' << v << " mtrs\n";
}
