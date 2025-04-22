#include <iostream>

using namespace std;

constexpr int frame {2};

class Bad_area {};

int area (int l, int w)
{
    if (l < 0 || w <0)
	    throw Bad_area{};
    return l*w;	
}

int framed_area (int l, int w)
{
    return area (l-frame, w-frame);
}

void test (int x, int y, int z)
{
	int area1 = area (x, y);
	int area2 = framed_area (1, z);
	int area3 = framed_area (y, z);
	double r = double(area1)/area3;
}

int main(int argc, char *argv[])
{
    try
    {
        test (-1,2,4);
        cout << "hi";
    }
    catch (Bad_area)
    {
        cout << "oops, bad args\n";
    }

    try
    {
        area (3,2);
        cout << "hi";
    }
    catch (Bad_area)
    {
        cout << "oops, bad argumevvvvnts\n";
    }
}


int main(int argc, char *argv[])
{
	try
	{
	    return 0;
	}
	catch (exception& e)
	{
	    cerr << e.what();
	    return 1;
	}
	catch (...)
	{
	    cerr << "unknown error\n";
	    return 2;
	}
}

void error (string s1, string s2)
{
    throw runtime_error {s1 + s2};
}

TODO
To see what an uncaught exception error looks like, run a small program that uses

error() without catching any exceptions.
