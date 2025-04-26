#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v;
//    cout << 0 << " ---> " << v[0] << '\n';

    for (int x; cin >> x; )
        v.push_back(x);

    for (int i = 0; i <= v.size(); ++i)
        cout << i << " ---> " << v[i] << '\n';

    cout << -8 << " ---> " << v[-8] << '\n';

}
