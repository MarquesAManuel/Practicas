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
    in.open(path);

    if (!in)
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return in;
}

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

void showWordsOf(ifstream& file)
{
    int sentecesNumber = 0;
    int totalWords = 0;

    while (!file.eof())
    {
        string sentence;
        getline(file, sentence);
        int wordsPerSetence = countWords(sentence);
        cout << "La frase número " << sentecesNumber + 1 << " tiene " << wordsPerSetence << " palabras" << endl;

        totalWords += wordsPerSetence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;
}

void closeFile(ifstream& file)
{
    
    if (file.is_open())
    {
        file.close();
        cout << "El archivo se cerro satisfactoriamente.";
    }
    
}

int main()
{
    ifstream textFile = openFile("QuotesOfBjarne.txt");
    showWordsOf(textFile);
    closeFile(textFile);
    cin.ignore();
    cin.get();
    return 0;
}