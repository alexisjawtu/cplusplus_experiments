#include <iostream>
#include <vector>

// using namespace std;

int main(int argc, char *argv[])
try
{
    std::vector<int> v;
    std::cout <<"Ctrl D ";
    for (int x; std::cin >> x; )
        v.push_back(x);

    for (int i = 0; i <= v.size()+1; ++i)
        std::cout << i << " ---> " << v[i] << '\n';
}
catch (std::out_of_range)
{
    std::cerr << "range err\n";
    return 1;   
}
catch (...)
{
    std::cerr << "Exception\n";
    return 2;
}
