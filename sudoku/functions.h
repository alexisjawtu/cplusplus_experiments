#ifndef _FUNCTSSUD_H_
#define _FUNCTSSUD_H_

#include <iostream>
#include <fstream>

using namespace std;

void load_the_data();
pair <int,int> square_corner(int square_index);
int which_square(int row, int col);
bool check(int i, int j, int k);
void solve(int i, int j);

#endif
