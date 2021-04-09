
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cifrado
{
    int filas;
    int columnas;
public:
    cifrado(int f, int c) : filas(f), columnas(c) {}
    string cifrar(string);
    string descifrar(string);

};

string cifrado::cifrar(string mensaje)
{
    int l = filas * columnas;
    string mencif;

    int aux = 0;
    for (int a = 0, i = 0; i < l; a++, i += filas)
    {
        for (; aux < l; aux += columnas)
            mencif += mensaje[aux + a];
        aux = 0;
    }
    return mencif;
}

string cifrado::descifrar(string mensaje)
{
    int l = filas * columnas;
    string mencif;

    int aux = 0;
    for (int a = 0, i = 0; i < l; a++, i += columnas)
    {
        for (; aux < l; aux += filas)
            mencif += mensaje[aux + a];
        aux = 0;
    }
    return mencif;
}

string completarMensaje(string mensaje, int f, int c)
{
    for (int i = mensaje.length(); i < f * c; i++)
        mensaje.insert(i, " ");
    return mensaje;
}


int main()
{
    int a, b;
    string frase;
    cout << "      INGRESE LA FRASE QUE QUIERE CIFRAR Y LAS DIMENSIONES: " << endl;
    cout << "FRASE: " << endl;
    cin >> frase;
    cout << endl;
    cout << "DIMENSIONES: ";
    cin >> a;
    cin >> b;
    cifrado uno(a, b);
    cout << endl;
    cout << "   Frase cifrada: " << uno.cifrar(completarMensaje(frase, a, b));



}

