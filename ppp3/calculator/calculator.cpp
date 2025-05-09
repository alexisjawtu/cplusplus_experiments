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

// Each function deals with a specific part of an expression and leaves everything else to other
// functions. This radically simplifies each function.



double expression()
{
    double left = term();
    Token t = get_token();

    while (true)
    {
        switch (t.kind)
        {
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}
double term() {};
double primary() {};

Token get_token()
{
    return Token {'*'};
}


vector<Token> tok;


int main ()
{
    while (cin)
    {
        Token t = get_token();
        tok.push_back(t);
    }
}


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
