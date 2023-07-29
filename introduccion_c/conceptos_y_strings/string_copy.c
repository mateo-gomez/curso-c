#include "stdio.h"
#include "string.h"

int main()
{
	char *str = "Mateo";
	char hola[] = "nada";

	strcpy(str, hola);

	printf("%s\n", str);

	return 0;
}