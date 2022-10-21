/*-----------------------
 | computadora.h
 | Author: Leandro Blandi
 ------------------------*/

#ifndef COMPUTADORA_H_INCLUDED
#define COMPUTADORA_H_INCLUDED

struct _Computadora;

typedef struct _Computadora * Computadora;

Computadora crearComputadora(char procesador[30], char placaDeVideo[20], int cantidadRAM);
Computadora crearComputadoraPorTeclado();

void mostrarComputadora(Computadora computadora);

void destruirComputadora(Computadora computadora);

#endif // COMPUTADORA_H_INCLUDED
