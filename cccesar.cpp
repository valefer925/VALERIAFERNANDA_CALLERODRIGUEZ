#include <iostream>
#include <string>

using namespace std;

class cesar
{
    string alfabeto = "abcdefghijklmnopqrstuwxyz";
    int clave;
public:
    cesar(int);
    string cifrado(string);
    string descifrado(string);
};

cesar::cesar(int c)
{
    clave = c;
}

string cesar::cifrado(string m)
{
    int tm = m.length();
    string mc;
    for (int i = 0; i < tm; i++)
    {
        if (m[i] == ' ')
            mc += " ";
        else
        {
            int p = alfabeto.find(m[i]);
            int aux = p + clave;
            if (aux > 26)
                aux -= 25;
            mc += alfabeto[aux];
        }
    }
    return mc;
}

string cesar::descifrado(string mc)
{
    int tmc = mc.length();
    string md;
    for (int i = 0; i < tmc; i++)
    {
        if (mc[i] == ' ')
            md += " ";
        else
        {
            int p = alfabeto.find(mc[i]);
            int aux = p - clave;
            if (aux < 0)
            {
                if (aux == -1)
                    aux = 0;
                else
                    aux += 25;
            }
            md += alfabeto[aux];
        }
    }
    return md;
}

class brCesar
{
    string alfabeto = "abcdefghijklmnopqrstuwxyz";
public:
    brCesar();
    int contar(char, string);
    int buscarClave(string);
    string descifrar(string);
};

brCesar::brCesar() {}
int brCesar::contar(char l, string m)
{
    int tam = m.length();
    int contador = 0;
    for (int i = 0; i < tam; i++)
    {
        if (m[i] == l)
            contador++;
    }
    return contador;
}
int brCesar::buscarClave(string m)
{
    int tam = m.length();
    int a = contar(m[0], m);
    int b;
    char e = m[0];
    for (int i = 0; i < tam; i++)
    {
        if (m[i] != m[i - 1])
            b = contar(m[i], m);
        if (b > a)
        {
            a = b;
            e = m[i];
        }
        cout << e << endl;
    }
    return alfabeto.find(e) - 4;
}

string brCesar::descifrar(string mc)
{
    int tmc = mc.length();
    string md;
    for (int i = 0; i < tmc; i++)
    {
        if (mc[i] == ' ')
            md += " ";
        else
        {
            int p = alfabeto.find(mc[i]);
            int aux = p - buscarClave(mc);
            if (aux < 0)
            {
                if (aux == -1)
                    aux = 0;
                else
                    aux += 25;
            }
            md += alfabeto[aux];
        }
    }
    return md;
}

int main()
{
    cesar emisor(4);
    string m;
    getline(cin, m);
    cout << endl;
    cout << emisor.cifrado(m) << endl;
    brCesar emisor2;
    string a = "ixyi ix zr gmjwehs hi twzife";
    cout << emisor2.buscarClave(a) << endl;
    cout << emisor2.descifrar(a) << endl;

}