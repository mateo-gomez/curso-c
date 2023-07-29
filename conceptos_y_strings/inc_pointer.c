#include "stdio.h"

int main()
{
	int number = 5;
	int *pointerInteger = &number;
	char character = 'a';
	char *pointerCharacter = &character;

	printf("Antes integer %p, chararacter %p\n", pointerInteger, pointerCharacter);
	pointerInteger++;
	pointerCharacter++;
	printf("Desupés integer %p, chararacter %p\n", pointerInteger, pointerCharacter);
}