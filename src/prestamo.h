/*
 * prestamo.h
 *
 */
#ifndef PRESTAMO_H_
#define PRESTAMO_H_
#include "clientes.h"

typedef struct ePrestamo{
	int idPrestamo;
	int idCliente;
	float importe;
	int cantCuotas;
	int isEmpty;
	int estadoPrestamo;
}ePrestamo;

/*
 * breaf Crea una estructura ePrestamo recibiendo parametros
 * param idPrestamo int autoincremental
 * param idCliente int
 * param importe float
 * param cuotas int
 * return 0 si ok -1 si error
 */
ePrestamo nuevoPrestamo(int idPrestamo,int idCliente, float importe, int cuotas);
/*
 * breaf Crea un alta en un indice libre de ePrestamo
 * param vector array de ePrestamo
 * param tam int tamaño del vector de ePrestamo
 * param idPrestamo int: autoincremental de ID
 * param aCliente eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int altaPrestamo(ePrestamo aPrestamo[],int tamPrestamo, int idPrestamo, eCliente aCliente[],int tamCliente);
/*
 * breaf Busca un vector libre en el array de eCliente
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * return 0 si ok -1 si error
 */
int buscarLibrePrestamo(ePrestamo aPrestamo[],int tamPrestamo);
/*
 * breaf Inicializa con 1 el array de ePrestamo en isEmpty
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * return 0 si ok -1 si error
 */
int inicializarPrestamo(ePrestamo aPrestamo[], int tamPrestamo);
/*
 * breaf Solicita el prestamo que se quiere cancelar
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aCliente eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int saldarPrestamo(ePrestamo aPrestamo[],int tamPrestamo, eCliente aClientes[],int tamClientes);
/*
 * breaf Da de baja de forma logica los clientes que no tengan prestamos activos
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aCliente eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int bajaCliente(eCliente vector[],int tam,ePrestamo aPrestamo[], int tamPrestamo);
/*
 * breaf Imprime todos los clientes que tengan prestamos activos
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aCliente eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int imprimirClientesConPrestamosActivos(eCliente aClientes[],int tamClientes, ePrestamo aPrestamo[], int tamPrestamo);
/*
 * breaf Imprime un prestamo con cuil de cliente
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param indice int, indice para imprimir el cliente
 * param cuilCliente eCUIL
 */
void imprimirPrestamo(ePrestamo aPrestamo[],int tamPrestamo, int indice, eCUIL cuilCliente);
/*
 * breaf Imprime todos prestamos que se encuntren activos
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aClientes eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int imprimirPrestamosActivos(ePrestamo aPrestamo[], int tamPrestamo,eCliente aClientes[],int tamCliente);
/*
 * breaf Reanuda prestamos que hayan sido dados de baja
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aClientes eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int reanudarPrestamo(ePrestamo aPrestamo[],int tamPrestamo, eCliente aClientes[], int tamClientes);
/*
 * breaf Verifica si hay prestamos cargados
 * param vector array de ePrestamo
 * param tam int tamaño del vector de ePrestamo
 * return 0 si hay, -1 si no
 */
int prestamosActivos(ePrestamo aPrestamo[], int tamPrestamo);
/*
 * breaf Hardcodea prestamos en el vector eCliente hasta 12 prestamos para los 10 clientes del hardcodeo
 * param vector array de ePrestamo
 * param tam int tamaño del vector de ePrestamo
 * param cantidad int cantidad de prestamos a adicionar
 * return 0 si OK, -1 si error
 */
int harcodearPrestamos(ePrestamo aPrestamo[], int tamPrestamo, int cantidad);
/*
 * breaf Imprime todos prestamos que se encuntren inactivos
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aClientes eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int imprimirPrestamosInactivos(ePrestamo aPrestamo[],int tamPrestamo, eCliente aClientes[], int tamClientes);
/*
 * breaf Muestra por pantalla el cliente que tiene mas prestamos solicitados, dados de baja o no
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aClientes eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int mostrarClienteConMasPrestamos(eCliente aClientes[], int tamClientes, ePrestamo aPrestamos[],int tamPrestamos);
/*
 * breaf Muestra por pantalla los prestamos inactivos de 12 cuotas
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tamaño del vector de ePrestamo
 * param aClientes eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * return 0 si ok -1 si error
 */
int imprimirPrestamosInactivosDe12cuotas(ePrestamo aPrestamo[],int tamPrestamo, eCliente aClientes[], int tamClientes);

#endif /* PRESTAMO_H_ */
