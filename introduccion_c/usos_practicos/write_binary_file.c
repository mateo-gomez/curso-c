#include <stdlib.h>
#include <stdio.h>

struct person
{
	char name[100];
	unsigned int age;
};

int main(int argc, char const *argv[])
{
	FILE *out;
	struct person p;
	char buffer[100];

	if (argc < 2)
	{
		printf("Debe especificar el nombre del archivo\n");

		return -1;
	}

	if (!(out = fopen(argv[1], "w")))
	{
		printf("No puedo crear el archivo %s \n", argv[1]);

		return -2;
	}

	do
	{
		printf("Ingrese nombre ");
		scanf("%99s", p.name);

		printf("Ingrese edad \n");
		scanf("%d", &p.age);

		fwrite(&p, sizeof p, 1, out);

		printf("Guardado!. otra? (s/n)\n");
		scanf("%99s", buffer);

	} while (buffer[0] != 'n');

	fclose(out);

	return 0;
}
