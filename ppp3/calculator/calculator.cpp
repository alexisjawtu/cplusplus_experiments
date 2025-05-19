//
// Each function deals with a specific part of an expression and leaves everything else to other
// functions. This radically simplifies each function.
//
#include "PPPheaders.h"


using namespace std;


class Token
{
    public:
        char kind;
        double value;
        Token (char k)
            : kind{k}, value{0.0} { }
        Token (char k, double v)
            : kind{k}, value{v} { }
};

//------------------------------------------------------------------------------

class Token_stream
{
    public:
        Token get();
        void put_back(Token t);
    private:
        bool full {false};
        Token buffer = {'0'};
};

void Token_stream::put_back(Token t)
{
    if (full) error("put_back into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch)
    {
        case ';':  // print
        case 'q':  // quit
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch};
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
                cin.put_back(ch);
                double val;
                cin >> val;
                return Token{'8', val};
            }
        default:
            error("Bad Token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------

double expression()
{
    double left = term();
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.put_back(t);
                return left;
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0)
                    error ("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.put_back(t);
                return left;
        }
    }
}

//------------------------------------------------------------------------------

double primary()
{
    Token t = ts.get();

    switch (t.kind)
    {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                error ("')' expected"); 
            return d;
        }

        case '8':
            return t.value;

        default:
            error ("primary expected");
    }
}

//------------------------------------------------------------------------------


int main ()
{
    try
    {
        double val {0};
        while (cin)
        {
            Token t = ts.get();
            if (t.kind == 'q')
                break;
            if (t.kind == ';')
                cout << '=' << val << '\n';
            else
                ts.put_back(t);
            val = expression();
        }
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Exception \n";
        return 2;
    }
}
