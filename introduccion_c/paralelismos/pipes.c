#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define MSGSIZE 16

int main(int argc, char const *argv[])
{
	FILE *in;
	int pid, p[2];

	if (pipe(p) < 0)
	{
		printf("No pude crear los pipes\n");

		return -2;
	}

	if (!(in = fopen(argv[1], "r")))
	{
		printf("No pude leer el archivo %s\n", argv[1]);

		return -1;
	}

	if (pid = fork())
	{
		char buffer[MSGSIZE];

		printf(" ++ Soy el padre, voy a leer desde el archivo %s\n", argv[1]);

		while (fgets(buffer, MSGSIZE, in))
		{
			printf("Leí %s, Dime %d, cuál es el caracter más grande?\n", buffer, pid);

			write(p[1], buffer, MSGSIZE);
		}

		close(p[1]);
		printf("Esperando los hijos\n");
		wait(NULL);
		fclose(in);
	}
	else
	{
		char buffer[MSGSIZE], max;

		printf("Soy el hijo, espero que aparezca algo en el pipe\n");

		while (read(p[0], buffer, MSGSIZE) > 0)
		{
			printf("Leí '%s', desde el pipe \n", buffer);
			max = buffer[0];

			for (int i = 0; i < MSGSIZE; i++)
			{
				if (buffer[i] > max)
				{
					max = buffer[i];
				}
			}

			printf("El caracter máximo será %c\n", max);
		}
	}

	return 0;
}
