#ifndef SOLDADO_H
#define SOLDADO_H

class Soldado {
public:
    Soldado(int posicionX, int posicionY, char equipo, int ID);
    void establecerPosicion(int nuevaX, int nuevaY);
    void establecerEquipo(char nuevoEquipo);
    void establecerID(int nuevoID);
    void moverSoldado(int nuevaX, int nuevaY);
    int obtenerPosicionX();
    int obtenerPosicionY();
    char obtenerEquipo();
    int obtenerID();
    void matarSoldado();
    bool viveOMuere();

private:
    int x;
    int y;
    bool vivo;
    char equip;
    int idSoldado;
};

#endif
