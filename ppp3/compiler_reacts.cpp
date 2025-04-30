#include "PPPheaders.h"

int main()
{
    try
    {
        //string s = "ape"; if (s!="fool") cout << "Success!\n";
        // string s = "ape"; if (s!="fool") cout << "Success!\n";
        // string s = "ape"; if (s != "fool") cout << "Success!\n";
        // vector<char> v(5); for (int i = 0; i<v.size(); ++i) cout << "Success!\n";
        // vector<char> v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";
        // string s = "Success!\n"; for (char c: s) cout << c;
        // if (true) cout << "Success!\n"; else cout << "Fail!\n";
        // int x = 2000; char c = x; if (x==2000) cout << "Success!\n";
        // string s = "Success!\n"; for (int i = 0; i<10; ++i) cout << s[i];
        // vector<int> v(5); for (int i = 0; i<1; ++i) cout << "Success!\n";
        // int i = 0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success!\n";
        // int x = 2; double d = 5/(x-1); if (d==2*(x+0.5)) cout << "Success!\n";
        // string s = "Success!\n"; for (int i = 0; i<=10; ++i) cout << s[i];
        // int i = 0; int j {0}; while (i<10) ++i; if (j<i) cout << "Success!\n";
        // int x = 4; double d = 5/(x-2); if (d=2*x+0.5) cout << "Success!\n";
        cout << "Success!\n";
        return 0;
    }
    catch (exception& e)
    {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "oops: unknown\n";
        return 2;
    }
}



