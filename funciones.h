#ifndef FUNCIONES
#define FUNCIONES

#include <iostream>

#include "soldado.h"
#include "mina.h"

const int FILAS = 20;
const int COLUMNAS = 20;
const int NUM_SOLDADOS = 4;

char** crearTablero();
/*
La función crearTablero() es una función que crea un nuevo tablero para el juego. Este tablero es un arreglo de dos
dimensiones de caracteres (char) que representa el campo de juego. La función comienza por declarar una variable
tablero como un puntero a puntero (char**). Luego, utiliza un bucle for anidado para recorrer todas las posiciones
del tablero y asignarles el valor ' ' (espacio en blanco). Finalmente, la función devuelve el tablero creado.
*/

void mostrarTablero(char** tablero);
/*
El procedimiento mostrarTablero se encarga de mostrar por pantalla el estado actual del tablero del juego.
En primer lugar, se muestran los números de columna en la parte superior del tablero. Luego, para cada fila del
tablero, se muestran los números de fila a la izquierda y se recorre cada columna del tablero para imprimir el 
contenido de cada casilla, separado por barras verticales.
En resumen, la función muestra una representación visual del estado del tablero para que los correctores puedan
visualizar la ubicación de los soldados y minas en todo momento durante el juego.
*/
void exportarTablero(char jugador, char** tablero, Mina* minas,int* cantMinas);
/*
Este procedimiento exporta el estado actual del tablero del juego a un archivo de texto. 
La función recibe como parámetros el número de jugador (1 o 2), un puntero al tablero, un array de objetos de tipo
Mina y la cantidad de minas en el array.
Primero, la función crea una variable booleana para verificar si hay una mina en la posición actual del tablero.
Luego, se define el nombre del archivo de salida en función del número de jugador. Se abre el archivo de texto y se 
escriben los números de columna en la primera fila.
A continuación, la función escribe el contenido de cada fila del tablero. Si hay una mina en la posición actual, 
se escribe una "M" en el archivo de texto. Si no hay mina, se verifica si el jugador está en esa posición y se escribe
el número de jugador. Si la posición está desactivada, se escribe "X". Si no hay nada en la posición, se escribe un
espacio en blanco.
Finalmente, se cierra el archivo y se guarda.
*/
void posicionarEnTablero(char** tablero, Soldado& soldado);
/*
El procedimiento posicionarSoldadoEnTablero recibe como parámetros un puntero a un array de caracteres que representa el
tablero y un objeto Soldado. Lo que hace la función es obtener la posición en X e Y del soldado y el equipo al que
pertenece. Luego, verifica si en la posición del tablero correspondiente hay una "X", lo que significa que ese 
casillero está inactivo y no se puede posicionar al soldado ahí. Si el casillero está libre, coloca el símbolo del
equipo del soldado en la posición correspondiente del tablero.
*/

Soldado* identificarSoldado(Soldado* soldados);
/*
La función identificarSoldado recibe un arreglo de objetos Soldado y busca entre ellos al que tenga un ID específico
que el usuario ingrese por consola y que esté vivo. Si encuentra al soldado, retorna un puntero a dicho objeto Soldado.
En caso contrario, sigue pidiendo al usuario que ingrese un ID válido hasta que lo encuentre. La función también
muestra por consola la posición de cada soldado y si está vivo o muerto.
*/

int obtenerPosicion(char nombre);
/*
Esta función recibe un parámetro nombre que es de tipo char y se utiliza para imprimir un mensaje en la consola 
indicando al usuario que ingrese la posición correspondiente a ese nombre. Luego, la función utiliza la función cin
para leer un valor de la entrada estándar y lo asigna a una variable local posicion. Finalmente, la función retorna
el valor de posicion.
*/

char validarPosicion(char** tablero, int posicionX, int posicionY, Soldado& soldado);
/*
Esta función tiene como objetivo validar si la posición seleccionada por un soldado es una posición válida en el 
tablero y si en esa posición hay una mina, un soldado rival o está desactivada. 
Así funciona cada una de las validaciones:

Si la posición seleccionada tiene una mina ('M') se retorna la letra 'M'.
Si la posición seleccionada está desactivada ('X') se indica que el casillero está inactivo y se retorna la letra 'P'.
Si la posición seleccionada tiene un soldado rival se elimina el soldado rival y se retorna la letra 'D'.
Si la posición seleccionada tiene un soldado del mismo equipo se indica que no se puede ocupar esa posición y se retorna la letra 'P'.
Si la posición seleccionada no tiene nada se retorna la letra 'V' indicando que la posición es válida para ser ocupadada.

*/

void limpiarPosicion(char** tablero, Soldado& soldado);
/*
El procedimiento limpiarPosicion recibe como parámetros un puntero doble a char que representa el tablero y una 
referencia a un objeto Soldado. Esta función se encarga de limpiar la posición del soldadoque será abandonada
en el tablero, es decir, establecer un espacio vacío en la posición en la que se encuentra actualmente el soldado.
Para ello, primero se obtienen las coordenadas de la posición actual del soldado a través de los métodos
obtenerPosicionX y obtenerPosicionY de la instancia de Soldado. Luego, se establece un espacio vacío en el casillero
correspondiente del tablero mediante la asignación de ' '.
En resumen, la función limpiarPosicion tiene la tarea de actualizar el tablero después de que un soldado se haya
movido o sido eliminado del juego.
*/

void juegoPrincipal(char** tablero, Soldado* jugador1, Soldado* jugador2);
/*
Procedimiento que se encarga de llevar a cabo el juego, comienza preguntando al primer jugador que coloque una mina en el tablero y luego muestra el tablero.
Luego, le pregunta al jugador si quiere mover uno de sus soldados. Si decide moverlo, el jugador selecciona un 
soldado y luego ingresa la posición a la que desea moverlo. Si el soldado se mueve a una casilla vacía, se 
actualizará la posición del soldado en el tablero. Si el soldado se mueve a una casilla con una mina, el soldado 
muere y se actualiza la posición en el tablero. Si el soldado se mueve a una casilla con un soldado enemigo, 
ambos soldados mueren y se actualizan las posiciones en el tablero.
Luego, le pide al segundo jugador que coloque una mina y muestra el tablero actualizado. Si el segundo jugador tiene
soldados, se le pregunta si quiere mover uno de sus soldados y el proceso continúa hasta que uno de los jugadores
pierde todos sus soldados.
*/
#endif