#include <iostream>

using namespace std;

#define MAX 10

int main()
{
    char nombre[MAX];
    cin >> nombre;
    cout << endl << "El nombre es: " << nombre << endl << endl;
    for (int i=0; i < MAX; i++)
    {
        cout << "ascii de " << nombre[i] << ": " << (int) nombre[i] << endl;
    }
    return 0;
}
//(int) nombre[i]; devuelve el ascci del char nombre[i]
