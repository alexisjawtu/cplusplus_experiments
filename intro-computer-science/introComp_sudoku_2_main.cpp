#include <iostream>
#include <fstream>
#include "listaInt.h"
#include "funciones.h"
#include <vector>

using namespace std;
int main()
{
	int ii,jj,kk;
    int ** s_dato;
	s_dato = new int*[9];
	for(ii=0; ii<9; ii++) {
		s_dato[ii] = new int[9];
    }
    ifstream sudoku_dato("C:\\temp\\sudoku\\bin\\Debug\\datos.txt");
    if (!sudoku_dato) {
        cout << "Poné bien la ruta completa del archivo";
        exit(1);
    }
    sudoku_dato.get();
    char x = sudoku_dato.peek();
    int i = 0;
    int j = 0;
    while (x != ']')
    {
        if (i < 9)
        {
            if (j < 9)
            {
                int num = 0;
                sudoku_dato >> num;
                s_dato[i][j] = num;
                x = sudoku_dato.peek();
                j ++;
                if (x == ',') sudoku_dato.get();
            }
            else
            {
                i ++;
                j = 0;
            }
        }
    }
    sudoku_dato.close();
    for (jj=0 ; jj<9 ; jj++)
    {
        for (kk=0 ; kk<9 ; kk++)
        {
            cout << s_dato[jj][kk] << ", ";
        }
    }
    int *** m_de_dato;
	m_de_dato = new int**[9];
	for (ii=0 ; ii<9 ; ii++)
    {
        m_de_dato[ii]  = new int*[9];
		for (jj=0 ; jj<9 ; jj++)
        { 
			m_de_dato[ii][jj]  = new int[9];
		}
	}
    for (ii=0 ; ii<9 ; ii++)
    {
        for (jj=0 ; jj<9 ; jj++)
        {
            for (kk=0 ; kk<9 ; kk++)
            {
                m_de_dato[ii][jj][kk] = 1;
            }
        }
    }
    vector < pair<int,int> > lugares__vacios;
    for (ii = 0; ii < 9; ii ++)
    {
        for (jj = 0; jj < 9; jj ++)
        {
            if (-1 != s_dato [ii][jj])
            {
                actualizar_matrices (m_de_dato, s_dato, ii, jj, s_dato [ii][jj]);
            }
            else lugares__vacios.push_back(make_pair(ii,jj));
        }
        //cout << endl;
    }

    for (ii = 0; ii < 9; ii ++)
    {
        for (jj = 0; jj < 9; jj ++)
        {
            cout << s_dato[ii][jj] << "'";
        }
    }

    cout << endl;

    for (ii = 0; ii < 9; ii ++)
    {
        for (jj = 0; jj < 9; jj ++)
        {
            for (kk = 0; kk < 9; kk ++)
            {
                cout << m_de_dato[ii][jj][kk] << "'";
            }
        }
    }

    listaInt nodos_sudoku;

    nodos_sudoku.ag_atras (lugares__vacios, s_dato, m_de_dato);

    NodoBi* nodo_actual = new NodoBi;
    while (nodos_sudoku.nodo_ultimo() != NULL)
    {
        //nodo_actual->lugares_vacios.push_back(make_pair(0, 0));
        nodo_actual = nodos_sudoku.nodo_ultimo();
        nodos_sudoku.sin_ultimo();

        int resu = es_hoja_o_solucion(nodo_actual->sudoku_actual, nodo_actual->matriz_de_factibilidad);
        cout << "RESU " << resu;
        if (resu == 0)
        {
            int fila__;
            vector <pair <int, int> > mi_vector = nodo_actual->lugares_vacios;

            pair <int, int> mi_par = mi_vector.back();
            fila__ = mi_par.first;
            int columna__ = mi_par.second;
            //nodo_actual->lugares_vacios.pop_back();
            mi_vector.pop_back();
            int *** mi_matriz = new int**[9];
            for (int t = 0; t < 9; t ++)
            {
                mi_matriz[t]=new int*[9];
				for (int u = 0; u < 9; u ++)
                {
                    mi_matriz[t][u]=new int[9];
					for (int v = 0; v < 9; v ++)
                    {
                        mi_matriz[t][u][v] = (nodo_actual->matriz_de_factibilidad)[t][u][v];
                    }
                }
            }
            int ** mi_matriz2 = new int*[9];
            for (int u = 0; u < 9; u ++)
            {
                mi_matriz2[u] = new int[9];
				for (int v = 0; v < 9; v ++)
                {
                    mi_matriz2[u][v] = (nodo_actual->sudoku_actual)[u][v];
                }
            }
            for (int k = 1; k<10; k++)
            {
                if ((mi_matriz[fila__][columna__][k-1]) == 1)
                {

  /*****************en cualquiera de estas dos lineas se detiene*************************/

                    nodos_sudoku.ag_atras(mi_vector, mi_matriz2, mi_matriz);
                    actualizar_matrices ((nodos_sudoku.nodo_ultimo())->matriz_de_factibilidad, (nodos_sudoku.nodo_ultimo())->sudoku_actual, fila__, columna__, k);

                }
            }
        }
        else if (resu == 2)
        {
            cout<<endl;
            for (int i =0; i<9; i++)
                {
                    for (int j=0; j<9; j++)
                    {
                        cout<<(nodo_actual->sudoku_actual)[i][j]<<" | ";
                    }
                    cout<<endl;
                }
                delete nodo_actual;
                //nodos_sudoku.~listaInt();
                //return 0;
                return 0;
        }
        delete nodo_actual;
    }
    return 0;
}
