/*
 ============================================================================
 Name        : PrimerParcialLabo1-Facello.c
 Author      : Nahuel Facello
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "prestamo.h"
#include "informes.h"
#include "utn_funciones.h"

#define CANT_CLIENTES 50
#define CANT_PRESTAMOS 50



int main(void) {

	eCliente clientes[CANT_CLIENTES];
	ePrestamo prestamos[CANT_PRESTAMOS];
	int idCliente=2000;
	int idPrestamo=1;
	int opcionMenu,opcionSubMenu,opcionSubMenu2;

	setbuf(stdout,NULL);

	inicializarClientes(clientes, CANT_CLIENTES);
	inicializarPrestamo(prestamos, CANT_PRESTAMOS);
	idCliente+=harcodearClientes(clientes, CANT_CLIENTES, 10);
	idPrestamo+=harcodearPrestamos(prestamos, CANT_PRESTAMOS, 13);
	do{
		menu();
		utn_getNumeroInt(&opcionMenu, "Opcion : ", "\nError, intente nuevamente\n",1,11, 6);

		switch(opcionMenu){
		case 1:
			altaCliente(clientes,CANT_CLIENTES, idCliente);
			idCliente++;
			pauseYLimpia();
			break;
		case 2:
			if(!(clientesActivos(clientes,CANT_CLIENTES)))
				modificarCliente(clientes, CANT_CLIENTES);
			else
				errorClientes();
			pauseYLimpia();
			break;
		case 3:
			if(!(clientesActivos(clientes,CANT_CLIENTES)))
				bajaCliente(clientes,CANT_CLIENTES,prestamos, CANT_PRESTAMOS);
			else
				errorClientes();
			pauseYLimpia();
			break;
		case 4:
			if(!(clientesActivos(clientes,CANT_CLIENTES)))
			{
				altaPrestamo(prestamos,CANT_PRESTAMOS, idPrestamo, clientes,CANT_CLIENTES);
				idPrestamo++;
			}
			else
				errorClientes();
			pauseYLimpia();
			break;
		case 5:
			if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)))
				saldarPrestamo(prestamos,CANT_PRESTAMOS, clientes,CANT_CLIENTES);
			else
				errorPrestamos();
			pauseYLimpia();
			break;
		case 6:
			if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)))
				reanudarPrestamo(prestamos,CANT_PRESTAMOS,clientes,CANT_CLIENTES);
			else
				errorPrestamos();
			pauseYLimpia();
			break;
		case 7:
			if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)))
				imprimirClientesConPrestamosActivos(clientes,CANT_CLIENTES, prestamos,CANT_PRESTAMOS);
			else
				errorClientes();
			pauseYLimpia();
			break;
		case 8:
			if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)))
			imprimirPrestamosActivos(prestamos, CANT_PRESTAMOS,clientes,CANT_CLIENTES);
			else
				errorPrestamos();
			pauseYLimpia();
			break;
		case 9:
			subMenu();
			utn_getNumeroInt(&opcionSubMenu, "Opcion : ", "\nError, intente nuevamente\n",1,3, 3);
			switch(opcionSubMenu){
			case 1:
				if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)) && !(clientesActivos(clientes,CANT_CLIENTES)))
						mostrarClienteConMasCreditosActivos(clientes,CANT_CLIENTES, prestamos,CANT_PRESTAMOS);
				else
					errorAmbos();
				pauseYLimpia();
				break;
			case 2:
				if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)) && !(clientesActivos(clientes,CANT_CLIENTES)))
					mostrarClienteConMasCreditosSaldados(clientes,CANT_CLIENTES, prestamos,CANT_PRESTAMOS);
				else
					errorAmbos();
				pauseYLimpia();
				break;
			case 3:
				if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)) && !(clientesActivos(clientes,CANT_CLIENTES)))
					mostrarClienteConMasPrestamos(clientes, CANT_CLIENTES, prestamos,CANT_PRESTAMOS);
				else
					errorAmbos();
				pauseYLimpia();
				break;

			}
			break;
		case 10:
			subMenu2();
			utn_getNumeroInt(&opcionSubMenu2, "Opcion : ", "\nError, intente nuevamente\n",1,3, 3);
			switch(opcionSubMenu2){
			case 1:
				if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)) && !(clientesActivos(clientes,CANT_CLIENTES)))
					prestamosDeImporteIngresadoMayorA1000(prestamos,CANT_PRESTAMOS);
				else
					errorAmbos();
				pauseYLimpia();
				break;
			case 2:
				if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)) && !(clientesActivos(clientes,CANT_CLIENTES)))
					prestamosDe12CuotasSaldados(prestamos,CANT_PRESTAMOS,clientes, CANT_CLIENTES);
				else
					errorAmbos();
				pauseYLimpia();
				break;
			case 3:
				if(!(prestamosActivos(prestamos,CANT_PRESTAMOS)) && !(clientesActivos(clientes,CANT_CLIENTES)))
					prestamosActivosPorCantidadDeCuotas(prestamos,CANT_PRESTAMOS,clientes, CANT_CLIENTES);
				else
					errorAmbos();
				pauseYLimpia();
				break;

			}

		}
	}while(opcionMenu!=11);

	return 0;
}

