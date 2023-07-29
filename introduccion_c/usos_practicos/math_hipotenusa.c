#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{

	int a, b;

	if (argc != 3)
	{
		printf("No se ingresó ningún valor a calcular\n");

		return 0;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	float h = sqrt(pow(a, 2) + pow(b, 2));

	printf("La hipotenusa es: %.2f \n", h);

	return 0;
}