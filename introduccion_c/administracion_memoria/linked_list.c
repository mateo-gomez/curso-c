#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int number;
	struct Node *next;
} NODE;

NODE *createNode(int number)
{
	NODE *newNode;
	newNode = malloc(sizeof(NODE));
	newNode->number = number;
	newNode->next = NULL;

	return newNode;
}

int main(int argc, const char *argv[])
{
	NODE *start = NULL, *currentNode = NULL, *next;
	int number;
	int goOn, listSize = 0;

	do
	{
		printf("Tamaño de la list %d, ingrese un número (0 para terminar)\n", listSize);
		scanf("%d", &number);

		if (number)
		{
			if (!start)
			{
				start = createNode(number);
				listSize++;
			}
			else
			{
				currentNode = start;
				while (currentNode->next)
				{
					currentNode = currentNode->next;
				}
				currentNode->next = createNode(number);
				listSize++;
			}
			goOn = 1;
		}
		else
		{
			goOn = 0;
		}
	} while (goOn);

	currentNode = start;
	while (currentNode)
	{
		printf("%d %c", currentNode->number, currentNode->next ? ',' : '\n');

		currentNode = currentNode->next;
	}

	currentNode = start;
	while (currentNode)
	{
		next = currentNode->next;
		free(currentNode);
		currentNode = next;
	}

	return 0;
}