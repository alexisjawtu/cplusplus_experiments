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
        Token (char k): kind{k}, value{0.0} {}
        Token (char k, double v): kind{k}, value{v} {}
};

//------------------------------------------------------------------------------

class Token_stream
{
    // get()
    // put_back()
};

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

Token_stream ts;

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

//------------------------------------------------------------------------------

/*
int first_version_main ()
{
    cout << "Expression (x to end) ";
    int lval {0};
    int rval {0};
    cin >> lval;
    if (!cin)
        error ("missing 1st. operand");

    for (char op; cin >> op; )
    {
        if (op != 'x')
            cin >> rval;
        if (!cin)
            error ("missing 2nd. operand");

        switch (op)
        {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result " << lval << '\n';
                return 0;
        }
    }

    error ("wrong expression");

    return 0;
}
*/
