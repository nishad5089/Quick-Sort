#include <iostream>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int p, int r)
{
	int pivot = arr[r]; // pivot
	int i = (p - 1); // Index of smaller element

	for (int j = p; j <= r - 1; j++)
	{
	
		if (arr[j] <= pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

/*
   
	arr[] --> Array to be sorted,
	P --> Starting index,
	r --> Ending index 
*/
void quickSort(int arr[], int P, int r)
{
	if (P < r)
	{	
		int pi = partition(arr, P, r);
		quickSort(arr, P, pi - 1);
		quickSort(arr, pi + 1, r);
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = ARRAY_SIZE(arr);
	
	quickSort(arr, 0, n - 1);
	
	std::cout << "Sorted array : ";
	int i;
	for (i = 0; i < n; i++)
		std::cout << arr[i];
	std::cout << std::endl;
	
	getchar();
	return 0;
}