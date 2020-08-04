#include <stdio.h>
#include <stdlib.h>


void pprint(int arr[], int n)
{
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int max(int arr[], int n)
{

	int i, max_ = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max_)
			max_ = arr[i];
	}

	return max_;
}

void random_array(int n)
{
	int *random_array_ = (int*)malloc(sizeof(int) * n);
	int i;
	
	for (i = 0; i < n; i++)
	{
		random_array_[i] = rand();
	}
}

void merge(int arr[], int l, int m, int r, int *sw_counter, int *eq_counter)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L, *R;
	L = (int*)malloc(sizeof(int) * n1);
	R = (int*)malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
		*sw_counter += 1;
	}

	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
		*sw_counter += 1;
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{	
		*eq_counter += 1;
		if (L[i] <= R[j])
		{
			*eq_counter += 1;
			arr[k] = L[i];
			*sw_counter += 1;
			i++;
		}
		else
		{
			arr[k] = R[j];
			*sw_counter += 1;
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);

}


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


int partition(int arr[], int low, int high, int *sw_counter, int *eq_counter)
{
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] <= pivot)
		{
			*sw_counter += 1;
			*eq_counter += 1;
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	*sw_counter += 1;
	return (i + 1);
}

int linear_search(int arr[], int n, int element, int *sw_counter, int *eq_counter)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		*eq_counter += 1;
		*sw_counter = 0;
		if (arr[i] == element)
			return i;
	}

	return -1;
}

int binarySearch(int arr[], int left, int right, int element, int *sw_counter, int *eq_counter)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		
		*eq_counter += 1;
		if (arr[mid] == element)
			return mid;
		*eq_counter += 1;
		if (arr[mid] < element)
			left = mid + 1;
		else
			right = mid - 1;
		*sw_counter = 0;
	}

	return -1;
}
