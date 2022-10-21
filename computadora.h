/*-----------------------
 | computadora.h
 | Author: Leandro Blandi
 ------------------------*/

#ifndef COMPUTADORA_H_INCLUDED
#define COMPUTADORA_H_INCLUDED

struct _Computadora;

typedef struct _Computadora * Computadora;

/*----------------------------
 | Procedimientos individuales
 ------------------------------*/

Computadora crearComputadora(char procesador[30], char placaDeVideo[20], int cantidadRAM);
Computadora crearComputadoraPorTeclado();

void mostrarComputadora(Computadora computadora);
void destruirComputadora(Computadora computadora);


/*----------------------------
 | Procedimientos de arreglo
 ------------------------------*/

 void inicializarComputadoras(Computadora computadoras[]);
 void agregarComputadoras(Computadora computadoras[], int cantidad);
 void mostrarComputadoras(Computadora computadoras[]);
 void modificarComputadora(Computadora computadoras[], char procesador[30]);
 void eliminarComputadora(Computadora computadoras[], char procesador[30]);
 void ordenarComputadorasPorRAM(Computadora computadoras[]);


 /*----------------------------
 | Procedimientos extras
 ------------------------------*/

 int buscar(Computadora computadoras[], int elemento);

  /*----------------------------
 | Procedimientos de archivo
 ------------------------------*/
 Computadora parsearDatos(char datos[55]);
 void cargarComputadorasDesdeArchivo(Computadora computadoras[]);
 void guardarComputadorasEnArhivo(Computadora computadoras[]);

#endif // COMPUTADORA_H_INCLUDED
