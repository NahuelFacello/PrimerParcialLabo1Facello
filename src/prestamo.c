/*
 * prestamo.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prestamo.h"
#include "clientes.h"
#include "utn_funciones.h"

int inicializarPrestamo(ePrestamo aPrestamo[], int tamPrestamo)
{
	int i;
	for(i = 0;i < tamPrestamo;i++)
	{
		aPrestamo[i].isEmpty=1;
		aPrestamo[i].estadoPrestamo=-1;
		aPrestamo[i].idCliente=-1;
	}
	return 0;
}
int buscarLibrePrestamo(ePrestamo aPrestamo[],int tamPrestamo)
{
	int indice=-1;
	int i;
	for(i=0;i<tamPrestamo;i++)
	{
		if(aPrestamo[i].isEmpty==1)
		{
			indice=i;
		}
	}
	return indice;
}

void imprimirPrestamo(ePrestamo aPrestamo[],int tamPrestamo, int indice, eCUIL cuilCliente)
{
	char cancelado[21]={"Cancelado"};
	char activo[21]={"Activo"};
	if(aPrestamo[indice].isEmpty==0)
	{
		if(aPrestamo[indice].estadoPrestamo==1)
		{
			printf("%4d %8.2f %4d %10s %d-%ld-%d",aPrestamo[indice].idPrestamo, aPrestamo[indice].importe,aPrestamo[indice].cantCuotas,activo,cuilCliente.tipo,cuilCliente.DNI,cuilCliente.aleatorio);
		}
		else
		{
			printf("%4d %8.2f %4d %10s %d-%ld-%d",aPrestamo[indice].idPrestamo, aPrestamo[indice].importe,aPrestamo[indice].cantCuotas,cancelado,cuilCliente.tipo,cuilCliente.DNI,cuilCliente.aleatorio);
		}
	}

}
int imprimirPrestamosActivos(ePrestamo aPrestamo[], int tamPrestamo,eCliente aClientes[],int tamCliente)
{
	int retorno=-1;
	int i,j,flag=-1;
	eCUIL auxCuil;
	printf("\nID  IMPORTE    CUOTAS   ESTADO  CUIL CLIENTE\n\n");
	for(i=0; i< tamPrestamo;i++)
	{
		if(aPrestamo[i].estadoPrestamo==1 && aPrestamo[i].isEmpty==0)
		{
			for(j=0;j<tamCliente;j++)
			{
				if(aPrestamo[i].idCliente==aClientes[j].idCliente)
				{
					auxCuil=aClientes[j].cuil;
				}
			}
			imprimirPrestamo(aPrestamo,tamPrestamo, i, auxCuil);
			flag=0;
			retorno=0;
		}
	}
	if(flag==-1)
	{
		printf("\nTodos los prestamos estan saldados\n");
	}
	return retorno;
}
int altaPrestamo(ePrestamo aPrestamo[],int tamPrestamo, int idPrestamo, eCliente aCliente[],int tamCliente)
{
	int retorno=-1;
	int indice;
	float importe;
	int cuotas;
	char respuesta;
	int idCliente;
	int auxMostrarCliente;

	printf("\n***************ALTA PRESTAMO************\n");

	indice=buscarLibrePrestamo(aPrestamo,tamPrestamo);

	if(indice==-1)
	{
		printf("El sistema esta lleno\n");
	}else
	{
		do{
			utn_getNumeroInt(&idCliente,"\nIngrese el ID del cliente: \n", "Error, por favor intente de nuevo\n",2000,2050,3);

			auxMostrarCliente = mostrarClienteId(aCliente,tamCliente,idCliente);
			if(auxMostrarCliente==-1)
			{
				printf("No se encuentra ese cliente\n");
			}
		}while(auxMostrarCliente==-1);

		utn_getNumeroFloat(&importe,"\nIngrese el importe del prestamo: ","Error, el prestamo excede el limite\n",0, 100000,3);
		utn_getNumeroInt(&cuotas,"\nIngrese la cantidad de cuotas: ", "Error, el prestamo excede la cantidad de cuotas\n",0,72,3);

		fflush(stdin);
		utn_getAnswer(&respuesta,"\nDesea confirmar el alta? s/n: ", "Error, por favor intente de nuevo\n", 3);

		if(respuesta=='s')
		{
			aPrestamo[indice]=nuevoPrestamo(idPrestamo,idCliente,importe,cuotas);
			retorno=0;
			printf("\n\nAlta realizada con exito\n\nNumero de prestamo %d\n\n",aPrestamo[indice].idPrestamo);
		}else
		{
			printf("\nAlta cancelada\n");
		}
		system("pause");
		system("cls");
	}
	return retorno;
}

ePrestamo nuevoPrestamo(int idPrestamo,int idCliente, float importe, int cuotas)
{
	ePrestamo estructuraPrestamo;

	estructuraPrestamo.idCliente=idCliente;
	estructuraPrestamo.idPrestamo=idPrestamo;
	estructuraPrestamo.importe=importe;
	estructuraPrestamo.cantCuotas=cuotas;
	estructuraPrestamo.isEmpty=0;
	estructuraPrestamo.estadoPrestamo=1;

	return estructuraPrestamo;
}

int saldarPrestamo(ePrestamo aPrestamo[],int tamPrestamo, eCliente aClientes[],int tamClientes)
{
	int retorno=-1;
	int idPrestamo;
	int flag=0;
	int i, aux;
	char respuesta;

	printf("\n***************SALDAR PRESTAMO************\n");

	utn_getNumeroInt(&idPrestamo,"\nIngrese el ID del prestamo que desea saldar :", "Error, por favor intente de nuevo\n",1,50,3);
	for(i=0; i< tamPrestamo;i++)
	{
		if(aPrestamo[i].idPrestamo==idPrestamo && aPrestamo[i].isEmpty==0 )
		{
			aux=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nNo hay un prestamo con ese ID\n");
	}
	else
	{
		utn_getAnswer(&respuesta,"\nDesea confirmar la operacion? s/n: ", "\nOpcion incorrecta\n", 3);
		if(respuesta=='s')
		{
			aPrestamo[aux].estadoPrestamo=0;
			retorno=0;
			printf("\nPrestamo saldadado con exito!\n");
		}
		else
		{
			printf("\nOperacion cancelada\n");
		}
	}
	return retorno;
}

int bajaCliente(eCliente vector[],int tam,ePrestamo aPrestamo[], int tamPrestamo)
{
	int retorno=-1;
	int i;
	char respuesta;
	int idCliente;
	int flag=0;
	int aux, auxEstadoPrestamo;
	int contadorPrestamosActivos=0;
	printf("\n*****************BAJA CLIENTES ***************\n");

	utn_getNumeroInt(&idCliente,"\nIngrese el id del cliente que desea dar de baja\n", "Error, por favor intente de nuevo\n",2000,2050,3);
	for(i=0;i<tam;i++)
	{
		if(vector[i].idCliente==idCliente && vector[i].isEmpty==0)
		{
			flag=1;
			mostrarClienteId(vector,tam,idCliente);
			aux=i;
			break;
		}
	}
	if(flag==0)
	{
		printf("No se encontro un cliente con ese ID\n");
	}
	else
	{
		for(i=0; i<tamPrestamo; i++)
		{
			if(aPrestamo[i].idCliente==idCliente && aPrestamo[i].estadoPrestamo==1)
			{
				auxEstadoPrestamo=1;
				contadorPrestamosActivos++;
			}
		}
		if(auxEstadoPrestamo==1)
		{
			printf("\nNo se puede realizar la baja, el cliente tiene %d prestamo/s activo/s\n",contadorPrestamosActivos);
		}
		else
		{
			fflush(stdin);
			utn_getAnswer(&respuesta,"\nEsta seguro que desea dar de baja? s/n \n", "\nOpcion incorrecta\n", 3);
			if(respuesta=='s')
			{
				vector[aux].isEmpty=1;
				for(i=0; i<tamPrestamo; i++)
				{
					if(aPrestamo[i].idCliente==idCliente)
						aPrestamo[i].isEmpty=0;
				}
				retorno=0;
				printf("\nBaja realizada con exito\n");
			}
			else
			{
				printf("\nSe cancelo la operacion\n");
			}
		}

	}
	return retorno;
}
int imprimirClientesConPrestamosActivos(eCliente aClientes[],int tamClientes, ePrestamo aPrestamo[], int tamPrestamo)
{
	int retorno=-1;
	int i,j;
	int contadorActivos=0;
	int flag=-1;

	printf("\nID         NOMBRE    APELLIDO    CUIL        PRESTAMOS ACTIVOS\n");
	for(i=0;i<tamClientes;i++)
	{
		contadorActivos=0;
		if(aClientes[i].isEmpty==0)
		{
			for(j=0; j < tamPrestamo;j++)
			{
				if((aPrestamo[j].estadoPrestamo==1) && (aPrestamo[j].idCliente==aClientes[i].idCliente))
				{
					contadorActivos++;
				}
			}
			if(contadorActivos>0)
			{
				printf("%4d %12s %12s %d-%ld-%d %8d\n",aClientes[i].idCliente,aClientes[i].nombre,aClientes[i].apellido,aClientes[i].cuil.tipo,aClientes[i].cuil.DNI,aClientes[i].cuil.aleatorio,contadorActivos);
				flag=0;
			}
		}
	}
	if(flag==-1)
	{
		printf("\nNo existen datos para mostrar\n");
	}
	return retorno;
}
int reanudarPrestamo(ePrestamo aPrestamo[],int tamPrestamo, eCliente aClientes[], int tamClientes)
{
	int retorno=-1;
	int idPrestamo;
	int i,j,auxCliente,auxPrestamo;
	int flag=-1;
	char respuesta;
	printf("\n********* REANUDAR PRESTAMO *********\n\n");
	utn_getNumeroInt(&idPrestamo,"\nIngrese el id del prestamo que desea reanudar\n", "Error, por favor intente de nuevo\n",1,50,3);
	for(i=0;i<tamPrestamo;i++)
	{
		if(aPrestamo[i].idPrestamo==idPrestamo && aPrestamo[i].estadoPrestamo==0)
		{
			for(j=0;j<tamClientes;j++)
			{
				if(aClientes[j].idCliente==aPrestamo[i].idCliente)
				{
					auxCliente=j;
					auxPrestamo=i;
					flag=0;
				}
			}
		}

	}
	if(flag==0)
	{
		mostrarClienteId(aClientes,tamClientes,auxCliente);
		utn_getAnswer(&respuesta,"\nEsta seguro que desea reanudar el prestamo? s/n \n", "\nOpcion incorrecta\n", 3);
		if(respuesta=='s')
		{
			aPrestamo[auxPrestamo].estadoPrestamo=1;
			retorno=0;
			printf("\nOperacion realizada con exito\n");
		}
		else
		{
			printf("\nSe cancelo la operacion\n");
		}
	}
	return retorno;
}
int prestamosActivos(ePrestamo aPrestamo[], int tamPrestamo)
{
	int retorno=-1;
	int i;
	for(i=0; i<tamPrestamo;i++)
	{
		if(aPrestamo[i].isEmpty==0)
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}
int harcodearPrestamos(ePrestamo aPrestamo[], int tamPrestamo, int cantidad)
{
	int i;
	int contador=0;

	ePrestamo auxiliar[]={
			{1,2000,15000,12,0,1},
			{2,2001,10500,12,0,1},
			{3,2002,25000,12,0,1},
			{4,2003,99000,12,0,1},
			{5,2004,15000,12,0,1},
			{6,2005,23000,12,0,1},
			{7,2006,45000,12,0,1},
			{8,2007,56000,12,0,1},
			{9,2008,47000,12,0,1},
			{10,2009,12000,12,0,1},
			{11,2008,8000,24,0,1},
			{12,2002,15000,36,0,0},
	};

	if(cantidad<13 && cantidad<=tamPrestamo)
	{
		for(i=0;i < cantidad; i++)
		{
			aPrestamo[i]=auxiliar[i];
			contador++;
		}
	}
	return contador;
}
