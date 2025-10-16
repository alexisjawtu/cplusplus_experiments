enum Value_Symbol {
NAME, NUMBER,  END, PLUS=+, MINUS='-', MULT='*', DIV='/',
PRINT=';', ASIGN = '='; LEFTP='(', RIGHTP=')'
};

Value_Symbol current_symbol = PRINT;

Value_Symbol get_symbol() {};

double expression(bool get)
{
    double left = term(get);

    for (;;)
    {
        switch (current_symbol) {
            case PLUS:
                left += term(true);
                break;

            case MINUS:
                left -= term(true);
                break;

            default:
                return left;
        }
    }
}
