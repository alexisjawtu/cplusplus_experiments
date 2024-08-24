#include "the_map.h"

ostream& operator<<(ostream& o, const the_map& tm) 
{
	for (auto& i: tm) {
		o << i.first << ", " << i.second << endl;
	}

	return o;
}