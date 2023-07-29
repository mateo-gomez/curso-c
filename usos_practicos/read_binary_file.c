#include <stdlib.h>
#include <stdio.h>

struct person
{
	char name[100];
	unsigned int age;
};

int main(int argc, char const *argv[])
{
	FILE *in;
	struct person p;

	if (argc < 2)
	{
		printf("Debe especificar el nombre del archivo\n");

		return -1;
	}

	if (!(in = fopen(argv[1], "r")))
	{
		printf("No puedo leer el archivo %s \n", argv[1]);

		return -2;
	}

	while (fread(&p, sizeof p, 1, in))
	{
		printf("%s tiene %d años\n", p.name, p.age);
	}

	fclose(in);

	return 0;
}
