#include <iostream>
#include <cmath>
using namespace std;

double conversor(double temperatura,char op);


int main()
{
  double temperatura;
  char opcion;

  cout << "Elegir que conversor desea usar: " << endl;
  cout << "Ingrese 1 para convertir Celcius a Farenheit o Ingrese 2 para convertir Farenheit a Celcius" << endl;
  cin >> opcion;
  cout << "Cuantos grados hace? : " << endl;
  cin >> temperatura;

  cout << "El resultado de la conversion es de = " << conversor(temperatura, opcion) << endl;

  cin.get();
  cin.ignore();


  return 0;
}
double conversor(double temperatura,char op)
{
    double conversor = 0.0;
    if (op == '1' )
    {
        conversor = (1.8 * temperatura) + 32.0;
    }
    else if (op == '2' )
    {
        conversor = (temperatura - 32) / 1.8;

    }
    else
    {
      cout << "Opcion no disponible" << endl;
    }
    return conversor;

}
