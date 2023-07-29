//Divide : Divide the n-element array into two n/2-element subarrays.
//Conquer : Sort the two subarrays recursively using merge sort
//Combine : Merge the two sorted subsequences to form the sorted array

#include <stdio.h>
#include <time.h>

int arr[20]; // array to be sorted

int merge(int arr[], int l, int m, int h)
{
	int arr1[100], arr2[100]; // Two temporary arrays to
							//hold the two arrays to be merged
	int n1, n2, i, j, k;
	n1 = m - l + 1;
	n2 = h - m;

	for (i = 0; i < n1; i++)
		arr1[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		arr2[j] = arr[m + j + 1];

	arr1[i] = 9999; // To mark the end of each temporary array
	arr2[j] = 9999;

	i = 0;
	j = 0;
	for (k = l; k <= h; k++) //process of combining two sorted arrays
	{
		if (arr1[i] <= arr2[j])
			arr[k] = arr1[i++];
		else
			arr[k] = arr2[j++];
	}

	return 0;
}

int mergeSort(int arr[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Divide and Conquer
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		// Combine
		merge(arr, low, mid, high);
	}

	return 0;
}

void imprimir(int arreglo[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", arreglo[i], n - 1 == i ? '\n' : ',');
	}
}


int main()
{
	int tiempo_final, tiempo_inicio;
	double segundos;
	int arreglo[] = {3, 94, 86, 82, 90, 10, 87, 36, 61, 8, 17, 15, 22, 10, 23, 78, 25, 2, 30, 45, 98, 43, 98, 59, 53, 57, 2, 64, 1, 41, 32, 58, 19, 99, 60, 74, 48, 80, 44, 25, 68, 1, 89, 77, 60, 25, 99, 30, 76, 32, 57, 82, 52, 44, 72, 87, 34, 87, 65, 30, 54, 6, 31, 33, 44, 44, 42, 82, 90, 17, 9, 98, 28, 86, 69, 3, 17, 8, 45, 98, 12, 47, 95, 43, 72, 39, 41, 82, 74, 56, 65, 79, 50, 26, 67, 100, 24, 67, 38, 57};
	int n = sizeof(arreglo) / sizeof(arreglo[0]);

	tiempo_inicio = clock();

	mergeSort(arreglo, 0, n);
	imprimir(arreglo, n);

	tiempo_final = clock();
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("Insert sort: %f\n", segundos);

	return 0;
}