/*
 * informes.c
 *
 *  Created on: 14 may. 2020
 *      Author: Nahu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "prestamo.h"
#include "utn_funciones.h"

int mostrarClienteConMasCreditosActivos(eCliente aClientes[], int tamClientes, ePrestamo aPrestamos[],int tamPrestamos)
{
	int retorno=-1;
	int i,j,aux;
	int contadorPrestamos=0;
	int maxPrestamos=0;
	int flag=0;
	for(i=0;i<tamClientes;i++)
	{
		contadorPrestamos=0;

		if(aClientes[i].isEmpty==0)
		{

			for(j=0;j<tamPrestamos;j++)
			{
				if(aPrestamos[j].isEmpty==0 && aPrestamos[j].idCliente==aClientes[i].idCliente && aPrestamos[j].estadoPrestamo==1)
				{
					contadorPrestamos++;
					if(contadorPrestamos>maxPrestamos||flag==0)
					{
						maxPrestamos=contadorPrestamos;
						aux=aClientes[i].idCliente;
						flag=1;
						retorno=0;
					}
				}
			}
		}
	}
	if(maxPrestamos==0)
	{
		printf("\nNo hay clientes con prestamos activos\n");
	}
	else
	{
		printf("\nEl cliente con mas prestamos activos es :\n");
		mostrarClienteId(aClientes,tamClientes,aux);
		printf("\nCon %d prestamos activos\n",maxPrestamos);
	}
	return retorno;
}

int mostrarClienteConMasCreditosSaldados(eCliente aClientes[], int tamClientes, ePrestamo aPrestamos[],int tamPrestamos)
{
	int retorno=-1;
	int i,j,aux;
	int contadorPrestamos=0;
	int maxPrestamos=0;
	int flag=0;
	for(i=0;i<tamClientes;i++)
	{
		contadorPrestamos=0;
		if(aClientes[i].isEmpty==0)
		{

			for(j=0;j<tamPrestamos;j++)
			{
				if(aPrestamos[j].isEmpty==0 && aPrestamos[j].idCliente==aClientes[i].idCliente && aPrestamos[j].estadoPrestamo==0)
				{
					contadorPrestamos++;
					if(contadorPrestamos>maxPrestamos||flag==0)
					{
						maxPrestamos=contadorPrestamos;
						aux=aClientes[i].idCliente;
						retorno=0;
					}
				}
			}
		}
	}
	if(maxPrestamos==0)
	{
		printf("\nNo hay clientes con prestamos saldados\n");
	}
	else
	{
		printf("\nEl cliente con mas prestamos saldados es :\n");
		mostrarClienteId(aClientes,tamClientes,aux);
		printf("\nCon %d prestamos saldados\n",maxPrestamos);
	}
	return retorno;
}

int prestamosDeImporteIngresadoMayorA1000(ePrestamo aPrestamos[],int tamPrestamos)
{
	int retorno=-1;
	int i;
	float importe;
	int contadorPrestamos=0;
	int flag=-1;
	utn_getNumeroFloat(&importe,"\nIngrese el importe del cual desea saber la cantidad de prestamos ","Error, debe ser mayor a 1.000 y menor a 100.000",1000, 100000, 3);
	for(i=0;i<tamPrestamos;i++)
	{
		if(aPrestamos[i].isEmpty==0 && aPrestamos[i].importe==importe)
		{
			contadorPrestamos++;
			flag=0;
		}
	}
	if(flag==-1)
	{
		printf("\nNo se encontro ningun prestamo de ese importe\n");
	}
	else
	{
		printf("\nHay %d prestamos de %.2f\n",contadorPrestamos,importe);
		retorno=0;
	}
	return retorno;
}
int mostrarClienteConMasPrestamos(eCliente aClientes[], int tamClientes, ePrestamo aPrestamos[],int tamPrestamos)
{
	int retorno=-1;
	int i,j,aux;
	int contadorPrestamos=0;
	int maxPrestamos=0;
	int flag=0;
	for(i=0;i<tamClientes;i++)
	{
		contadorPrestamos=0;

		if(aClientes[i].isEmpty==0)
		{

			for(j=0;j<tamPrestamos;j++)
			{
				if(aPrestamos[j].isEmpty==0 && aPrestamos[j].idCliente==aClientes[i].idCliente)
				{
					contadorPrestamos++;
					if(contadorPrestamos>maxPrestamos||flag==0)
					{
						maxPrestamos=contadorPrestamos;
						aux=aClientes[i].idCliente;
						flag=1;
						retorno=0;
					}
				}
			}
		}
	}
	if(maxPrestamos==0)
	{
		printf("\nNo hay clientes con prestamos\n");
	}
	else
	{
		printf("\nEl cliente con mas prestamos:\n");
		mostrarClienteId(aClientes,tamClientes,aux);
		printf("\nCon %d prestamos\n",maxPrestamos);
	}
	return retorno;
}
int prestamosDe12CuotasSaldados(ePrestamo aPrestamos[],int tamPrestamos,eCliente aClientes[], int tamClientes)
{
	int retorno=-1;
	int i,j;
	int contadorPrestamos=0;
	int flag=-1;
	eCUIL auxCuil;

	printf("\n********** PRESTAMOS DE 12 CUOTAS SALDADOS******\n");
	printf("\nID  IMPORTE    CUOTAS   ESTADO  CUIL CLIENTE\n\n");
	for(i=0;i<tamClientes;i++)
	{
		if(aClientes[i].isEmpty==0)
		{
			for(j=0;j<tamPrestamos;j++)
			{
				if(aPrestamos[j].isEmpty==0 && aPrestamos[j].idCliente==aClientes[i].idCliente && aPrestamos[j].cantCuotas==12 && aPrestamos[j].estadoPrestamo==0 )
				{

					auxCuil=aClientes[i].cuil;
					imprimirPrestamo(aPrestamos,tamPrestamos, i, auxCuil);
					contadorPrestamos++;
					flag=0;
				}
			}
		}
	}
	if(flag==-1)
	{
		printf("\nNo se encontro ningun prestamo de 12 cuotas saldado\n");
	}
	else
	{
		printf("\nHay %d prestamos de 12 cuotas saldados\n",contadorPrestamos);
		retorno=0;
	}
	return retorno;
}
int prestamosActivosPorCantidadDeCuotas(ePrestamo aPrestamos[],int tamPrestamos,eCliente aClientes[], int tamClientes)
{
	int retorno=-1;
	int i,j;
	int cantidadDeCuotas;
	int contadorPrestamos=0;
	int flag=-1;
	eCUIL auxCuil;

	utn_getNumeroInt(&cantidadDeCuotas, "\nIngrese la cantidad de cuotas para realizar el informe: ", "\nError, por favor reintente\n",12, 72,3);
	printf("\nID  IMPORTE    CUOTAS   ESTADO  CUIL CLIENTE\n\n");
	for(i=0;i<tamClientes;i++)
	{
		if(aClientes[i].isEmpty==0)
		{
			for(j=0;j<tamPrestamos;j++)
			{
				if(aPrestamos[j].isEmpty==0 && aPrestamos[j].idCliente==aClientes[i].idCliente && aPrestamos[j].cantCuotas==cantidadDeCuotas && aPrestamos[j].estadoPrestamo==1)
				{
					auxCuil=aClientes[i].cuil;
					imprimirPrestamo(aPrestamos,tamPrestamos, i, auxCuil);
					contadorPrestamos++;
					flag=0;
				}
			}
		}
	}
	if(flag==-1)
	{
		printf("\nNo se encontro ningun prestamo de %d cuotas activo\n",cantidadDeCuotas);
	}
	else
	{
		printf("\nHay %d prestamos de %d cuotas activos\n",contadorPrestamos,cantidadDeCuotas);
		retorno=0;
	}
	return retorno;
}
void menu()
{
	printf("\n********** PRESTAMOS PERSONALES **********\n\n");
	printf( "1) Alta cliente\n"
			"2) Modificar datos del cliente\n"
			"3) Baja de cliente\n"
			"4) Nuevo prestamo\n"
			"5) Saldar prestamo\n"
			"6) Reanudar prestamo\n"
			"7) Imprimir clientes con prestamos activos\n"
			"8) Imprimir prestamos activos\n"
			"9) Informar clientes\n"
			"10) Informar prestamos\n"
			"11) Salir\n");
}
void subMenu()
{
	printf("\t1) Cliente con mas prestamos activos\n\t2) Cliente con mas prestamos saldados\n"
			"\t3) Cliente con mas prestamos\n");
}
void pauseYLimpia()
{
	system("pause");
	system("cls");
}
void errorClientes()
{
	printf("\nNo hay clientes en el sistema\n");
}
void errorPrestamos()
{
	printf("\nNo hay prestamos en el sistema\n");
}

void errorAmbos()
{
	printf("\nInformacion insuficiente para realizar el informe\n");
}
void subMenu2()
{
	printf("\t1) Informe de prestamos por importes\n\t2) Prestamos de 12 cuotas saldados\n"
			"\t3) Prestamos activos por cantidad de cuotas\n");
}
