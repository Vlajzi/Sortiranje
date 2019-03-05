#include "HeapSort.h"

void HeapSort::heapify(int* a, int n, int i)
{
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left < n && a[left] > a[largest])
	{
		largest = left;
	}

	if (right < n && a[right] > a[largest])
	{
		largest = left;
	}

}
