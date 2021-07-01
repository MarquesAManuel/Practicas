/*
CORRECCION:
Lo unico que se me ocurre que esta mal es que no le agrego una opcion para que el usuario salga del programa
entonces cuando ejecuta el .exe nunca lo va a poder ver,se cierra en el momento que termina de leerlo.
Tambien le falto el .close para cerrar el archivo cuando se termine de usar.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in;
    in.open("QuotesOfBjarne.txt");

    //if (!in) throw "Error opening file";
    if (!in)
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    while (!in.eof())
    {
        string line;
        getline(in, line);
        cout << line << endl;
        cout << endl;
    }
    in.close();

    cin.ignore();
    cin.get();

    return 0;
}
