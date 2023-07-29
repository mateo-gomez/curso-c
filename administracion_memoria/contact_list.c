#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char NAME[100];
typedef char EMAIL[100];

typedef struct
{
	NAME name;
	EMAIL email;
} CONTACT;

int main(int argc, char *argv[])
{
	CONTACT *list = NULL;
	char buffer[100];
	char goOn, listSize = 0;

	do
	{

		printf("Ingrese el nombre del contacto (0 para terminar)\n");
		scanf("%99s", buffer);

		if (strcmp("0", buffer) != 0)
		{
			if (!list)
			{
				list = malloc(sizeof list);
			}
			else
			{
				list = realloc(list, sizeof list * listSize + 1);
			}
			strcpy(list[listSize].name, buffer);

			printf("Ingrese el email\n");
			scanf("%99s", buffer);

			strcpy(list[listSize].email, buffer);

			listSize++;
			goOn = 1;
		}
		else
		{
			goOn = 0;
		}

	} while (goOn);

	printf("Nombre\t\tEmail\n");

	for (int i = 0; i < listSize; i++)
	{
		printf("%s\t\t%s\n", list[i].name, list[i].email);
	}

	free(list);

	return 0;
}