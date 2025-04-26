// exceptions.cpp

/*
    Rule of thumb

    as a default debugging scheme, use error() and catch
    exception in main()
*/

#include "PPPheaders.h"

using namespace std;

constexpr int frame {2};

class Bad_area {};

int area (int l, int w)
{
    if (l < 0 || w < 0)
        error(to_string(w) + " <-- wrong sign of arguments --> " + to_string(l));
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

int prevmain(int argc, char *argv[])
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
        cout << "oops, bad arguments\n";
    }
    return 0;
}

bool positive_ordered (int a, int b, int c)
{
    return (0 < a) && (a < b) && (b < c);
}

int my_complicated_function (int a, int b, int c)
{
    // the args must be 0 < a < b < c
    expect([&]{ return (0 < a) && (a < b) && (b < c); }, "bad args for m_c_f");
    return a * b * c;
}

int main(int argc, char *argv[])
{
    cout << my_complicated_function(2, 3, 7) << '\n';
    int mcf = my_complicated_function(4, 8, 7);
    cout << mcf << '\n';

	try
	{
        cout << "Our normal program\n";
        test (-1, 2, 4);
        cout << area (3, 2) << '\n';
        cout << area (3, -2) << '\n';
	    return 0;
	}
	catch (exception& e)
	{
	    cerr << "Returning 1.\n" << e.what() << "\n";
	    return 1;
	}
    catch (Bad_area&)
    {
        cout << "oops, bad area.\n";
        return 3;
    }
	catch (...)
	{
	    cerr << "Returning 2. Unknown error\n";
	    return 2;
	}
}
