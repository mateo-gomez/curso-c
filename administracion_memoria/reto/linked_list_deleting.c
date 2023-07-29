#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int number;
	struct Node *next;
} NODE;

int main(int argc, const char *argv[])
{
	NODE *createNode(int number);
	void showLinkedList(NODE * linkedList);
	NODE *deleteNode(NODE * startNode);
	void freeList(NODE * startNode);

	NODE *start = NULL,
		 *currentNode = NULL, *next;
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

	showLinkedList(start);
	start = deleteNode(start);
	showLinkedList(start);

	freeList(start);

	return 0;
}

NODE *createNode(int number)
{
	NODE *newNode;
	newNode = malloc(sizeof(NODE));
	newNode->number = number;
	newNode->next = NULL;

	return newNode;
}

void showLinkedList(NODE *linkedList)
{
	NODE *currentNode = linkedList;

	printf("Numeros ingresados\n");
	while (currentNode)
	{
		printf("%d %c", currentNode->number, currentNode->next ? ',' : '\n');

		currentNode = currentNode->next;
	}
}

NODE *deleteNode(NODE *startNode)
{
	printf("Reference: %p\n", &startNode);
	NODE *currentNode = startNode;
	printf("Reference: %p\n", &startNode);
	NODE *prev;
	int node_number;
	int i = 1;

	printf("Ingresa la posición de la lista a eliminar\n");
	scanf("%d", &node_number);

	while (currentNode)
	{
		if (node_number == 1)
		{
			if (currentNode->next)
			{
				free(startNode);
				startNode = currentNode->next;
				currentNode = startNode;
				printf("entra\n");
				break;
			}
			else
			{
				printf("No es posible eliminar.\n");
			}
		}

		if (i == node_number - 1)
		{
			prev = currentNode;
		}

		if (node_number != 0 && i == node_number)
		{
			if (currentNode->next)
			{
				prev->next = currentNode->next;
			}
			else
			{
				prev->next = NULL;
			}

			free(currentNode);
		}

		currentNode = currentNode->next;
		i++;
	}

	if (node_number > i)
	{
		printf("El nodo a eliminar no existe,  el número de nodo máximo es %d\n", i - 1);
	}

	return startNode;
}

void freeList(NODE *linkedList)
{
	NODE *next, *currentNode = linkedList;

	while (currentNode)
	{
		next = currentNode->next;
		free(currentNode);
		currentNode = next;
	}
}