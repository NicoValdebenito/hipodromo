#include "caballo.hpp" // incluye el archivo de encabezado donde se define la clase caballo
#include <cstdlib>
#include <ncurses.h>

// constructor de la clase caballo
Caballo::Caballo(){
    this -> posicionCaballo = 0; // posición inicial del caballo = 0
} 

// función para mover al caballo
void Caballo::MoverCaballo(){
    int prob = rand()%10+1; //se genera la probabilidad de movimiento entre 1 y 10
    if (prob > 6) {
        this -> posicionCaballo++;
    }
    else if (prob > 9) {
        this -> posicionCaballo= this->posicionCaballo+2;
    }
    else if(prob <9) {
        this -> posicionCaballo= this->posicionCaballo+3;
    }
}

// función para establecer la posición del caballo
void Caballo::setPosicion(int posicion) {
    this -> posicionCaballo = posicion;
}

// función para obtener la posición del caballo
int Caballo::getPosicion() {
    return this -> posicionCaballo;
}

// función para verificar si el caballo llegó a la meta
bool Caballo::verificarGanador(){
    if (this -> posicionCaballo >= 150) {
        return true;
    }
    else {
        return false;
    }
}

// destructor de la clase
Caballo::~Caballo(){
    posicionCaballo=0;
}
