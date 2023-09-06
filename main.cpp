#include "funciones.h"
#include "soldado.h"
#include "mina.h"

#include <iostream>
using namespace std;

int main() {
    // Crear un nuevo tablero
    char** tablero = crearTablero();

    Soldado* jugador1 = new Soldado[NUM_SOLDADOS]{
    Soldado(0, 5, '1', 10),
    Soldado(0, 8, '1', 11),
    Soldado(0, 11, '1', 12), 
    Soldado(0, 14, '1', 13)
    };
    
    Soldado* jugador2 = new Soldado[NUM_SOLDADOS]{
        Soldado(19, 5, '2', 20),
        Soldado(19, 8, '2', 21),
        Soldado(19, 11, '2', 22), 
        Soldado(19, 14, '2', 23)
     };

    for (int i = 0; i < 4; i++){
        posicionarEnTablero(tablero, jugador1[i]);
        posicionarEnTablero(tablero, jugador2[i]);
    }

    // Mostrar el tablero en la consola
    mostrarTablero(tablero);

    juegoPrincipal(tablero, jugador1, jugador2);

    for (int i = 0; i < FILAS; i++) {
        delete[] tablero[i];
    }
    delete[] jugador1; 
    delete[] jugador2;
    delete[] tablero;
    
    return 0;
}