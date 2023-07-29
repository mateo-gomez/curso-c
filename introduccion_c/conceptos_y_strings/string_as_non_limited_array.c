#include "stdio.h"

int main()
{
	// Si se pone el número exacto de caracteres que tiene el string el compilador no sabe hasta qué espacio en memoria
	// llega dicho string, por lo que va a seguir imprimiendo caracteres.

	char name[18] = "Mateo Gomez Molina";

	// para solucionarlo se debe adicionar un espacio más en cual se va a incluir el caracter "\0", el cual indica el final del string
	char name[19] = "Mateo Gomez Molina";


	printf("Mi nombre es: %s\n", name);

	return 0;
}