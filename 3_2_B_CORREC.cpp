/*
Ya le agregue la funcion closeFile y por si las dudas agregue
el ignore y el get que nos enseño porque se sigue cerrando apenas se ejecuta el .exe
puede ser que sea un problema de windows eso.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream openFile(string path)
{
    ifstream in;
    in.open("QuotesOfBjarne.txt");

    if (!in) 
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return in;
}

void showQuotesOf(ifstream file)
{
    while (!file.eof())
    {
        string line;
        getline(file, line);
        cout << line << endl;
        cout << endl;
    }
}
void closeFile(string path)
{
    ifstream out;
    if (!out.eof())
    {
        out.close();
        cout <<"El archivo se cerro satisfactoriamente"<< endl;
    }
    
}

int main()
{
    showQuotesOf(openFile("QuotesOfBjarne.txt"));
    closeFile("QuotesOfBjarne.txt");
    cin.ignore();
    cin.get();
    return 0;
}