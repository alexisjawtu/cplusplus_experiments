/*
	when the preprocessor finds a #include directive it
	replaces it by the entire content of the specified header or file.
*/
#include <iostream>  
#include <string>

#define TABLE_SIZE 100
#define INTEGER int 
#define getmax(a, b) ((a) > (b) ? (a) : (b))
#define str(x) #x
#define glue(a, b) a ## b


using namespace std;


/*

	a macro expansion. 

		#define identifier expression

	The preprocessor does not understand c++. It simply
	replaces every instance of identifier with expression

	The preprocessor directives are executed before any cpp syntax
	check. We show an example here using the word INTEGER :)

*/


INTEGER table1[TABLE_SIZE];
INTEGER table2[TABLE_SIZE];


INTEGER main () 
{

	INTEGER x;
	INTEGER y = 11;

	x = getmax(y, 9);

	cout << x << "\n";
	cout << getmax(14, 17) << "\n";

	x = getmax(y, 23);
	cout << x << "\n";

	// with the str() macro we can inspect the variable name in the output console.
	cout << str(boris) << "\n";

	//double hash ## concatenates
	glue(c, out) << "alex" << "\n";  // this writes cout to the code!! :)

	/*
		// line control for compiling errors display
		#line 20 "assignment of variable"
		int z?;
	*/

	// Predefined macro names
	
	cout << __LINE__ << "\n";
	cout << __FILE__ << "\n";
	cout << __DATE__ << "\n";
	cout << typeid(__TIME__).name() << "\n";
	cout << typeid("the computers").name() << "\n";
	cout << typeid("the").name() << "\n";
	cout << "simple quotes " << typeid('t').name() << "\n";
	cout << "double quotes " << typeid("t").name() << "\n";
	cout << __cplusplus << "\n";
	cout << __STDC_HOSTED__ << "\n";

	string str_time = string(__TIME__);
	string str_date = string(__DATE__);

	str_time[2] = '_';
	str_time[5] = '_';

	str_date[3] = '_';
	str_date[6] = '_';

	cout << str_date << '_' << str_time << "\n";
	cout << __DATE__ << '_' << __TIME__ << "\n\n";

	cout << __STDC__ << '\n';
	// cout << __STDC_VERSION__ << '\n';
	// cout << __STDC_MB_MIGHT_NEQ_WC__ << '\n';
	cout << __STDC_ISO_10646__ << '\n';
	// cout << __STDCPP_STRICT_POINTER_SAFETY__ << '\n';
	cout << __STDCPP_THREADS__ << '\n';

	return 0;

}
