#include "listaInt.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*int es_solucion (int s[9][9])
{
    for (int i = 0; i <9; i ++)
    {
        for (int j = 0; j <9; j ++)
        {
            if (s[i][j] == -1) return 0;
        }
    }
    return 1;
}*/

int es_hoja_o_solucion (int s[9][9], int m[9][9][9])
{
    int cuantos_vacios = 0;
    for (int i = 0; i <9; i++)
    {
        for (int j = 0; j <9; j++)
        {
            if (s[i][j] == -1)
            {
                cuantos_vacios ++;
                int k=0;
                while (k<9 && m[i][j][k] == 0)
                {
                    k++;
                }
                if (k == 9)
                {
                    return 1;
                }
            }
        }
    }
    if (cuantos_vacios > 0) return 0;
    return 2;
}

int que_cuadrado( int fila, int columna)
{
    if (fila<3)
    {
        if (columna <3)return 1;
        else if (columna <6)return 2;
        else return 3;
    }
    else if( fila<6)
    {
        if (columna <3)return 4;
        else if (columna <6)return 5;
        else return 6;
    }
    else
    {
        if (columna <3)return 7;
        else if (columna <6)return 8;
        else return 9;
    }

}

pair <int,int> extremos_del_cuadrado (int numero_de_cuadrado)
    {
        switch (numero_de_cuadrado)
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

void actualizar_matrices (int *** m, int ** s, int fila, int columna, int valor)
{
    int l;
	s[fila][columna]=valor;
    for (l=0; l<9; l++)
    {
        m[fila][l][valor] = 0;
    }
    for (l=0; l<9; l++)
    {
        m[l][columna][valor]=0;
    }
    int min_fila = extremos_del_cuadrado (que_cuadrado(fila,columna)).first;
    int min_col = extremos_del_cuadrado (que_cuadrado(fila,columna)).second;

    for (l = min_fila; l < min_fila + 3; l ++)
    {
        for (int h = min_col; h < min_col + 3; h ++)
        {
            m[l][h][valor] = 0;
        }
    }
    for (int k = 0; k < 9; k ++)
    {
        m[fila][columna][k] = 0;
    }
}

/*ostream& operator<<(ostream& f,const int l[9][9])
{
    for (int m = 0; m < 9; m ++)
    {
        f << "|" << l[m][0];
        for (int n = 1; n < 9; n ++)
        {
            f << "," << l[m][n];
        }
        f << "|" << endl;
    }
    return f;
}

istream& operator>>(istream& is, int l[9][9])
{
    for (int n = 0; n < 9; n ++)
    {
        is.get();
        char c=is.peek();
        for (int m = 0; m < 9; m ++)
        {
            int valor = 0;
            is >> valor;
            l[n][m] = valor;
            c=is.peek();
            if(c == ',')
            {
                is.get();
            }
        }
    }
    return is;
}*/
