#include <stdio.h>
#include <stdlib.h>
#include "computadora.h"

int main()
{

    Computadora computadora = crearComputadoraPorTeclado();
    mostrarComputadora(computadora);

    return 0;
}
