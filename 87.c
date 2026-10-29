// WAP to implement Selection Sort using Array.

#include <stdio.h>

int main(void)
{
	int array[100], n, i, j, minIndex, temp;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}

		temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}

	printf("Sorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

