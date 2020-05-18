/*
 * informes.h
 *
 *  Created on: 14 may. 2020
 *      Author: Nahu
 */

#ifndef INFORMES_H_
#define INFORMES_H_
//Menu de opciones
void menu();
//Sub menu de opciones para informes
void subMenu();
//pausa en la consola y limpia la consola
void pauseYLimpia();
//Mensaje de error si no hay prestamos activos
void errorPrestamos();
//Mensaje de error si no hay clientes activos
void errorClientes();
//informacion insuficiente para realizar el informe
void errorAmbos();
/*
 * breaf Muestra los clientes que tienen mas creditos activos
 * param aCliente eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tama�o del vector de ePrestamo
 * return 0 si ok -1 si error
 */
int mostrarClienteConMasCreditosActivos(eCliente aClientes[], int tamClientes, ePrestamo aPrestamos[],int tamPrestamos);
/*
 * breaf Muestra los clientes que tienen mas creditos saldados
 * param aCliente eCliente, para validar el cliente
 * param tamCliente int, para recorrer el vector de eCliente
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tama�o del vector de ePrestamo
 * return 0 si ok -1 si error
 */
int mostrarClienteConMasCreditosSaldados(eCliente aClientes[], int tamClientes, ePrestamo aPrestamos[],int tamPrestamos);
/*
 * breaf Pide un importe del prestamo mayor a 1000 y muestra la cantidad de prestamos de ese importe
 * param aPrestamo array de ePrestamo
 * param tamPrestamo int tama�o del vector de ePrestamo
 * return 0 si ok -1 si error
 */
int prestamosDeImporteIngresadoMayorA1000(ePrestamo aPrestamos[],int tamPrestamos);


#endif /* INFORMES_H_ */
