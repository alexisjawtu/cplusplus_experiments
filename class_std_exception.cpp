#include <iostream>
#include <exception>


/*
    first option with a struct
    second option with a class
*/


struct ooops: std::exception {

	virtual const char* what() const noexcept {
		return "the ooops!\n";
	}

};


class MyException: public std::exception {

    virtual const char* what() const throw() {
        return "My exception\n";
    }

};


int main ()
{

    ooops err;
    MyException err2;

	try {

		throw err;

	} catch (std::exception& ex) {

		std::cout << ex.what();

	}

	std::cout << "Flow continuation checkpoint\n";

    try {

        throw err2;

    } catch (std::exception& ex2) {

        std::cout << ex2.what();

    }

    std::cout << "Flow continuation checkpoint 2\n";

	return 0;

}
