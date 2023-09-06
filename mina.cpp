#include "mina.h"
#include "funciones.h"
#include "soldado.h"
#include <iostream>
using namespace std;

Mina::Mina() {
    this->activa = true;
}

char Mina::posicionarMina(char equipo, char** tablero, Soldado* soldados){
    this->equipo = equipo;
    //this ->turnos = turnos;
    cout << "Ingrese la fila donde colocar la mina: " << endl;
    cin >> x;
    cout << "Ingrese la columna donde colocar la mina: " << endl;
    cin >> y;
    char team;
    if (x < 0 || x >= FILAS || y < 0 || y >= COLUMNAS) {
        cout << "Posición inválida." << endl;
        return 'P';
    } 
    
    else if (equipo == '1' && tablero[x][y] == '2')
    {
        tablero[x][y] = 'X';
        return 'a';
    }
    else if (equipo == '2' && tablero[x][y] == '1')
    {
        tablero[x][y] = 'X';
        return 'b';
    }
    
    else if((tablero[x][y] == '1') || (tablero[x][y] == '2'))
    {
        tablero[x][y] = 'X';
        for (int i = 0; i < 4; i++)
        {
            if ((soldados[i].obtenerPosicionX() == x) && (soldados[i].obtenerPosicionY() == y))
            {
                
                soldados[i].matarSoldado();
                if (soldados[i].obtenerEquipo() == '1'){
                    team = '1';
                } 
                else if (soldados[i].obtenerEquipo() == '2') 
                {
                    team = '2';
                }
            }   
        }
        return team;
    } 
    else if (tablero[x][y] == 'X'){
        cout << "CASILLERO INACTIVO" << endl;
        return 'P';
    } else {
        tablero[x][y] = 'M';
        return 'V';
    }
}

void Mina::activar() {
    this->activa = true;
}

void Mina::desactivar() {
    this->activa = false;
    this->turnos = 5;
}

bool Mina::estaActiva() {
    return this->activa;
}

int Mina::posicionX() {
    return this->x;
}

int Mina::posicionY() {
    return this->y;
}

char Mina::equipoMina(){
    return equipo;
}

