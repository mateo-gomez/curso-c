#include <stdio.h>
#include <stdlib.h>

int buffer;
long result;

long factorial(int n)
{
	if (n == 0)
		return 1;

	return (n * factorial(n - 1));
}

int main(int argc, char const *argv[])
{

	printf("Ingresa un número para calcular su valor factorial\n");
	scanf("%d", &buffer);

	if (buffer > 0)
	{
		result = factorial(buffer);
		printf("%ld\n", result);
	}

	return 0;
}
