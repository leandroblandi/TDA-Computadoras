/*-----------------------
 | computadora.c
 | Author: Leandro Blandi
 ------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "computadora.h"

#define CANTIDAD_COMPUTADORAS 5
#define NO_ENCONTRADO -1

struct _Computadora
{
    char procesador[30];
    char placaDeVideo[20];
    int cantidadRAM;
};


/*---------------
 | Constructores
 ----------------*/

Computadora crearComputadora(char procesador[30], char placaDeVideo[20], int cantidadRAM)
{
    Computadora computadora = malloc(sizeof(struct _Computadora));

    strcpy(computadora->procesador, procesador);
    strcpy(computadora->placaDeVideo, placaDeVideo);

    computadora->cantidadRAM = cantidadRAM;

    return computadora;
}

Computadora crearComputadoraPorTeclado()
{
    char procesador[30];
    char placaDeVideo[20];
    int cantidadRAM;

    printf("\nNueva computadora:");
    printf("\n- Ingrese que procesador dispondra la computadora: ");
    fflush(stdin);
    gets(procesador);

    printf("\n- Ingrese que placa de video dispondra la computadora: ");
    fflush(stdin);
    gets(placaDeVideo);

    printf("\n- Ingrese cuanta memoria RAM tendra instalada la computadora: ");
    scanf("%d", &cantidadRAM);

    return crearComputadora(procesador, placaDeVideo, cantidadRAM);
}


/*----------------------------
 | Procedimientos individuales
 ------------------------------*/

void mostrarComputadora(Computadora computadora)
{
    printf("\nComputadora:");
    printf("\n\t- Procesador: %s", computadora->procesador);
    printf("\n\t- Placa de Video: %s", computadora->placaDeVideo);
    printf("\n\t- Cantidad de RAM instalada: %dGB", computadora->cantidadRAM);
}


/*------------
 | Destructor
 -------------*/

void destruirComputadora(Computadora computadora)
{
    free(computadora);
}


/*----------------------------
 | Procedimientos de arreglo
 ------------------------------*/

void inicializarComputadoras(Computadora computadoras[])
{
    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        computadoras[i] = crearComputadora("", "", -1);
    }
}

void agregarComputadoras(Computadora computadoras[], int cantidad)
{
    int posicion = NO_ENCONTRADO;

    for(int i = 0; i < cantidad; i++)
    {
        posicion = buscar(computadoras, -1);

        if(posicion != -1)
        {
            computadoras[posicion] = crearComputadoraPorTeclado();
        }
    }
}

void mostrarComputadoras(Computadora computadoras[])
{
    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        if(computadoras[i]->cantidadRAM != -1)
        {
            mostrarComputadora(computadoras[i]);
        }
    }
}


 /*----------------------------
 | Procedimientos extras
 ------------------------------*/

int buscar(Computadora computadoras[], int elemento)
{
    int encontrado = NO_ENCONTRADO;

    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        if(computadoras[i]->cantidadRAM == elemento)
        {
            encontrado = i;
            i = CANTIDAD_COMPUTADORAS;
        }
    }
    return encontrado;
}
