#include <iostream>
#include <string>


using namespace std;


// class template
template <class T>
class mycontainer {
  public:
	T element;
  	mycontainer (T arg) {
  		this -> element = arg;
  	}

  	T increase () {
  		return ++(this -> element);
  	}
};

// class template specialization
template <>
class mycontainer <char> {
  public:
	char element;
  	mycontainer (char arg) {
  		this -> element = arg;
  	}

  	char uppercase () {
  		// check wether it is a lower case character
  		if ((element >= 'a') && (element <= 'z'))
  			// translation to the upper case side
  			element = element + 'A' - 'a';
  		return this -> element;
  	}
};


template <class T> void print(T data)
{
    std::cout << std::boolalpha << data << "\n";
}


int main () {

	mycontainer<float> f (4.8);
	mycontainer<char>  c ('e');

	print(f.element);
	print(c.element);

	float testf = f.increase();
	char  testc = c.uppercase();
	
	print(f.element);
	print(c.element);
	
	print(testf);
	print(testc);

	return 0;
}
