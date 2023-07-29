#include "stdio.h"

int main()
{
	char *name = "Luji";
	int i;

	for (i = 0; i < 4; i++)
	{
		printf("name[%d](%p) = %c\n", i, name + i, *(name + i)); // *(name + i) es lo mismo que name[i]
	}
}