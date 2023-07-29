#include <stdio.h>
#include <time.h>

void insertSort(int arreglo[], int n)
{
	int j, currentValue;
	for (int i = 0; i < n - 1; i++)
	{
		currentValue = arreglo[i];
		j = i - 1;

		while (j >= 0 && arreglo[j] > currentValue)
		{
			arreglo[j + 1] = arreglo[j];
			j = j - 1;
		}
		arreglo[j + 1] = currentValue;
	}
}

void imprimir(int arreglo[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", arreglo[i], n - 1 == i ? '\n' : ',');
	}
}

int main(int argc, char const *argv[])
{
	int tiempo_final, tiempo_inicio;
	double segundos;
	int arreglo[] = {3, 94, 86, 82, 90, 10, 87, 36, 61, 8, 17, 15, 22, 10, 23, 78, 25, 2, 30, 45, 98, 43, 98, 59, 53, 57, 2, 64, 1, 41, 32, 58, 19, 99, 60, 74, 48, 80, 44, 25, 68, 1, 89, 77, 60, 25, 99, 30, 76, 32, 57, 82, 52, 44, 72, 87, 34, 87, 65, 30, 54, 6, 31, 33, 44, 44, 42, 82, 90, 17, 9, 98, 28, 86, 69, 3, 17, 8, 45, 98, 12, 47, 95, 43, 72, 39, 41, 82, 74, 56, 65, 79, 50, 26, 67, 100, 24, 67, 38, 57};
	int n = sizeof(arreglo) / sizeof(arreglo[0]);

	tiempo_inicio = clock();

	insertSort(arreglo, n);
	imprimir(arreglo, n);

	tiempo_final = clock();
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("Insert sort: %f\n", segundos);

	return 0;
}
