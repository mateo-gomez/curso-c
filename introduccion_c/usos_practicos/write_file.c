#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *out;
	char buffer[100];

	if (!(out = fopen(argv[1], "w")))
	{
		printf("No puedo escribir el archivo %s \n", argv[1]);

		return -1;
	}

	do
	{
		printf("Ingresa una palabra\n");
		scanf("%99s", buffer);
		fputs(buffer, out);
		fputs("\n", out);
		printf("Palabra guardada. Otra? (s/n) \n");
		scanf("%99s", buffer);

	} while (buffer[0] != 'n');

	fclose(out);

	return 0;
}
