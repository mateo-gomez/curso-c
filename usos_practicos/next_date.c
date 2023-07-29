#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	time_t oneDay = 24 * 60 * 60,
		   today = time(NULL),
		   nextDate;

	int cantidadDay = atoi(argv[1]);

	nextDate = today + oneDay * cantidadDay;

	printf("La fecha dentro de %d días es: %s \n", cantidadDay, ctime(&nextDate));

	return 0;
}
