
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cifrado       //se crea la clase cifrado que tendra las funciones necesarias
{
    int filas;
    int columnas;
public:
    cifrado(int f, int c) : filas(f), columnas(c) {}
    string cifrar(string);
    string descifrar(string);

};

string cifrado::cifrar(string mensaje)      //imprementamos la funcion cifrar
{
    int l = filas * columnas;       //hallamos el largo total del string 
    string mencif;      //creamos la variable para guardar el mensaje cifrado

    int aux = 0;
    for (int a = 0, i = 0; i < l; a++, i += filas)     //recorremos el string saltando de columna en columna
    {
        for (; aux < l; aux += columnas)        //aquí lo recorremos saltando de fila en fila
            mencif += mensaje[aux + a];     //se va llenando el cifrado
        aux = 0;
    }
    return mencif;
}

string cifrado::descifrar(string mensaje)   //operacion inversa al cifrado 
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

string completarMensaje(string mensaje, int f, int c)       //esta funcion nos sirve para completar los 
{                                                           //posibles espacios en blanco que puedan haber
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

