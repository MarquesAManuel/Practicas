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

int countWords(string sentence)
{
    int i = 0; 
    int counter = 1;

    while (i < sentence.length())
    {
        if (sentence[i] == ' ')
        {
            counter++;
        }
        i++;
    }
    return counter;
}

int main()
{
    ifstream in;
    in.open("QuotesOfBjarne.txt");
    if (!in){ cerr << "Error opening file" << endl; exit(EXIT_FAILURE); }

    int sentecesNumber = 0;
    int totalWords = 0;
    
    while (!in.eof())
    {
        string sentence;
        getline(in, sentence);
        int wordsPerSetence = countWords(sentence);
        cout << "La frase número " << sentecesNumber+1 << " tiene " << wordsPerSetence << " palabras" << endl;

        totalWords += wordsPerSetence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;

    in.close();

    cin.ignore();
    cin.get();

    return 0;
}