//compilar en terminal con g++ main.cpp caballo.cpp  -o main -lncurses
#include <ncurses.h> // incluye la librería ncurses
#include <cstdlib>
#include "caballo.hpp" // incluye el archivo de encabezado donde se define la clase caballo
#include <vector>
#include <unistd.h> // incluye la librería para la función usleep()


using namespace std;
int main(int argc, char const *argv[]) {
    initscr(); // inicializa la pantalla de la libería ncurses

    int cantidad_caballos = 1;
    do {
        printw("Ingrese nuemro de caballos (1-20): "); // solicita al usuario que ingrese la cantidad de caballos
        scanw("%d", &cantidad_caballos); // escanea el número entero ingresado por el usuario
    } while (cantidad_caballos>=20); // repire el ciclo mientras la cantidad de caballos sea menor o igual a 20

    clear(); // limpia la pantalla

    vector <Caballo> Lista_caballos; // se crea un vector de objetos de la clase Caballo

    // agrega la cantidad de caballos que ingresa el usuario
    for (int i = 0; i < cantidad_caballos; i++) {
        Caballo caballo; // crea un objeto de clase Caballo
        Lista_caballos.push_back(caballo); // agrega el caballo al final del vector
    }

    bool ganador=false; // variable que indica si hay un ganador
    int caballoGanador=0; // variable que indica el caballo ganador
    
    // bucle principal
    while (true) {
        // comienzo de la carrera con la iteración de caballos
        for (int i = 0; i < cantidad_caballos; i++){   
            Lista_caballos[i].MoverCaballo(); // mueve el caballo en la pista según la función de moverCaballo()
            // imprime la posición del caballo en pantalla
            if (i<9) {
                mvprintw(15+i, 0, "caballo %i", i+1);
            }
            else {
                mvprintw(15+i, 0, "caballo%i", i+1);
            }
            mvprintw(15+i, Lista_caballos[i].getPosicion()+10, "c");
            
            // verifica si hay un caballo ganador
            if (Lista_caballos[i].verificarGanador()){
                caballoGanador=i;
                ganador=true;
                break;
            }

            // impresión de la linea de meta
            mvprintw(14, 158, "META");
            mvprintw(15+i, 160, "|");
        }

        // sale del bucle si hay un ganador
        if (ganador == true) {
            break;
        } 

        refresh(); // actualiza la pantalla y espera un tiempo antes de continuar
        usleep(300000); // espera 300 milisegundos para refrescar la pantalla
        clear(); // limpia la pantalla
    }
    clear();
    mvprintw(20, 80, "el caballo ganador es %i", caballoGanador+1); // imprime el mensaje de caballo ganador
    getch(); // espera que el usuario presione un tecla
    endwin(); // finaliza la pantalla de la biblioteca ncurses

    return 0;
}
