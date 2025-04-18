/** 
 * 
 * Namespaces can even extend across different translation units 
 * (i.e., across different files of source code).
 *
 * The STORAGE of variables with global or namespace scope is allocated for the
 * entire duration of the program, which is known as STATIC STORAGE.
 * 
 *              - uninitialized variables are set to ZERO.
 * 
 * The STORAGE for local variables is allocated only for its containing block.
 * This is called AUTOMATIC STORAGE.
 * 
 *              - uninitialized variables are left undetermined.
 * 
 * 
 * []: these brackets are a dereferencing operator known as offset operator. 
 *     They dereference the variable they follow just as * does, but they 
 *     also add the number between brackets to the address being dereferenced.
 * 
 * 
 * const: una variable const es read-only.
 *
 * 
 * Dynamic Memory: there may be cases where the memory needs of a program can only be
 *                 determined during runtime. For example, when the memory needed 
 *                 depends on user input. 
 * 
 *                 On these cases, programs need to dynamically allocate memory.
 * 
 *                 There is a substantial difference between declaring a normal
 *                 array and allocating dynamic memory for a block of memory
 *                 using new. The most important difference is that the size of
 *                 a regular array needs to be a constant expression, and thus
 *                 its size has to be determined at the moment of designing the
 *                 program, before it is run, whereas the dynamic memory
 *                 allocation performed by new allows to assign memory during
 *                 runtime using any variable value as size.
*/

#include <chrono>
#include <string>
#include <thread>
#include <sstream>
#include <iostream>


using namespace std;


inline string concatenate(const string& a, const string& b)
{
    return b + " y " + a;
}


void even(int);
inline string concatenate(const string&, const string&);


template <class T> void print(T data)
{
    cout << boolalpha << data << "\n";
}


template <class T> void print_vector(T& v)
{
    for (auto& d: v)
    {
        cout << boolalpha << d << ", ";
    }
    cout << "\n";
}


void basicio()
{
    double rational {0.};
    int number {0};
    string inputstring;

    getline(cin, inputstring);

    this_thread::sleep_for(chrono::seconds(1));

    stringstream(inputstring) >> number;
    cout << number << "\n";

    int c {0};

    for ( ; ; )
    {
        cout << number << " ";
        c++;
        if (c > 4) break;
    }

    for (char d: "hola")
        printf("%c ", d);

    cout << "\n";
}


void duplicate(int& a)
{
    a = a * 2;
}


void odd(int a)
{
    if ((a % 2) != 0) cout << "ODD\n";
    else even(a);
}


void even(int a)
{
    if ((a % 2) == 0) cout << "EVEN\n";
    else odd(a);
}


namespace foo
{
    const double seven = 7.;
    int eight {8};
    int value() { return 5; }
}


namespace bar
{
    int value() { return 3; }
}


int z;  // global, static


int main_arrays ()
{
    {
        using namespace foo;
        cout << "foo " << value() << "\n";
    }
    {
        using namespace bar;
        cout << "bar " << value() << "\n";
    }

    int zz;

    int elements;
    print(elements);
    int vec[3] = {};  // all zeros

    int vec2 [] = { 0, -5, 2, 2 };  // implicit size

    int vec3 [] { 4, 4, 8, -7 };

    print(vec[0]);

    return 0;
}


int main_char_secs () 
{

    /**

     * null char \0 is appended automatically to string literal constants.
      
     * main.cpp:139:21: error: initializer-string for char array is too long
           char word [3] = "alo";
     *                      ^~~~~

    */
    char word [4] = "alo";  

    char word2 [14];
    word2[2] = 'x';
    word2[0] = '2';
    word2[1] = '1';
    print(word2);


    char someword [] {'a', 'l', 'o', '\0'};

    string aword {"otra vez"};

    string bword;
    bword = string(word2);

    print(word);
    int vec [] = { 1,2,3 };
    print(vec);
    print(aword.data());  // to C string

    print(bword);

    return 0;
}


int main_ptrs ()
{
    int a = 47;
    int b = -70;
    int* address;

    address  = &a;
   *address -= 1;

    address  = &b;
   *address += 3;

    cout << a << " " << b << "\n\n";

    int myarray[20];
    int* mypointer;

    mypointer = myarray;

    *mypointer = 37;

    cout << mypointer << "\n" << &(myarray[1]) << "\n" << &myarray[2] << "\n"
         << myarray[0] << "\n";

    mypointer = mypointer + 5;
    cout << mypointer << "\n";

    return 0;
}


void main_ptrs_2 ()
{
    int numbers[5];

    int* p;

    p = numbers;     *p = 7;

    print_vector(numbers);

    p++;             *p = 17;

    print_vector(numbers);

    p = &numbers[3]; *p = 13;

    print_vector(numbers);

    p = numbers + 2; *p = 19;  // numbers ~ numbers[0]

    print_vector(numbers);

    p = numbers;     *(p + 4) = 11;

    print_vector(numbers);

    int myvar;

    int* ptr;

    ptr = &myvar;

    int* ptr2 = ptr;

    print(ptr);

    print(ptr2);
}


void main_ptrs_3 ()
{
    char c = 'e';
    short s = 17;
    long l = 99;
    
    char* mychar = &c;
    short* myshort = &s;
    long* mylong = &l;
    
    print(mychar);
    print(myshort);
    print(mylong);     

    ++mychar;
    ++myshort;
    ++mylong;

    print(mychar);
    print(myshort);
    print(mylong);
}


void main_ptrs_4()
{
    int i = 2;
    const int * p;
    p     = &i;
    int x = *p;
    print(p);
    print(x);
    p     = &x;
    print(p);
}


void print_all (const int* start, const int* stop)
{
                         // Aca const quiere decir que current no modifica, mediante
    const int* current;  // una desreferencia, el valor de aquello a lo que apunta
                         // Sin embargo, current SI si puede modificar; el puntero
                         // no es constante.

    current = start;

    while (current != stop) {
        print(*current);
        ++current;
    }
}


void increment_all (int* start, int* stop)
{
    int* current = start;
    while (current != stop) {
        *current += 7;
        ++current;
    }
}


void pointers_as_arguments ()
{
    int vec[] {3, -5, 8};
    increment_all(vec, vec + 3);
    print_all(vec, vec + 3);
}


void pointers_and_string_literals () {
    const char* foo = "helio";
    print(*(foo + 2));
    print(foo[4]);}


void pointer_pointers () {
    int a;
    int * b;
    int ** c;

    a = 3;
    b = &a;
    c = &b;

    print(c);
    print(*c);
    print(b);
    print(&a);
    print(**c);}


int void_null_and_invalid_pointers () {
    float f {4.0};
    int i {4};
    void * v = &f;
    print(v);

    int * p = 0;
    int myarray[10];

    int * q = nullptr;
    double * d = 0;

    print(nullptr == 0);
    print(f == i);

    return 0;}


int addition (int a, int b) { return a + b; }


int subtraction (int a, int b) { return a - b; }


int operation (int x, int y, int (*functocall) (int, int))
{
    int g;
    g = (*functocall)(x, y);
    return g;
}


int main__ ()
{
    int u = 18;
    int v = 47;

    int (*difference) (int, int) = subtraction;

    print(operation(u, v, addition));
    print(operation(u, v, difference));

    return 0;
}


int main_dynamic_memory ()
{
    // Dynamic Memory
    int dim;
    string in;
    getline(cin, in);
    stringstream(in) >> dim;
    int * foo;
    foo = new int [dim];

    foo[3] = -7;
    *foo = 2;
    *(foo + 4) = 17;

    print_all(foo, foo + dim);

    delete foo;

    int dim2;
    getline(cin, in);
    stringstream(in) >> dim2;
    int * bar = new int [dim2];
    if (bar == nullptr) {
        print("null");
    }
    else {
        print(dim2);
    }
    delete[] bar;
    return 0;
}


/*
    Classes are either class or struct.
    Structs are only for grouping data under a name.
*/

struct movie
{
    string country;
    string director;
    string name;
    int year;
} first, second, films[3];


void print_movie (movie mv)
{
    print(mv.name);
    print(mv.director);
    print(mv.year);
}


class Alosha {
    // same class or friends. Specifier private is by default, so we can omit it.
    int a;
    
    public:  // anywhere where the object is visible
        int b;
    protected:  // same class, derived classes of friends
        int c;
};


class Rectangle {

    int width;  // members default to private
    int height;

    public:
        Rectangle() {
            print("***default constructor***");
            width = 0;
            height = 0;
        }
        Rectangle(int w, int h) {
            print("***parametric constructor***");
            width = w;
            height = h;
        }
        void set_values(int, int);
        int area();
        int perimeter() {
            return 2 * width + 2 * height;
        }
};


// :: is the scope operator
// it grants the access to the private data of the class!
void Rectangle::set_values(int w, int h) {
    width = w;
    height = h;
}


int Rectangle::area() {
    return width * height;
}


class Square {
    int edge;

    public:
        Square (int e) { edge = e; }
        int area () {
            return edge * edge;
        }
};


int main_classes_I_a ()
{
    // structs
    struct example
    {
        int member_one;
        string member_two;
    } boris, jawtu;

    example alexis;

    first.name = "Ivan the Terrible";
    first.director = "Sergei Eisenstein";
    first.year = 1947;

    print_movie(first);

    films[1].name = "The Shining";

    print_movie(films[1]);
    
    Alosha alex;

    print("no args. Rectangle r0{};");
    Rectangle r0{};
    print(r0.area());
    print(r0.perimeter());

    Rectangle r1(7, 4);
    print(r1.area());
    print(r1.perimeter());

    print("hi");
    Rectangle r = Rectangle(13, 5);
    print(r.area());


    print("unique parameter in constructor:");

    Square sq = 2;
    
    printf("area of sq: %d\n", sq.area());
    printf("g\n");

    // following is uniform initialization
    Rectangle r2 = {3, 4};
    printf("area of r2: %d\n", r2.area());

    Rectangle r3 {4, 5};
    printf("area of r3: %d\n", r3.area());

    return 0;
}


int main_classes_I_b ()
{
    Rectangle obj = Rectangle(3, 4);
    Rectangle * foo;
    foo = &obj;
    print(obj.area());
    print((*foo).area());
    print(foo -> area());


    /*
        first experiment:
        two pointer declarations are apparently contiguous in static memory

            0x7ffe96308410
          - 0x7ffe96308408
          ----------------
            0x000000000008  eight bytes
    */
    Rectangle * bar;  // declaration. before initialization
    Rectangle * baz;
    print(bar);       // here we have the value 0, the null pointer.
    print(&bar);      // here es the address where the pointer is.
    print(&baz);      // and this address is contiguous

    Rectangle * r0;
    print(&r0);       // and this address is contiguous too

    /*
        second experiment: initialization and deletion.
        now the pointer contains an address.
    */
    bar = new Rectangle(5, 6);
    print(bar);  // the value is an address. The address of an object.
    delete bar;
    print(bar);  // keeps the 'new' address after deletion
    print(&bar); // and keeps it's own address

    baz = new Rectangle[2] { {2, 5}, {3, 6} };  // a 'regular' array
    r0  = new Rectangle;
    print(r0);
    print(baz);         // Here we print values. Both yield the same address, because an array is
    print(&(baz[0]));   // similar to a pointer that stores the address to the first
                        // element of the array.
    print(baz -> area());  // 10, the Rectangle in the first place.

    // Now, it is the same address as the Rectangle once stored in the deleter bar !!!    
    // so be careful with this:
    print(bar -> area());
    bar -> set_values(78, -2);
    print(baz -> area());

    return 0;
}


/*
    Third experiment.
    Now we delete and initialize an object of another class
*/
int main_classes_I_c ()
{
    /*
        We may suspect that the dynamic memory is reutilized in an ordered way.
        But what is what 'delete' really does?
    */
    Rectangle * bar;
    bar = new Rectangle(5, 6);
    print("=========================Address of bar======================");
    print(&bar); // it's own address
    print("=========================Address in bar======================");
    print(bar);  // the value is an address. The address of an object.
    print(bar -> perimeter());
    print(bar -> area());
    delete bar;

    print("=========================Address of bar post delete =========");
    print(&bar); // keeps it's own address
    print("=========================Address in bar post delete =========");
    print(bar);  // keeps the 'new' address after deletion

    Square * s;
    s = new Square(4);
    print("=========================Address of s======================");
    print(&s);
    print("=========================Address in s======================");
    print(s);
    print(s -> area());
    print("=========================Address of bar post s =========");
    print(&bar); // keeps it's own address
    print("=========================Address in bar post s =========");
    print(bar);  // keeps the 'new' address after deletion

    print(bar -> area());
    return 0;
}


class My_Class {
    string product;
    float price;

    public:
        string get_product () {
            return product;
        }
      
        float get_price () {
            return price;
        }
        My_Class operator+(My_Class m);

        My_Class () {};
        My_Class (string p, float pr) {
            product = p;
            price = pr;
        }

};

My_Class My_Class::operator+ (My_Class m) {
    return My_Class(product + m.product, price + m.price);
} 

int main_classes_I_d ()
{
    My_Class p2;
    My_Class p0 = My_Class ("piano", 7320);
    My_Class p1 = My_Class ("bench", 1);

    p2 = p0 + p1;

    print(p2.get_price());
    print(p2.get_product());
    
    return 0;
}



#include <iomanip>

int main_quoted ()
{
    cout << "dcv2" << " " << quoted("dcv2") << '\n';
    return 0;
}

int main () {
    cerr << "Test of cerr stream\n";
}
