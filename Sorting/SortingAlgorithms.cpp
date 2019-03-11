#include "SortingAlgorithms.h"
#include <stdlib.h>
#include <vector>
#include <algorithm> 


using namespace std;

namespace Algoritmi
{

	void swap(int* a, int* b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}


	void SelectionSort(int* a, int n)
	{
		int i, j, max_id;


		for (i = 0; i < n; i++)
		{
			max_id = i;
			for (j = i + 1; j < n; j++)
			{
				if (a[j] > a[max_id])
				{
					max_id = j;
				}
			}
			swap((a + max_id), (a + i));
		}
	}


	void InsercionSort(int* a, int n)
	{
		int i = 1;

		while (i < n)
		{
			int j = i;

			while (j > 0 && a[j - 1] < a[j])
			{
				swap((a + j), (a + j - 1));

				j--;
			}

			i++;
		}
	}

	void BubbleSort(int* a, int n)
	{
		bool swapt = true;
		while (swapt)
		{
			swapt = false;
			for (int i = 1; i < n; i++)
			{
				if (a[i - 1] < a[i])
				{
					swap((a + i), (a + i - 1));
					swapt = true;
				}
			}
			n--;
		}
	}

	void quickSort(int* a, int lo, int hi);
	int partition(int* a, int lo, int hi);

	void QuickSort(int* a, int n)
	{
		quickSort(a, 0, n-1);
	}

	void quickSort(int* a, int lo, int hi)
	{
		if (lo < hi)
		{
			int  i = partition(a, lo, hi);
			quickSort(a, lo, i - 1);
			quickSort(a, i + 1, hi);
		}
	}

	int partition(int* a,int lo,int hi)
	{
		int mid = (hi - lo) / 2;
		if (a[mid] < a[lo])
		{
			swap((a + mid), (a + hi));
		}
		if (a[hi] < a[lo])
		{
			swap((a + hi), (a + lo));
		}
		if (a[mid] < a[hi])
		{
			swap((a + mid), (a + hi));
		}

		int pivot = a[hi];
		int i = lo;
		for (int j = lo; j < hi; j++)
		{
			if (a[j] >= pivot)
			{
				
				swap((a + i), (a + j));
				i++;
			}
			
		}
		swap((a + i), (a + hi));
		return i;
	}

	void heapify(int* a, int n, int i)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && a[left] < a[largest])
		{
			largest = left;
		}

		if (right < n && a[right] < a[largest])
		{
			largest = right;
		}

		if (largest != i)
		{
			swap((a + i), (a + largest));

			heapify(a, n, largest);
		}
	}


	void HeapSort(int* a, int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(a, n, i);
		}

		for (int i = n - 1; i >= 0; i--)
		{

			swap(a, (a+i));

			n--;

			heapify(a, n, 0);
		}
	}

	int MaxElement(int* a,int n)
	{
		int min = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] > min)
			{
				min = a[i];
			}
		}
		return min;
	}

	void Copy(int* a, int* b, int n)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}
	}


	void CountingSort(int* a,int n)
	{
		int max = MaxElement(a, n);

		int* c = (int*)calloc(max+1, sizeof(int));

		int* b = (int*)calloc(n , sizeof(int));
		
		for (int i = 0; i < n; i++)
		{
			c[a[i]]++;
		}

		for (int i = 1; i < max+1; i++)
		{
			c[i] += c[i - 1];
		}

		for (int i = n - 1; i >= 0; i--)
		{
			b[c[a[i]]-1] = a[i];
			c[a[i]]--;
		}

		Copy(a, b, n);

		free(b);
		free(c);
	}

	void BucketSort(int* a, int n)
	{
		int k = n/100;
		
		int div = 100;//n / k;

		int** b = (int**)calloc(k,sizeof(int*));

		for (int i = 0; i < k; i++)
		{
			b[i] = (int*)calloc(n, sizeof(int));
		}

		int* poz = (int*)calloc(k, sizeof(int));

		for (int i = 0; i < n; i++)
		{
			b[a[i] / div][poz[a[i]/div]++] = a[i];
		}

		for (int i = 0; i < k; i++)
		{
			//InsercionSort(b[i],poz[i]);
			HeapSort(b[i],poz[i]);

		}

		int index = 0;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < poz[i]; j++)
				a[index++] = b[i][j];


		
	}

}

