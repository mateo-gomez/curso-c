#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct PERSON
{
	char name[20];
	int age;
};

// En este ejemplo se hizo lo mismo que en el que está en struct.c, sólo que acá se asigna los valores
// a la estructura person por referencia a la celda de memoria

void fillPerson(struct PERSON *person, char *name, int age)
{
	if (strlen(name) > 20)
	{
		printf("El máximo de dígitos para el nombre es %d\n", 20);
	}

	printf("celda person = %p\n", &person);
	printf("celda person.name = %p - valor = %s\n", &(*person).name, person->name);
	printf("celda person.age = %p - valor = %d\n", &(*person).age, person->age);

	strcpy((*person).name, name);

	// También se puede usar la notación person->age;
	(*person).age = age;

	printf("Antes Nombre = %s, Edad = %d\n", (*person).name, (*person).age);
}

int main(int argc, char *argv[])
{
	struct PERSON person;

	if (argc < 3)
	{
		printf("Por favor ingresa nombre y edad.\n");

		return 1;
	}

	fillPerson(&person, argv[1], atoi(argv[2]));

	printf("Nombre = %s, Edad = %d\n", person.name, person.age);

	return 0;
}