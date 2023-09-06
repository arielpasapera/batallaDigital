#ifndef MINA_H
#define MINA_H

#include <iostream>
#include "soldado.h"


class Mina {
public:
    Mina();
    char posicionarMina(char equipo, char** tablero, Soldado* soldados);
    void activar();
    void desactivar();
    bool estaActiva();
    int posicionX();
    int posicionY();
    char equipoMina();
    void posicionarMinaTablero(char** tablero);

private:
    int x;
    int y;
    bool activa;
    char equipo;
    int turnos;
};

#endif
