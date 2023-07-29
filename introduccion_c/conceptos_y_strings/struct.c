#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, const char *argv[])
{
	int maxName = 20;

	struct
	{
		char name[maxName];
		int age;
	} person;

	if (argc < 3)
	{
		printf("Por favor ingresa nombre y edad.\n");

		return 1;
	}

	if (strlen(argv[1]) > maxName)
	{
		printf("El máximo de dígitos para el nombre es %d\n", maxName);

		return 1;
	}

	strcpy(person.name, argv[1]);

	person.age = atoi(argv[2]);

	printf("Nombre = %s, Edad = %d\n", person.name, person.age);

	return 0;
}