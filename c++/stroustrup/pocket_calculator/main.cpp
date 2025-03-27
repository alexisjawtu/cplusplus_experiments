/**
 * Spurious global variable;
 * it stores the value of the last read NUMBER.
**/
double number_value;  

/**
 * Stores the value of the last read NAME.
**/
string string_value;

map<string, double> table;  // symbol table to be consulted.

enum Value_Symbol {
    /**
     * A value that specifies the nature of the symbol.
    **/
	NAME,
    NUMBER, // NUMBER is an integer or floating point literal
    END, PLUS='+', MINUS='-', MULT='*', DIV='/',
	PRINT=';', ASIGN = '='; LEFTP='(', RIGHTP=')'
};

Value_Symbol current_symbol = PRINT;

Value_Symbol get_symbol()
{
    char ch;
    do {  // skip spaces except for the line break.
        if(!cin.get(ch))   // the success here is when a char could not be read,
            return current_symbol = END;  // so we end the use of the calculator
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
        case ';':                          // these two indicate that we want
        case '\n':                         // to read the output, so PRINT
            return current_symbol = PRINT;
        default:
            if (isalpha(ch)) {
                string_value = ch;
                while (cin.get(ch) && isalnum(ch))
                    string_value.push_back(ch);
                cin.putback(ch);
                return current_symbol = NAME;
            }
            error("Not a valid symbol.");
            return current_symbol = PRINT;
    }
}

/*
Value_Symbol get_symbol()
{
    char ch = 0;
    cin >> ch;

    switch (ch) {
        case 0:
            return current_symbol = END;
        case ';':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return current_symbol = Value_Symbol(ch);
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
        case '.':
            cin.putback(ch);
            cin >> number_value;
            return current_symbol = NUMBER;
        default:
            if (isalpha(ch)) {
                cin.putback(ch);
                cin >> string_value;
                return current_symbol = NAME;
            }

            error("Not a valid symbol.");
            return current_symbol = PRINT;

    }
};
*/

double term(bool get)
{
	double left = prim(get);

	while (true)
	{
		switch (current_symbol) {
			case MULT:
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {
                    left /= d;
                    break;
                }
                return error ("Division by zero");
            default:
                return left;
		}

	}
}

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





double prim(bool get)
{
    if (get) get_symbol();

    switch(current_symbol) {
        case NUMBER:            // floating point constant
        {
            double v = number_value;
            get_symbol();
            return v;
        }

        case NAME:
        {
            double& v = table[string_value];
            if (get_symbol() == ASIGN)
                v = expression(true);
            return v;
        }

        case MINUS:             // unitary minus
            return -prim(true);

        case LEFTP:
        {
            double e = expression(true);
            if (current_symbol != RIGHTP)
                return error("Expected ).");

            get_symbol();  // jump ')'
            return e;
        }

        default:
            return error("Expected primary expression.");
    }
}

