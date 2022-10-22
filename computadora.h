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

/// @pre: Nada
/// @post: Devuelve un struct _Computadora
Computadora crearComputadora(char procesador[30], char placaDeVideo[20], int cantidadRAM);

/// @pre: Se ingresa por stdin cada atributo de struct _Computadora
/// @post: Devuelve un struct _Computadora personalizado
Computadora crearComputadoraPorTeclado();

/// @pre: El struct _Computadora debe ser no-filtrable
/// @post: Devuelve todos los datos del struct _Computadora
void mostrarComputadora(Computadora computadora);

/// @pre: Debe existir y ocupar memoria el struct _Computadora
/// @post: Libera la direccion de memoria para que sea usada por otros programas
void destruirComputadora(Computadora computadora);


/*----------------------------
 | Procedimientos de arreglo
 ------------------------------*/

/// @pre: Debe existir el arreglo struct _Computadora computadoras[]
/// @post: Setea los valores de cada struct _Computadora como vacio, o -1
void inicializarComputadoras(Computadora computadoras[]);

/// @pre: Debe existir el arreglo struct _Computadora computadoras[] y { -1 < cantidad < CANTIDAD_COMPUTADORAS }, ademas debe haber lugar
/// @post: Agrega en algunas posiciones libres un struct _Computadora por stdin
void agregarComputadoras(Computadora computadoras[], int cantidad);

/// @pre: Debe existir el arreglo struct _Computadora computadoras[] y cada struct _Computadora debe ser no-filtrable
/// @post: Devuelve todos los datos de los atributos
void mostrarComputadoras(Computadora computadoras[]);

/// @pre: Debe existir tanto el arreglo como el struct _Computadora con el nombre a modificar
/// @post: Se reingresan los datos por stdin modificando cada atributo
void modificarComputadora(Computadora computadoras[], char procesador[30]);

/// @pre: Debe existir tanto el arreglo como el struct _Computadora con el nombre a eliminar
/// @post: Setea todos sus atributos en vacio, o -1
void eliminarComputadora(Computadora computadoras[], char procesador[30]);

/// @pre: Debe existir el arreglo y deben haber struct _Computadoras no-filtrables
/// @post: Ordena por cantidad de memoria RAM instalada ascendente
void ordenarComputadorasPorRAM(Computadora computadoras[]);


/*----------------------------
| Procedimientos extras
------------------------------*/

/// @pre: Debe existir el arreglo y el struct _Computadora con atributo memoriaRAM = elemento
/// @post: Devuelve la posicion del struct _Computadora coincidente, si no lo encuentra, devuelve NO_ENCONTRADO
int buscar(Computadora computadoras[], int elemento);


/*----------------------------
| Procedimientos de archivo
------------------------------*/

/// @pre: La cadena pasada por parametro debe ser de la forma '%s-%s-%d'
/// @post: Devuelve un struct _Computadora con los atributos parseados de la cadena
Computadora parsearDatos(char datos[55]);

/// @pre: Tanto el arreglo como el archivo 'computadoras.txt' deben existir
/// @post: Parsea los valores leidos haciendo uso de la funcion anterior, e inserta en cada posicion el struct ya parseado
void cargarComputadorasDesdeArchivo(Computadora computadoras[]);

/// @pre: El arreglo debe existir y ademas, contener struct _Computadora no-filtrable
/// @post: Escribe en el archivo 'computadoras.txt' cada struct _Computadora que se encuentra en computadoras[]
void guardarComputadorasEnArhivo(Computadora computadoras[]);

#endif // COMPUTADORA_H_INCLUDED
