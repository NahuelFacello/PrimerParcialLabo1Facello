/*
 * clientes.h
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct eCUIL{
	int tipo;
	long DNI;
	int aleatorio;
}eCUIL;

typedef struct eCliente{
	int idCliente;
	char nombre[51];
	char apellido[51];
	eCUIL cuil;
	int isEmpty;
}eCliente;

/*
 * breaf Busca un vector libre en el array de eCliente
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * return 0 si ok -1 si error
 */
int buscarLibre(eCliente vector[],int tam);
/*
 * breaf Inicializa con 1 el array de eCliente en isEmpty
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * return 0 si ok -1 si error
 */
int inicializarClientes(eCliente vector[], int tam);
/*
 * breaf Crea un alta en un indice libre de  eCliente
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * param idCliente int: autoincremental de ID
 * return 0 si ok -1 si error
 */
int altaCliente(eCliente vector[],int tam, int idCliente);
/*
 * breaf Crea una estructura eCliente recibiendo parametros
 * param idCliente int
 * param nombre char[]
 * param apellido char[]
 * param eCUIL cuil, estructura de cuil validada
 * return 0 si ok -1 si error
 */
eCliente nuevoCliente(int idCliente, char nombre[], char apellido[],eCUIL cuil);
/*
 * breaf Muestra por pantalla un eCliente recibido por id
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * param idCliente int: id de cliente que se quiere motrar
 * return 0 si ok -1 si error
 */
int mostrarClienteId(eCliente vector[],int tam,int idCliente);
/*
 * breaf Modifica un cliente de eCliente
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * return 0 si ok -1 si error
 */
int modificarCliente(eCliente vector[], int tam);
/*
 * breaf Pide y crea una estructura de cuil tipo eCUIL
 * param eCUIL cuil, donde va a guardar los datos del cuil
 * param mensaje char, mensaje a imprimir por pantalla
 * param mensajeError char, mensaje de error si el cuil es invalido
 * param reintentos int, reintentos para generar de forma correcta un cuil
 * return 0 si ok -1 si error
 */
int getCUIL(eCUIL* cuil, char mensaje[4069], char mensajeError[4069], int reintentos);
/*
 * breaf Recibe en cuil por parametro y lo valida
 * param eCUIL cuil, va a validar los datos de cuil
 * return 0 si ok -1 si error
 */
int validarCuil(eCUIL cuil);
/*
 * breaf Imprime el cuil por consola
 * param eCUIL cuil
 */
void imprimirCuil(eCUIL cuil);
/*
 * breaf Verifica si hay clientes cargados
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * return 0 si hay, -1 si no
 */
int clientesActivos(eCliente vector[], int tam);
/*
 * breaf Hardcodea clientes en el vector eCliente hasta 10 clientes
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * param cantidad int cantidad de clientes a adicionar
 * return 0 si OK, -1 si error
 */
int harcodearClientes(eCliente vector[], int tam, int cantidad);
/*
 * breaf Muestra por pantalla los clientes eCliente activos
 * param vector array de eCliente
 * param tam int tamaño del vector de eCliente
 * return 0 si ok -1 si error
 */
int mostrarClientes(eCliente vector[],int tam);
#endif /* CLIENTES_H_ */
