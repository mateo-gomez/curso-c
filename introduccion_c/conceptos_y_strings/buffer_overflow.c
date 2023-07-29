#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	// El buffer overflow sucede cuando se trata de escribir por fuera del tamaño reservado
	// como en este ejemplo en donde se va a copiar el contenido del primer argumento
	// a una variable con un espacio displonible de 20 caracteres. según lo anterior,
	// si el tamaño de lo que se pase por argumento es mayor a 20 va a suceder un buffer overflow

	char buffer[20];
	char *buffer2 = "hola como estas";

	printf("before buffer2 = %s\n", buffer2);
	strcpy(buffer, argv[1]);
	printf("after buffer2 = %s\n", buffer2);

	return 0;
}