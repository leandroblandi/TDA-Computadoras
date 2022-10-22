#include <stdio.h>
#include <stdlib.h>
#include "computadora.h"

#define CANTIDAD_COMPUTADORAS 2

int main()
{

    Computadora computadoras[CANTIDAD_COMPUTADORAS];
    inicializarComputadoras(computadoras);
    cargarComputadorasDesdeArchivo(computadoras);
    mostrarComputadoras(computadoras);

    modificarComputadora(computadoras, "Ryzen 5 5600G");
    eliminarComputadora(computadoras, "Intel i9 12900K");

    mostrarComputadoras(computadoras);

    return 0;
}
