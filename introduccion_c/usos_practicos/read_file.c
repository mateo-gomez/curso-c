#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char c;

	while ((c = fgetc(file)) != EOF)
	{
		printf("%c", c);
	}

	fclose(file);

	return 0;
}
