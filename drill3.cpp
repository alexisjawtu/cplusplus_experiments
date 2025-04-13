#include <iostream>
using namespace std;

SEGUIR en drill3::[6]




int main ()
{ 
    double num1, num2;

    while (cin >> num1 && cin >> num2)
    {
        if (num1 == num2)
            cout << "equal\n";
        else
        {
            double max {num1 > num2 ? num1 : num2};
            double min {num1 > num2 ? num2 : num1};
            cout << "min: " << min << '\n';
            cout << "max: " << max << '\n';
            double dist {max - min};
            double thrshld {1.0/100};
            if (dist < thrshld)
                cout << "almost equal\n";
        }
    }
}
