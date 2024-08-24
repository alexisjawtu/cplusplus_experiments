#include <map>
#include <iostream>

using namespace std; 

class the_map : public map<int, string>
{

	public:
	
	friend ostream& operator<<(ostream& o, const the_map& tm);
};