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
    }
    catch (Bad_area)
    {
        cout << "oops, bad arguments\n";
    }
}