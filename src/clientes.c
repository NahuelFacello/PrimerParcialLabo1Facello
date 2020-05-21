/*
 * clientes.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prestamo.h"
#include "clientes.h"
#include "utn_funciones.h"

int buscarLibre(eCliente vector[],int tam)
{
	int indice=-1;
	int i;
	for(i=0;i<tam;i++)
	{
		if(vector[i].isEmpty==1)
		{
			indice=i;
		}
	}
	return indice;
}

int inicializarClientes(eCliente vector[], int tam)
{
	int i;
	for(i = 0;i < tam;i++)
	{
		vector[i].isEmpty=1;
	}
	return 0;
}
int validarCuil(eCUIL cuil)
{
	int retorno=0;
	if(cuil.tipo>99||cuil.tipo<11||cuil.DNI>99999999||cuil.DNI<11111111||cuil.aleatorio>9||cuil.aleatorio<0)
	{
		retorno=-1;
	}
	return retorno;
}
int getCUIL(eCUIL* cuil, char mensaje[4069], char mensajeError[4069], int reintentos)
{
	int retorno=-1;
	int tipo;
	long DNI;
	int aleatorio;
	eCUIL aux;
	do{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%d-%ld-%d",&tipo,&DNI,&aleatorio);
		aux.tipo=tipo;
		aux.DNI=DNI;
		aux.aleatorio=aleatorio;
		if(!validarCuil(aux))
		{
			cuil->tipo=tipo;
			cuil->DNI=DNI;
			cuil->aleatorio=aleatorio;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos--;
		}
	}while(reintentos>0);
	return retorno;
}

void imprimirCuil(eCUIL cuil)
{
	printf("%d-%ld-%d",cuil.tipo,cuil.DNI,cuil.aleatorio);
}

int altaCliente(eCliente vector[],int tam, int idCliente)
{
	int retorno=-1;
	int indice;
	char nombre[51];
	char apellido[51];
	char respuesta;
	eCUIL cuil;

	printf("\n***************ALTA CLIENTE************\n");

	indice=buscarLibre(vector,tam);

	if(indice==-1)
	{
		printf("El sistema esta lleno\n");
	}else
	{
		fflush(stdin);
		utn_getAChar(nombre, "\nIngrese el nombre: ", "\nError, por favor intente de nuevo\n", 3, 51);

		fflush(stdin);
		utn_getAChar(apellido, "\nIngrese el apellido: ", "\nError, por favor intente de nuevo\n", 3, 51);


		getCUIL(&cuil, "\nIngrese el numero de CUIL: ##-#########-# ", "\nError, por favor intente de nuevo\n", 3);

		fflush(stdin);
		utn_getAnswer(&respuesta,"Quiere guardar los cambios? s/n ", "\nError, por favor intente de nuevo\n", 3);

		if(respuesta=='s')
		{
			vector[indice]=nuevoCliente(idCliente,nombre,apellido,cuil);
			retorno=0;
			printf("\n\nAlta realizada con exito\n\nNumero de cliente %d\n\n",vector[indice].idCliente);
		}else
		{
			printf("\nAlta cancelada\n");
		}

	}
	return retorno;
}

eCliente nuevoCliente(int idCliente, char nombre[], char apellido[],eCUIL cuil)
{
	eCliente estructuraCliente;

	estructuraCliente.idCliente=idCliente;
	strncpy(estructuraCliente.nombre,nombre,51);
	strncpy(estructuraCliente.apellido,apellido,51);
	estructuraCliente.isEmpty=0;
	estructuraCliente.cuil=cuil;

	return estructuraCliente;
}

int mostrarClienteId(eCliente vector[],int tam,int idCliente)
{
	int i;
	int retorno=-1;
	for(i=0; i < tam;i++)
	{
		if(vector[i].idCliente==idCliente && vector[i].isEmpty==0)
		{
			printf("\nIdCliente : %d\n",vector[i].idCliente);
			printf("Nombre : %s\n",vector[i].nombre);
			printf("Apellido : %s\n",vector[i].apellido);
			printf("CUIL : %d-%ld-%d\n",vector[i].cuil.tipo,vector[i].cuil.DNI,vector[i].cuil.aleatorio);
			retorno=0;
		}
	}
	return retorno;
}

int modificarCliente(eCliente vector[], int tam)
{
	int retorno=-1;
	int i;
	char respuesta;
	int opcion=0;
	int idCliente;
	int flag=0;
	int aux;
	char nombre[51];
	char apellido[51];
	eCUIL cuil;

	printf("\n*****************MODIFICAR CLIENTES ***************\n");

	mostrarClientes(vector,tam);
	utn_getNumeroInt(&idCliente,"\nIngrese el ID del cliente que desea modificar: ", "\nError, por favor intente de nuevo\n",2000,2050,3);
	for(i=0;i<tam;i++)
	{
		if(vector[i].idCliente==idCliente && vector[i].isEmpty==0)
		{
			flag=1;
			mostrarClienteId(vector,tam,idCliente);
			aux=i;
		}
	}
	if(!flag)
	{
		printf("\nNo se encontro un cliente con ese ID\n");
	}
	else
	{

		utn_getNumeroInt(&opcion,"\n1) Modificar nombre\n"
				"2) Modificar apellido\n"
				"3) Modificar CUIL\n"
				" Opcion: ", "\nError, por favor intente de nuevo\n",1,3,3);
		switch(opcion)
		{
			case 1:
				fflush(stdin);
				utn_getAChar(nombre, "\nIngrese el nombre: ", "\nError, por favor intente de nuevo\n", 3, 51);
			  break;

			case 2:
				fflush(stdin);
				utn_getAChar(apellido, "\nIngrese el apellido: ", "\nError, por favor intente de nuevo\n", 3, 51);
			  break;

			case 3:
				getCUIL(&cuil, "\nIngrese el numero de CUIL: ##-#########-# ", "\nError, por favor intente de nuevo\n", 3);
			  break;

		}

		fflush(stdin);
		utn_getAnswer(&respuesta,"Quiere guardar los cambios? s/n ", "\nError, por favor intente de nuevo\n", 3);
		if(respuesta=='s')
		{
			switch(opcion)
			{
				case 1:
					strncpy(vector[aux].nombre,nombre,51);
				  break;

				case 2:
					strncpy(vector[aux].apellido,apellido,51);
				  break;

				case 3:
					vector[aux].cuil=cuil;
				  break;
			}
			retorno=0;
			printf("\nModificacion realizada con exito\n");
		}else
		{
			printf("\nSe cancelo la operacion\n");
		}
	}
	return retorno;
}
int clientesActivos(eCliente vector[], int tam)
{
	int retorno=-1;
	int i;
	for(i=0; i<tam;i++)
	{
		if(vector[i].isEmpty==0)
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}
int harcodearClientes(eCliente vector[], int tam, int cantidad)
{
	int i;
	int contador=0;

	eCliente auxiliar[]={
			{2000,"Nahuel","Facello",{23,29753698,0},0},
			{2001,"Micaela","Martinez",{27,29753698,1},0},
			{2002,"Marta","Susanez",{29,29753698,2},0},
			{2003,"Alejandro","Perez",{30,29753698,3},0},
			{2004,"Susana","Martinez",{27,29753698,4},0},
			{2005,"Mariana","Gomez",{30,29753698,5},0},
			{2006,"Martina","Caseres",{27,29753698,6},0},
			{2007,"Rosa","Gimenez",{27,29753698,7},0},
			{2008,"Guillermo","Bruno",{23,29753698,8},0},
			{2009,"Jose Luis","Perez",{30,29753698,9},0}
	};

	if(cantidad<11 && cantidad<=tam)
	{
		for(i=0;i < cantidad; i++)
		{
			vector[i]=auxiliar[i];
			contador++;
		}
	}
	return contador;
}
int mostrarClientes(eCliente vector[],int tam)
{
	int i;
	int retorno=-1;
	printf("\nID   NOMBRE    APELLIDO    CUIL\n");
	for(i=0; i < tam;i++)
	{
		if(vector[i].isEmpty==0)
		{
			printf("\n%d",vector[i].idCliente);
			printf("%10s",vector[i].nombre);
			printf("%10s",vector[i].apellido);
			printf("%4d-%ld-%d",vector[i].cuil.tipo,vector[i].cuil.DNI,vector[i].cuil.aleatorio);
			retorno=0;
		}
	}
	return retorno;
}
