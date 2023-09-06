#include "Soldado.h"
#include "funciones.h"
#include <iostream>
#include <cmath>

using namespace std;

Soldado::Soldado(int posicionX, int posicionY, char equipo, int ID) {
    x = posicionX;
    y = posicionY;
    vivo = true;
    equip = equipo;
    idSoldado = ID;
}

void Soldado::establecerPosicion(int nuevaX, int nuevaY) {
    x = nuevaX;
    y = nuevaY;
}

void Soldado::establecerEquipo(char nuevoEquipo) {
    equip = nuevoEquipo;
}

void Soldado::establecerID(int nuevoID) {
    idSoldado = nuevoID;
}

void Soldado::moverSoldado(int nuevaX, int nuevaY) {
    // Verificar que la nueva posición esté dentro de los límites del tablero
    if (nuevaX < 0 || nuevaX >= FILAS || nuevaY < 0 || nuevaY >= COLUMNAS) {
        cout << "Posición inválida." << endl;
        return;
    }

    // Verificar que el soldado se mueva en línea recta (horizontal, vertical o diagonal)
    if (nuevaX != x && nuevaY != y && abs(nuevaX - x) != abs(nuevaY - y)) {
        cout << "El soldado solo puede moverse en línea recta." << endl;
        return;
    }

    // Actualizar la posición del soldado
    x = nuevaX;
    y = nuevaY;
}

int Soldado::obtenerPosicionX(){
    return x;
}

int Soldado::obtenerPosicionY(){
    return y;
}

char Soldado::obtenerEquipo(){
    return equip;
}

int Soldado::obtenerID(){
    return idSoldado;
}

void Soldado::matarSoldado(){
    vivo = false;
}

bool Soldado::viveOMuere(){
    return vivo;
}