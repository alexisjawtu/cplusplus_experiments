#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

int es_hoja_o_solucion (int s[9][9], int m[9][9][9]);
pair <pair <int,int>, pair <int,int> > extremos_del_cuadrado (int numero_de_cuadrado);
void actualizar_matrices (int *** m, int ** s, int fila, int columna, int valor);
/*pair <int,int> con_cual_seguir(int s[9][9]);*/
/*ostream& operator<<(ostream& f,const int l[9][9]);
istream& operator>>(istream& is, int l[9][9]);*/

#endif
