#include <stdio.h>
#include <stdlib.h>
#include "computadora.h"

#define CANTIDAD_COMPUTADORAS 2

int main()
{

    Computadora computadoras[CANTIDAD_COMPUTADORAS];
    inicializarComputadoras(computadoras);
    agregarComputadoras(computadoras, 2);
    mostrarComputadoras(computadoras);
    ordenarComputadorasPorRAM(computadoras);
    mostrarComputadoras(computadoras);

    return 0;
}
