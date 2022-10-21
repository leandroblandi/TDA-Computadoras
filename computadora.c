/*-----------------------
 | computadora.c
 | Author: Leandro Blandi
 ------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "computadora.h"

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
    gets(procesador);

    printf("\n- Ingrese que placa de video dispondra la computadora: ");
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

void destruirComputadora(Computadora computadora);
{
    free(computadora);
}
