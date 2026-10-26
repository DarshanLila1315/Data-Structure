
#include <stdio.h>

int iterativeBinarySearch(const int a[], int n, int key)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (a[mid] == key)
			return mid;
		if (a[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

int recursiveBinarySearch(const int a[], int low, int high, int key)
{
	if (low > high)
		return -1;

	int mid = low + (high - low) / 2;

	if (a[mid] == key)
		return mid;
	if (a[mid] < key)
		return recursiveBinarySearch(a, mid + 1, high, key);

	return recursiveBinarySearch(a, low, mid - 1, key);
}

int main(void)
{
	int a[100], n, key, i;
	int iterativeResult, recursiveResult;

	printf("Enter number of elements (in sorted order): ");
	scanf("%d", &n);

	if (n < 1 || n > 100)
	{
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements in ascending order:\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter element to search: ");
	scanf("%d", &key);

	iterativeResult = iterativeBinarySearch(a, n, key);
	recursiveResult = recursiveBinarySearch(a, 0, n - 1, key);

	if (iterativeResult != -1)
		printf("Iterative search: Element found at position %d.\n", iterativeResult + 1);
	else
		printf("Iterative search: Element not found.\n");

	if (recursiveResult != -1)
		printf("Recursive search: Element found at position %d.\n", recursiveResult + 1);
	else
		printf("Recursive search: Element not found.\n");

	return 0;
}



