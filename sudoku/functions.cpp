#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int matrix_data[9][9];

void load_the_data()
{
    string file_name;
    cout << "Input file: ";
    cin  >> file_name;

    ifstream input_file(file_name);
    
    if (!input_file) {
        cout << "ERROR. Could not load data. Check the path.";
        exit(1);
    }
    input_file.get();
    char x = input_file.peek();
    int  i = 0;
    int  j = 0;
    while (x != ']')
    {
        if (i < 9)
        {
            if (j < 9)
            {
                int num = 0;
                input_file >> num;
                matrix_data[i][j] = num;
                x = input_file.peek();
                j ++;
                if (x == ',') input_file.get();
            }
            else
            {
                i ++;
                j = 0;
            }
        }
    }
    input_file.close();
}

pair <int,int> square_corner (int square_index)
{
    // Assignment: this could be a fixed container to read from.
    switch (square_index)
    {
        case 1:
           return make_pair(0,0);
           break;
        case 2:
           return make_pair(0,3);
           break;
        case 3:
           return make_pair(0,6);
           break;
        case 4:
           return make_pair(3,0);
           break;
        case 5:
           return make_pair(3,3);
           break;
        case 6:
           return make_pair(3,6);
           break;
        case 7:
           return make_pair(6,0);
           break;
        case 8:
           return make_pair(6,3);
           break;
        default:
           return make_pair(6,6);
    }
}

int which_square(int row, int col)
{
    if (row < 3)
    {
        if (col < 3) return 1;
        else if (col < 6) return 2;
        else return 3;
    }
    else if (row < 6)
    {
        if (col < 3) return 4;
        else if (col < 6) return 5;
        else return 6;
    }
    else
    {
        if (col < 3) return 7;
        else if (col < 6) return 8;
        else return 9;
    }
}

bool check (int i, int j, int k)
{
    for (int l = 0; l < 9; l++)
    {
        if (l != i && matrix_data[l][j]==k) return 0;
    }
    for (int t = 0; t < 9; t++)
    {
        if (t != j && matrix_data[i][t]==k) return 0;
    }
    pair<int,int> par = square_corner (which_square(i,j));
    int n = par.first;
    int m = par.second;
    for (int u = n; u < n + 3; u ++)
    {
        for (int v = m; v < m + 3; v++)
        {
            if ((u != i || v != j) && matrix_data[u][v] == k) return 0;
        }
    }
    return 1;
}

void solve(int i, int j)
{
    if (j == 9)
    {
        solve(i+1, 0);
        return;
    }
    if (i == 9)
    {
        cout << "Result: " << endl;
        for (int z = 0; z < 9; z++)
        {
            for (int y = 0; y < 9; y++)
            {
                cout << matrix_data[z][y] << " | ";
            }
            cout << endl;
        }
	/**
	 * Question: why do we need an exit here?
	 *
	**/
        exit(0);
    }
    if (matrix_data[i][j] > 0)
    {
        // cout << "(" << i << "," << j << ")"; // visualizar progreso
        solve(i, j+1);
        return;
    }
    for (int k = 1; k < 10; k++)
    {
        matrix_data[i][j] = k;
        if (check(i, j, k))
        {
            // cout << "(" << i << "," << j << ")"; // visualizar progreso
            solve(i, j+1);
        }
    }
    matrix_data[i][j] = 0;
}
