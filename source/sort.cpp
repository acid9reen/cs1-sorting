#include <stdlib.h>
#include "usefull_funcs.hpp"


void bubble_sort(int arr[], int n, int *sw, int *eq)
{
	int i, j;

	for ( i = 0; i < n; i++)
	{
		*eq += 1;
		for ( j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				*sw += 1;
			}
		}
	}
}


void selection_sort(int arr[], int n, int *sw_counter, int *eq_counter)
{
	int i, j, min_idx;
	
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for ( j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
				*eq_counter += 1;
			}
		}
		swap(&arr[min_idx], &arr[i]);
		*sw_counter += 1;
	}
}


void insertion_sort(int arr[], int n, int *sw_counter, int *eq_counter)
{
	int i, key, j;

	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			*sw_counter += 1;
			*eq_counter += 1;
		}
		arr[j + 1] = key;
	}
}


void counting_sort(int arr[], int n, int *sw_counter, int *eq_counter)
{
	int i, j, *count, max_ = max(arr, n) + 1;
	count = (int*)malloc(sizeof(int) * max_);

	*sw_counter = 0;
	*eq_counter = 0;

	for (i = 0; i < max_; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}

	int k = 0;

	for (i = 0; i < max_; i++)
	{
		for (j = 0; j < count[i]; j++)
		{
			arr[k] = i;
			k++;
		}
	}
}


void merge_sort(int arr[], int l, int r, int *sw_counter, int *eq_counter)
{
	if (l < r)
	{ 
		int m = l + (r - l) / 2;

		merge_sort(arr, l, m, eq_counter, sw_counter);
		merge_sort(arr, m + 1, r, eq_counter, sw_counter);

		merge(arr, l, m, r, sw_counter, eq_counter);
	}
}


void quick_sort(int arr[], int low, int high, int *sw_counter, int *eq_counter)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, sw_counter, eq_counter);

		quick_sort(arr, low, pi - 1, sw_counter, eq_counter);
		quick_sort(arr, pi + 1, high, sw_counter, eq_counter);
	}
}
