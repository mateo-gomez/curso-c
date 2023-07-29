#include <stdio.h> // se usa entre mayor y menor si la librería es standar
#include "mylib.h" // se usa entre comillas si la librería es creada

int main(int argc, const char *argv[])
{
	hello(argv[1]);

	return 0;
}