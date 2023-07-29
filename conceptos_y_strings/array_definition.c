#include "stdio.h"

int main() //funcion invocada cuando utilize el programa
{
	int array[5]; // declaramos el tipo de variable entero y lo nuevo son [] llevaran adentro el num de que cantidad de posiciones quiero ej arreglo tendra 5 arreglos adentro
	int i;		  // un indice de repetitiva exsacta que va ir definiendo posiciones en el arreglo
	for (i = 0; i < 5; i++)
	{
		array[i] = i * 2; // Asigno dentro de mi VECTOR pongo el indice que es el NUMERO DE LA POSICION a la que deseo acceder tambien asigno el resultado de multiplicar por 2 este indice
	}
	for (i = 0; i < 6; i++) //mostramos el contenido de este arreglo
	{
		printf("array[%d]= %d \n", i, array[i]); // el primero pertenece al indice y el segundo al contenido de esa celda despues llamo a la Variable indice y al contenido array que es de la celda
	}
	return 0;
}