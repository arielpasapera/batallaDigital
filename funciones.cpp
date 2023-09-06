#include "funciones.h"
#include "soldado.h"
#include "mina.h"
#include <iostream>
#include <fstream>
using namespace std;


char** crearTablero() {
    // Crear un nuevo tablero
    char** tablero = new char*[FILAS];
    for (int i = 0; i < FILAS; i++) {
        tablero[i] = new char[COLUMNAS];
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }
    return tablero;
}


void mostrarTablero(char** tablero) {
    // Mostrar los números de columna
    cout << "    ";
    for (int j = 0; j < COLUMNAS; j++) {
        if (j < 10){
           cout << " 0" << j << " ";
        }
        else{
            cout << " " << j << " ";
        }
    }
    cout << endl;

    // Mostrar el tablero con los números de fila a la izquierda
    for (int i = 0; i < FILAS; i++) {
        if (i < 10){
            cout<<"0" << i << "  ";
        }
        else{
            cout << i << "  ";
        }
        
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "|" << tablero[i][j] << "| ";
        }
        
        cout << endl;
    }
}

void exportarTablero(char jugador, char** tablero, Mina* minas, int* cantMinas) {
    
    bool minaEnPosicion;
    string nombreArchivo;
    ofstream archivo;

    if (jugador == '1'){
        nombreArchivo = "tablero_jugador_1.txt";
       
    }
    else{nombreArchivo = "tablero_jugador_2.txt";}
    
    archivo.open(nombreArchivo);

    archivo <<"Tablero del jugador: "<<jugador << endl;
    archivo << "   ";  
    for (int j = 0; j < 20; j++) {
        if (j < 10){
           archivo << " 0" << j << " ";
        }
        else{
            archivo << " " << j << " ";
        }
    }
    archivo << endl;

    // Escribir todas las filas del tablero
    for (int i = 0; i < FILAS; i++) {
        if (i < 10){
           archivo << " 0" << i << " ";
        }
        else{
            archivo << " " << i << " ";
        }
       
        for (int j = 0; j < COLUMNAS; j++) {
            minaEnPosicion = false;

            for (int k = 0; k < *cantMinas; k++) {
                if ((minas[k].posicionX() == i) && (minas[k].posicionY() == j)) {                    
                    

                    if (minas[k].equipoMina() == jugador) 
                    {
                       
                        archivo <<"M | ";                        
                        minaEnPosicion = true;
                        break;
                    }
                }
            }

            if (!minaEnPosicion) {    
                if(jugador == tablero[i][j]){
                    archivo << jugador << " | "; //aca imprimo al jugador del archivo
                    
                }                
                else if(tablero[i][j] == 'X'){
                    archivo << "X | ";
                }

                else{
                    archivo << "  | ";
                }
            }
        }

        archivo << endl;
    }

    
    archivo << endl;
    archivo.close();
}

void posicionarEnTablero(char** tablero, Soldado& soldado){
  
   int posicionX = soldado.obtenerPosicionX();
   int posicionY = soldado.obtenerPosicionY();
   char ficha = soldado.obtenerEquipo();

   if (tablero[posicionX][posicionY] != 'X')
        tablero[posicionX][posicionY] = ficha;
   else{
    cout << "El casillero se encuentra inactivo" <<endl;
   }

}

Soldado* identificarSoldado(Soldado* soldados){
    int posicionX;
    int posicionY;
    int id;
    bool encontrado = false;
    bool vivo;
    Soldado* soldado = nullptr;
    

    for(int i = 0; i < 4; i++){
        posicionX = soldados[i].obtenerPosicionX();
        posicionY = soldados[i].obtenerPosicionY();
        id = soldados[i].obtenerID();
        if (soldados[i].viveOMuere() == false){ //muert0
            cout << "El soldado "<< id << " se encuentra muerto" << endl;
        }
        else{
             cout << "El soldado "<< id << " se encuentra en y = " << posicionX << " x = " << posicionY << endl;
        } 

    }
    while(encontrado == false){
        cout << "Ingrese el ID del soldado que desea mover "<< endl;
        cin >> id;

        for(int i = 0; i < 4; i++){
            if ((soldados[i].obtenerID() == id) && (soldados[i].viveOMuere() == true)){
                soldado = &soldados[i];
                encontrado = true;
            }
        }
    }
    return soldado; //retorna un puntero a un objeto soldado.
}

int obtenerPosicion(char nombre){
    int posicion;
    cout << "ingrese la posicion " << nombre << endl;
    cin>>posicion;
    return posicion;
}

char validarPosicion(char** tablero, int posicionX, int posicionY, Soldado& soldado){
   char rival = '1';
   if (soldado.obtenerEquipo() == 1)
   {
        rival = '2';
   }

   if(tablero[posicionX][posicionY] == 'M')
    {
        tablero[posicionX][posicionY] = 'X'; //indica casillero desactivado
        return 'M';
    }
        
    else if (tablero[posicionX][posicionY] ==  'X')
    {
        cout << "El casillero se encuentra inactivo." <<endl;
        return 'P';
    }
        
    else if (tablero[posicionX][posicionY] == (soldado.obtenerEquipo() == '2' ? '1':'2'))
    {
        tablero[posicionX][posicionY] = 'X';
        return 'D';
    }
    
    else if (tablero[posicionX][posicionY] == (soldado.obtenerEquipo() == '1' ? '1':'2'))
    {
        return 'P';
    }

    else
    {
        return 'V';
    }          
}

void limpiarPosicion(char** tablero, Soldado& soldado){

   int posicionX  = soldado.obtenerPosicionX();
   int posicionY = soldado.obtenerPosicionY();
   tablero[posicionX][posicionY] = ' ';
}

void juegoPrincipal(char** tablero, Soldado* jugador1, Soldado* jugador2) {
  char mover, estado1, estado2;
  int contador = 1;
  int x, y, nuevaX, nuevaY;
  char posicion;
  int contadorSoldados1 = 4;
  int contadorSoldados2 = 4;
  int cantMinas = 0;
  
  

  Soldado* soldado1 = nullptr; //puntero a la primera posicion del array de soldados jugador 1
  Soldado* soldado2 = nullptr;
  Mina* minas = new Mina[400]; // crear arreglo vacío
    
    while ((contadorSoldados1 > 0) && (contadorSoldados2 > 0)) 
    {

        cout << "Debe colocar una mina." <<endl;
        if (contador % 2 != 0){
                cout<<"Turno del jugador 1."<<endl;
                
                minas[contador - 1] = Mina();   
                estado1 = minas[contador -1].posicionarMina('1', tablero, jugador1);//aca le asigno el equipo a la mina
                cantMinas += 1;
                
                if (estado1 == '1'){
                    contadorSoldados1 --;
                }
                else if (estado1 == 'a'){ 
                    contadorSoldados2 --;
                }

                mostrarTablero(tablero);    
                exportarTablero('1', tablero, minas, &cantMinas);
                exportarTablero('2', tablero, minas, &cantMinas);
                
                if (contadorSoldados1 > 0)
                {
                    
                    cout<< "Desea mover un soldado?(s/n): "<<endl;
                    cin>> mover;

                    if (mover == 's' || mover == 'S')
                    {
                        soldado1 = identificarSoldado(jugador1); //identifica el id del soldado
                        
                        nuevaX = obtenerPosicion('Y');
                        nuevaY = obtenerPosicion('X');
                        
                        posicion = validarPosicion(tablero, nuevaX, nuevaY, *soldado1);

                        if (posicion == 'M'){ //si el soldado pisa un casillero minado muere
                            minas[contador -1].activar();
                            limpiarPosicion(tablero, *soldado1);
                            soldado1->matarSoldado();
                            contadorSoldados1 -- ;
                        }
                        else if(posicion == 'V')
                        {
                            limpiarPosicion(tablero, *soldado1); //limpia la posicion que será abandonada
                            soldado1->moverSoldado(nuevaX, nuevaY); //Mueve el soldado a una nueva posicion
                            posicionarEnTablero(tablero, *soldado1);
                        }
                        else if(posicion == 'P')
                        {
                            cout << "Ha perdido el turno" <<endl;
                        }
                        
                        else
                        {
                            limpiarPosicion(tablero, *soldado1);
                            soldado1->matarSoldado();
                            for (int i = 0; i < 4; i++)
                            {
                                if((jugador2[i].obtenerPosicionX() == nuevaX) && (jugador2[i].obtenerPosicionY() == nuevaY))
                                {
                                    jugador2[i].matarSoldado();
                                    contadorSoldados1--;
                                    contadorSoldados2--;
                                }

                            }

                        }

                    } //aca cierra el if de si desea mover un soldado o no.
            
                }
            exportarTablero('1', tablero, minas, &cantMinas);
            exportarTablero('2', tablero, minas, &cantMinas);
        }
    
        else
        {
            cout<<"Turno del jugador 2."<<endl;
            minas[contador - 1] = Mina();
            
            estado2 = minas[contador -1].posicionarMina('2', tablero, jugador2); //aca le asigno el equipo a la mina
            
            cantMinas += 1;
            if (estado2 == '2')
            {
                contadorSoldados2 --;   
            }
            else if (estado2 == 'b')
            {
                contadorSoldados1 --; 
            }

            
                
            mostrarTablero(tablero);
            exportarTablero('1', tablero, minas, &cantMinas);
            exportarTablero('2', tablero, minas, &cantMinas);

            if (contadorSoldados2 > 0)
            {
                cout<< "Desea mover un soldado?(s/n): "<<endl;
                cin>> mover;
                
                if (mover == 's' || mover == 'S')
                {
                    soldado2 = identificarSoldado(jugador2); //identifica el id del soldado
                    nuevaX = obtenerPosicion('Y');
                    nuevaY = obtenerPosicion('X');
                        
                    posicion = validarPosicion(tablero, nuevaX, nuevaY, *soldado2);

                    if (posicion == 'M') //si el soldado pisa un casillero minado muere
                    { 
                        minas[contador -1].activar();
                        limpiarPosicion(tablero, *soldado2);//se activa, explota el casillero
                        soldado2->matarSoldado();
                        contadorSoldados2 --;
                    }
                    else if(posicion == 'V')
                    {
                        limpiarPosicion(tablero, *soldado2); //limpia la posicion que será abandonada
                        soldado2->moverSoldado(nuevaX, nuevaY); //Mueve el soldado a una nueva posicion
                        posicionarEnTablero(tablero, *soldado2);
                    }
                    else if(posicion == 'P')
                    {
                        cout << "Ha perdido el turno" <<endl;
                    }
                    else
                    {
                        limpiarPosicion(tablero, *soldado2);
                        soldado2->matarSoldado();
                        for (int i = 0; i < 4; i++)
                        {
                            if((jugador1[i].obtenerPosicionX() == nuevaX) && (jugador1[i].obtenerPosicionY() == nuevaY))
                            {
                                jugador1[i].matarSoldado();
                                contadorSoldados1--;
                                contadorSoldados2--;
                    
                            }

                        }

                    }

                }
            }
        }
            
        contador += 1;
        mostrarTablero(tablero);
        cout << "soldados vivos del jugador 1: " << contadorSoldados1 <<endl;
        cout << "soldados vivos del jugador 2: " << contadorSoldados2 <<endl;

   }

        exportarTablero('1', tablero, minas, &cantMinas);
        exportarTablero('2', tablero, minas, &cantMinas);
       
    
    if (contadorSoldados1 == 0)
    {
        cout<<"Gano el jugador 2"<<endl;
    } 
    else
    {
        cout<<"Gano el jugador 1"<<endl;
    }       
    delete[] minas; 
    
  }