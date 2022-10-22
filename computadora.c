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
    printf("\nLista de computadoras:");

    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        if(computadoras[i]->cantidadRAM != -1)
        {
            mostrarComputadora(computadoras[i]);
        }
    }
}

void modificarComputadora(Computadora computadoras[], char procesador[30])
{
    printf("\nModificando una computadora:");

    int encontrada = NO_ENCONTRADO;

    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        if(strcmp(computadoras[i]->procesador, procesador) == 0)
        {
            printf("\nIngrese nuevo procesador (ant: %s): ", computadoras[i]->procesador);
            fflush(stdin);
            gets(computadoras[i]->procesador);

            printf("\nIngrese nueva placa de video (ant: %s): ", computadoras[i]->placaDeVideo);
            fflush(stdin);
            gets(computadoras[i]->placaDeVideo);

            printf("\nIngrese nueva RAM instalada (ant: %dGB): ", computadoras[i]->cantidadRAM);
            scanf("%d", &computadoras[i]->cantidadRAM);

            encontrada = i;
            i = CANTIDAD_COMPUTADORAS;
        }
    }
    if(encontrada == NO_ENCONTRADO)
    {
        printf("\nLa computadora no se encuentra en memoria para modificar...");
    }
}

void eliminarComputadora(Computadora computadoras[], char procesador[30])
{
    printf("\nEliminando una computadora:");

    int encontrada = NO_ENCONTRADO;

    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        if(strcmp(computadoras[i]->procesador, procesador) == 0)
        {
            strcpy(computadoras[i]->procesador, "");
            strcpy(computadoras[i]->placaDeVideo, "");
            computadoras[i]->cantidadRAM = -1;

            encontrada = i;
            i = CANTIDAD_COMPUTADORAS;

            printf("\nComputadora eliminada exitosamente...");
        }
    }
    if(encontrada == NO_ENCONTRADO)
    {
        printf("\nLa computadora no se encuentra en memoria para eliminar...");
    }
}

void ordenarComputadorasPorRAM(Computadora computadoras[])
{
    Computadora auxiliarComputadora;

    printf("\nOrdenando por cantidad de RAM instalada...");

    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        for(int j = 0; j < CANTIDAD_COMPUTADORAS - 1; j++)
        {
            if(computadoras[j]->cantidadRAM > computadoras[j+1]->cantidadRAM)
            {
                auxiliarComputadora = computadoras[j];
                computadoras[j] = computadoras[j+1];
                computadoras[j+1] = auxiliarComputadora;
            }
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


 /*----------------------------
 | Procedimientos de archivo
 ------------------------------*/

Computadora parsearDatos(char datos[55])
{
    char procesador[30];
    char placaDeVideo[20];
    char cantidadRAM[5];

    /*--------------------------------------------------------------------------------
    | Si no se comprenden las siguientes tres lineas, acuda a los siguientes links:
    | ------------------------------------------------------------------------------
    | - https://parzibyte.me/blog/2018/11/13/separar-cadena-delimitadores-c-strtok/
    | - https://www.youtube.com/watch?v=jHdbmHCVQ2c
    --------------------------------------------------------------------------------*/
    strcpy(procesador, strtok(datos, "-"));
    strcpy(placaDeVideo, strtok(NULL, "-"));
    strcpy(cantidadRAM, strtok(NULL, "-"));

    return crearComputadora(procesador, placaDeVideo, atoi(cantidadRAM));

}

void cargarComputadorasDesdeArchivo(Computadora computadoras[])
{
    FILE * archivoComputadoras = fopen("computadoras.txt", "r");

    char datos[55] = "";
    int i = 0;

    if(archivoComputadoras == NULL)
    {
        printf("\nArchivo no encontrado: \"computadoras.txt\", cree uno nuevo");
    }

    while((fgets(datos, 55, archivoComputadoras)) && (i < CANTIDAD_COMPUTADORAS))
    {
        computadoras[i] = parsearDatos(datos);
        i++;
    }

    fclose(archivoComputadoras);

}

void guardarComputadorasEnArhivo(Computadora computadoras[])
{
    FILE * archivoComputadoras = fopen("computadoras.txt", "w");

    for(int i = 0; i < CANTIDAD_COMPUTADORAS; i++)
    {
        if(computadoras[i]->cantidadRAM != -1)
        {
            fprintf(
                archivoComputadoras,
                "%s-%s-%d\n",
                computadoras[i]->procesador,
                computadoras[i]->placaDeVideo,
                computadoras[i]->cantidadRAM
            );
        }
    }
    fclose(archivoComputadoras);
    return;
}


