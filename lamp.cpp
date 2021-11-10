#include <iostream>

using namespace std;

class Lampara
{
    private:
        /* data */
        bool estado;// true encendido, false apagado
        int intensidad;
        int usos;
    public:
        Lampara(/* args */);
        ~Lampara();
        void encender();
        void apagar();
        void intensificar();
        void atenuar();
        bool obtenerEstado();
        int obtenerIntensidad();
        int obtenerUsos();
};

Lampara::Lampara(/* args */)
{
    estado = false;
    intensidad = 0;
    usos = 100;
}

Lampara::~Lampara()
{
}

void Lampara::encender() 
{
    estado = true;
}

void Lampara::apagar() 
{
    estado = false;
    --usos;
}

void Lampara::intensificar() 
{
    if(estado == true) intensidad++;
}

void Lampara::atenuar() 
{
    if(estado == true and intensidad > 0) intensidad--;
}

bool Lampara::obtenerEstado() 
{
    return estado;
}

int Lampara::obtenerIntensidad() 
{
    return intensidad;    
}

int Lampara::obtenerUsos() 
{
    return usos;    
}


int main()
{
    Lampara* osram = new Lampara;
    cout << "El estado inicial es: " << osram->obtenerEstado() << endl;
    cout << "La intensidad inicial es: " << osram->obtenerIntensidad() << endl;
    cout << "La cantidad de usos inical es: " << osram->obtenerUsos() << endl;

    osram->encender();
    cout << "El estado es: " << osram->obtenerEstado() << endl;
    cout << "La intensidad es: " << osram->obtenerIntensidad() << endl;
    cout << "La cantidad de usos restantes es de: " << osram->obtenerUsos() << endl;
    
    osram->intensificar();
    cout << "La intensidad es: " << osram->obtenerIntensidad() << endl;
    
    osram->intensificar();
    cout << "La intensidad es: " << osram->obtenerIntensidad() << endl;
   
    osram->atenuar();
    cout << "La intensidad es: " << osram->obtenerIntensidad() << endl;
   
    osram->apagar();
    cout << "El estado es: " << osram->obtenerEstado() << endl;
    cout << "La cantidad de usos restantes es de: " << osram->obtenerUsos() << endl;

    delete osram;
    return 0;
}