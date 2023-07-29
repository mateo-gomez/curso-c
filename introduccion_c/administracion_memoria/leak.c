#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p = NULL;

	for (int i = 0; i < 10; i++)
	{
		if (p)
		{
			// Los leak son espacios en memoria reservados en el programa que ya no pueden ser usados
			// incluso después de terminar la ejecución del programa.
			// por lo anterior se debe liberar el espacio reservado en memoria con la función free()
			free(p);
		}

		printf("%d - Alocando 50 chars en memoria.\n", i);
		p = malloc(sizeof(char) * 50);
	}

	// Para detectar leaks en el programa se usa valgrind en la ejecución del programa
	// ej: >	valgrind ./leak

	free(p);
	return 0;
}