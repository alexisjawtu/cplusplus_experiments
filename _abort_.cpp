#include <iostream>


int main ()
{

	std::cout << "Calling abort. " << "\n";
    ::abort();
    std::cout << "Reache test line." << "\n";

	return 0;

}
