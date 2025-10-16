#include <iostream>

using namespace std;

int main() // terna pitagórica a,b,c tal que a+b+c=1000.
{
    for(int b = 5; b < 500; b++)
    {
        for(int a = 6; a < 1000; a++)
        {
            if(500000 - 1000*b == a*(1000-b))
            {
                cout<<a<<endl<<b<<endl;
                return 0;
            }
        }
    }
    return 0;
}
/*375
200
425
140625
40000

375*200*425=31875000*/
